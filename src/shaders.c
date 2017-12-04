#include <stdio.h>
#include "shaders.h"
#include "math.h"

vector_t simple_shader(shader_data_t data, material_t * mat) {
	vector_t LIGHT = vec_norm(make_vector(0, 0, 1, 0));
	vector_t N = data.norm;
	vector_t T = data.tan;
	vector_t B = vec_scale(vec_cross(N, T), T.w);
	vector_t sample = mat->diffuse;

	// if we have a bump map, use it to modify the surface normal
	if (mat->bump.data) {
		// transform light into tangent space
		LIGHT = make_vector(vec_dot(T, LIGHT), vec_dot(B, LIGHT), vec_dot(N, LIGHT), 0);
		
		vector_t bump = sample_nearest(mat->bump, data.tex_coord.x, data.tex_coord.y);
		bump = vec_add(vec_scale(bump, 2.0), VECTOR_ONE);
		N = vec_norm(bump);
	}

	// if we have a texture, use it, otherwise use the specified diffuse value
	if (mat->tex.data) {
		sample = sample_linear(mat->tex, data.tex_coord.x, data.tex_coord.y);
	}

	float diffuse = MAX(vec_dot(LIGHT, N), 0.0);
	return vec_scale(sample, diffuse);
}
