#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "img.h"
#include "draw.h"

void draw_clear(color_t c, uint8_t * buffer, point_t buffer_size) {
	for (int y=0; y<buffer_size.y; y++) {
		for (int x=0; x<buffer_size.x; x++) {
			draw_point(make_point(x,y), c, buffer, buffer_size);
		}
	}
}

void draw_point(point_t coords, color_t c, uint8_t * buffer, point_t buffer_size) {
	if (coords.x >= buffer_size.x || coords.y >= buffer_size.y) {
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

void draw_triangle(point_t p[3], color_t c, uint8_t * buffer, point_t buffer_size) {
	draw_line(p[0], p[1], c, buffer, buffer_size);
	draw_line(p[1], p[2], c, buffer, buffer_size);
	draw_line(p[2], p[0], c, buffer, buffer_size);
}
