#include <stdio.h>
#include "shaders.h"
#include "math.h"

image_t s_tex[MAX_TEXTURES];

vector_t simple_shader(shader_data_t data) {
	vector_t L = make_vector(0, 0, 1, 0);
	float s = MAX(vec_dot(L, data.norm), 0.25);
	vector_t sample = sample_nearest(s_tex[0], data.tex_coord.x, data.tex_coord.y);

	return sample;
}
