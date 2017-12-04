#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"
#include "math.h"
#include "draw.h"

void draw_clear(color_t c, uint8_t * buffer, point_t buffer_size) {
	for (int y=0; y<buffer_size.y; y++) {
		for (int x=0; x<buffer_size.x; x++) {
			draw_point(make_point(x,y), c, buffer, buffer_size);
		}
	}
}

void draw_point(point_t coords, color_t c, uint8_t * buffer, point_t buffer_size) {
	if (coords.x >= buffer_size.x || coords.y >= buffer_size.y ||
			coords.x < 0 || coords.y < 0) {
		// out of bounds - silently fail
		return;
	}

	int base = CHANNELS * (coords.y * buffer_size.x + coords.x);
	buffer[base + 0] = c.r;
	buffer[base + 1] = c.g;
	buffer[base + 2] = c.b;
}

void draw_line(point_t start, point_t end, color_t c, uint8_t * buffer, point_t buffer_size) {
	bool steep = false;
	if (abs(start.x - end.x) < abs(start.y - end.y)) {
		// line is steep, we need to transpose the image
		start = make_point(start.y, start.x);
		end = make_point(end.y, end.x);
		steep = true;
	}

	if (start.x > end.x) {
		// make sure we are rendering from left-right
		point_t tmp = start;
		start = end;
		end = tmp;
	}

	// for each x component, find a good corresponding y component to render at
	for (int x=start.x; x<=end.x; x++) {
		float t = (x - start.x) / (float)(end.x - start.x);
		int y = start.y * (1.0 - t) + end.y * t;

		draw_point(steep ? make_point(y, x) : make_point(x, y), c, buffer, buffer_size);
	}
}

void draw_triangle_frame(point_t t[3], color_t c, uint8_t * buffer, point_t buffer_size) {
	draw_line(t[0], t[1], c, buffer, buffer_size);
	draw_line(t[1], t[2], c, buffer, buffer_size);
	draw_line(t[2], t[0], c, buffer, buffer_size);
}

void draw_triangle(model_t * m, unsigned idx, 
		vector_t (*shader)(shader_data_t data, material_t * mat),
		material_t * material,
		uint8_t * buffer, float * back, point_t buffer_size) {
	// get all relavent data out of the model
	vector_t * vertices = &m->vertices[3*idx];
	vector_t * tex_coords = &m->tex_coords[3*idx];
	vector_t * norms = &m->norms[3*idx];
	vector_t * tans = &m->tangents[3*idx];

	// get the bounding box, clamped to screen coordinates
	bbox_t screen_box = (bbox_t){{0, 0},buffer_size};
	bbox_t bbox = find_bbox(vertices, 3);
	bbox = intersect_bbox(bbox, screen_box);

	for (int y = bbox.min.y; y <= bbox.max.y; y++) {
		for (int x = bbox.min.x; x <= bbox.max.x; x++) {
			vector_t pos = make_vector(x, y, 0, 0);

			if (is_point_in_triangle(pos, vertices)) {
				// compute bary centric coordinates, we will need this for our depth test
				vector_t bc_screen = bary_centric(make_vector(x,y, 0.0, 0.0), vertices);
				if (bc_screen.x < 0 || bc_screen.y < 0 || bc_screen.z < 0) { continue; }
				pos.z = (vertices[0].z * bc_screen.x) + 
					(vertices[1].z * bc_screen.y) + (vertices[2].z * bc_screen.z);

				#pragma omp critical
				{
					if (back[y*buffer_size.x + x] > pos.z) {
						back[y*buffer_size.x + x] = pos.z;

						// interpolate vertex data
						vector_t tex_coord = interpolate(tex_coords, bc_screen);
						vector_t norm = interpolate(norms, bc_screen);
						vector_t tan = interpolate(tans, bc_screen);

						vector_t c = shader((shader_data_t){pos, tex_coord, norm, tan}, material);
						draw_point(vector_to_point(pos), vector_to_color(c), buffer, buffer_size);
					}
				}
			}
		}
	}
}

