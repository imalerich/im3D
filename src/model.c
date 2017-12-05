#include <stdlib.h>
#include <stdio.h>

#include "model.h"
#include "io.h"

model_group_t obj_load(const char * filename) {
	// first, load all materials used by our models
	material_group_t materials = obj_load_materials(filename);

	FILE * fp = fopen(filename, "r");
	char line[1000];

	// allocate empty buffers.
	size_t v_count = 0, v_buffer_size = 8;
	vector_t * v_buffer = malloc(sizeof(vector_t) * v_buffer_size);

	size_t t_count = 0, t_buffer_size = 8;
	vector_t * t_buffer = malloc(sizeof(vector_t) * t_buffer_size);

	size_t n_count = 0, n_buffer_size = 8;
	vector_t * n_buffer = malloc(sizeof(vector_t) * n_buffer_size);

	size_t f_count = 0, f_buffer_size = 8;
	obj_face_t * f_buffer = malloc(sizeof(obj_face_t) * f_buffer_size);

	// objects grouped by material, allocate a buffer indicating
	// the end of each model
	size_t model_count = 0, model_buffer_size = 8;
	unsigned * model_buffer = malloc(sizeof(unsigned) * model_buffer_size);

	// read each line from the file
	// comment lines or unsupported directives are ignored
	while (fgets(line, sizeof(line), fp) != NULL) {
		strip_comments(line);

		// read any relavent data that we find
		
		if (is_vertex(line)) {
			v_buffer[v_count++] = get_vector(line, 1);

		} else if (is_texture_coord(line)) {
			t_buffer[t_count++] = get_texture_coord(line);

		} else if (is_vertex_norm(line)) {
			n_buffer[n_count++] = get_vector(line, 2);

		} else if (is_face(line)) {
			f_buffer[f_count++] = get_face(line);

		} else if (is_object_start(line) && v_count > 0) {
			model_buffer[model_count++] = f_count;

		}
		
		// line has been read, check if we need
		// to reallocate any of our buffers

		if (v_count == v_buffer_size) {
			v_buffer_size *= 2;
			v_buffer = realloc(v_buffer, sizeof(vector_t) * v_buffer_size);
		}

		if (t_count == t_buffer_size) {
			t_buffer_size *= 2;
			t_buffer = realloc(t_buffer, sizeof(vector_t) * t_buffer_size);
		}

		if (n_count == n_buffer_size) {
			n_buffer_size *= 2;
			n_buffer = realloc(n_buffer, sizeof(vector_t) * n_buffer_size);
		}

		if (f_count == f_buffer_size) {
			f_buffer_size *= 2;
			f_buffer = realloc(f_buffer, sizeof(obj_face_t) * f_buffer_size);
		}

		if (model_count == model_buffer_size) {
			model_buffer_size *= 2;
			model_buffer = realloc(model_buffer, sizeof(unsigned) * model_buffer_size);
		}
	}

	model_buffer[model_count++] = f_count;
	model_group_t ret = (model_group_t){
		model_count,
		malloc(sizeof(model_t) * model_count),
		0, NULL
	};

	unsigned face_base = 0;
	for (int i=0; i<model_count; i++) {
		// create a new model, we need to allocate new buffers in this model
		// but they don't need to be dynamic as we already know how many faces we have
		unsigned face_count = model_buffer[i] - face_base;

		size_t num_vertices = face_count * 3;
		model_t m = (model_t){
			num_vertices, 
			malloc(sizeof(vector_t) * num_vertices), 
			malloc(sizeof(vector_t) * num_vertices), 
			malloc(sizeof(vector_t) * num_vertices), 
			malloc(sizeof(vector_t) * num_vertices),
			0
		};

		int idx = 0;
		for (int k=face_base; k<(face_base + face_count); k++) {
			// get the current face, we will need to add 3 vertices/normals/coords for each
			obj_face_t face = f_buffer[k];

			// copy data from the loaded buffers into the new model

			// VERTEX A
			m.vertices[idx] = v_buffer[face.a.v];
			m.tex_coords[idx] = t_buffer[face.a.t];
			m.norms[idx] = n_buffer[face.a.n];
			m.tangents[idx] = VECTOR_ZERO;
			idx++;

			// VERTEX B
			m.vertices[idx] = v_buffer[face.b.v];
			m.tex_coords[idx] = t_buffer[face.b.t];
			m.norms[idx] = n_buffer[face.b.n];
			m.tangents[idx] = VECTOR_ZERO;
			idx++;

			// VERTEX C
			m.vertices[idx] = v_buffer[face.c.v];
			m.tex_coords[idx] = t_buffer[face.c.t];
			m.norms[idx] = n_buffer[face.c.n];
			m.tangents[idx] = VECTOR_ZERO;
			idx++;
		}

		face_base = model_buffer[i];
		compute_model_tangents(&m);
		ret.models[i] = m;
	}

	// rewind to the start of the file for reading material names
	rewind(fp);
	unsigned idx = 0;
	while (fgets(line, sizeof(line), fp) != NULL && idx < model_count ) {
		strip_comments(line);
		char * mtl = read_string("usemtl", line);
		if (mtl) { 
			ret.models[idx++].material = find_material(materials, mtl); 
			free(mtl); mtl = NULL;
		}
	}

	// free all our buffers, close the file, and return results
	free(model_buffer);
	free(v_buffer);
	free(t_buffer);
	free(n_buffer);
	free(f_buffer);
	fclose(fp);
	return ret;
}

void compute_model_tangents(model_t * m) {
	// "Mathematics for 3D Game Programming and Computer Graphics"
	// p. 184-185 (c) 2012 Eric Lengyel
	
	vector_t * tan1 = malloc(sizeof(vector_t) * m->vert_count * 2);
	vector_t * tan2 = tan1 + m->vert_count;
	memset(tan1, 0, sizeof(vector_t) * m->vert_count * 2);

	for (size_t i=0; i<num_faces(*m); i++) {
		int idx = i*3;

		float x1 = m->vertices[idx + 1].x - m->vertices[idx + 0].x;
		float x2 = m->vertices[idx + 2].x - m->vertices[idx + 0].x;
		float y1 = m->vertices[idx + 1].y - m->vertices[idx + 0].y;
		float y2 = m->vertices[idx + 2].y - m->vertices[idx + 0].y;
		float z1 = m->vertices[idx + 1].z - m->vertices[idx + 0].z;
		float z2 = m->vertices[idx + 2].z - m->vertices[idx + 0].z;

		float s1 = m->tex_coords[idx + 1].x - m->tex_coords[idx + 0].x;
		float s2 = m->tex_coords[idx + 2].x - m->tex_coords[idx + 0].x;
		float t1 = m->tex_coords[idx + 1].y - m->tex_coords[idx + 0].y;
		float t2 = m->tex_coords[idx + 2].y - m->tex_coords[idx + 0].y;

		float r = 1.0f / (s1 * t2 - s2 * t1);
		vector_t sdir = make_vector((t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r, 
			(t2 * z1 - t1 * z2) * r, 0.0);
		vector_t tdir = make_vector((s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r,
			(s1 * z2 - s2 * z1) * r, 0.0);

		tan1[idx + 0] = vec_add(tan1[idx + 0], sdir);
		tan1[idx + 1] = vec_add(tan1[idx + 1], sdir);
		tan1[idx + 2] = vec_add(tan1[idx + 2], sdir);

		tan2[idx + 0] = vec_add(tan1[idx + 0], tdir);
		tan2[idx + 1] = vec_add(tan1[idx + 1], tdir);
		tan2[idx + 2] = vec_add(tan1[idx + 2], tdir);
	}

	for (size_t a=0; a < m->vert_count; a++) {
		const vector_t n = m->norms[a];
		const vector_t t = tan1[a];
		const vector_t tmp = vec_scale(n, -vec_dot(n, t));

		// Gram-Schmidt orthogonalize
		m->tangents[a] = vec_norm(vec_add(t, tmp));

		// calculate handedness
		m->tangents[a].w = (vec_dot(vec_cross(n, t), tan2[a]) < 0.0f ? -1.0f : 1.0f);
	}

	free(tan1);
}

void model_free(model_t * m) {
	free(m->vertices);
	free(m->tex_coords);
	free(m->norms);
	free(m->tangents);
	material_free(m->material);

	m->material = NULL;
	m->material = NULL;
	m->vertices = NULL;
	m->tex_coords = NULL;
	m->tangents = NULL;
	m->norms = NULL;
}

void model_group_free(model_group_t * m) {
	for (unsigned i=0; i<m->model_count; i++) {
		model_free(&m->models[i]);
	}

	for (unsigned i=0; i<m->texture_count; i++) {
		free_img(&m->textures[i]);
	}
	
	free(m->models);
	free(m->textures);
	m->models = NULL;
	m->textures = NULL;
}

void model_print(model_t m) {
	for (int i=0; i<m.vert_count; i++) {
		printf("[");
		print_vector(m.vertices[i]);
		printf("\t");
		print_vector(m.tex_coords[i]);
		printf("\t");
		print_vector(m.norms[i]);
		printf("]\n");
	}
}
