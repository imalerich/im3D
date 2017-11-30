#include <stdlib.h>
#include <stdio.h>

#include "model.h"
#include "io.h"

model_t obj_load(const char * filename) {
	FILE * fp = fopen(filename, "r");
	char line[1000];

	// allocate empty buffers.
	size_t v_count = 0, v_buffer_size = 8;
	vector_t * v_buffer = malloc(sizeof(vector_t) * v_buffer_size);

	size_t t_count = 0, t_buffer_size = 8;
	coord_t * t_buffer = malloc(sizeof(coord_t) * t_buffer_size);

	size_t n_count = 0, n_buffer_size = 8;
	vector_t * n_buffer = malloc(sizeof(vector_t) * n_buffer_size);

	size_t f_count = 0, f_buffer_size = 8;
	obj_face_t * f_buffer = malloc(sizeof(obj_face_t) * f_buffer_size);

	// read each line from the file
	// comment lines or unsupported directives are ignored
	while (fgets(line, sizeof(line), fp) != NULL) {

		// read any relavent data that we find
		
		if (is_vertex(line)) {
			v_buffer[v_count++] = get_vertex(line);

		} else if (is_texture_coord(line)) {
			t_buffer[t_count++] = get_texture_coord(line);

		} else if (is_vertex_norm(line)) {
			n_buffer[n_count++] = get_vertex_norm(line);

		} else if (is_face(line)) {
			f_buffer[f_count++] = get_face(line);
		}
		
		// line has been read, check if we need
		// to reallocate any of our buffers

		if (v_count == v_buffer_size) {
			v_buffer_size *= 2;
			v_buffer = realloc(v_buffer, sizeof(vector_t) * v_buffer_size);
		}

		if (t_count == t_buffer_size) {
			t_buffer_size *= 2;
			t_buffer = realloc(t_buffer, sizeof(coord_t) * t_buffer_size);
		}

		if (n_count == n_buffer_size) {
			n_buffer_size *= 2;
			n_buffer = realloc(n_buffer, sizeof(vector_t) * n_buffer_size);
		}

		if (f_count == f_buffer_size) {
			f_buffer_size *= 2;
			f_buffer = realloc(f_buffer, sizeof(obj_face_t) * f_buffer_size);
		}
	}

	// create a new model, we need to allocate new buffers in this model
	// but they don't need to be dynamic as we already know how many faces we have
	size_t num_vertices = f_count * 3;
	model_t m = (model_t){
		num_vertices, 
		malloc(sizeof(vector_t) * num_vertices), 
		malloc(sizeof(coord_t) * num_vertices), 
		malloc(sizeof(vector_t) * num_vertices)
	};

	int idx = 0;
	for (int k=0; k<f_count; k++) {
		// get the current face, we will need to add 3 vertices/normals/coords for each
		obj_face_t face = f_buffer[k];

		// copy data from the loaded buffers into the new model

		// FACE A
		m.vertices[idx] = v_buffer[face.a.v];
		m.tex_coords[idx] = t_buffer[face.a.t];
		m.norms[idx] = n_buffer[face.a.n];
		idx++;

		// FACE B
		m.vertices[idx] = v_buffer[face.b.v];
		m.tex_coords[idx] = t_buffer[face.b.t];
		m.norms[idx] = n_buffer[face.b.n];
		idx++;

		// FACE C
		m.vertices[idx] = v_buffer[face.c.v];
		m.tex_coords[idx] = t_buffer[face.c.t];
		m.norms[idx] = n_buffer[face.c.n];
		idx++;
	}

	// free all our buffers, close the file, and return results
	free(v_buffer);
	free(t_buffer);
	free(n_buffer);
	free(f_buffer);
	fclose(fp);
	return m;
}

void model_free(model_t m) {
	free(m.vertices);
	free(m.tex_coords);
	free(m.norms);

	m.vertices = NULL;
	m.tex_coords = NULL;
	m.norms = NULL;
}

void model_print(model_t m) {
	for (int i=0; i<m.vert_count; i++) {
		printf("[");
		print_vector(m.vertices[i]);
		printf("\t");
		print_coord(m.tex_coords[i]);
		printf("\t");
		print_vector(m.norms[i]);
		printf("]\n");
	}
}
