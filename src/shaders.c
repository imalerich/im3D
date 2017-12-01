#include "shaders.h"
#include "math.h"

vector_t simple_shader(shader_data_t data) {
	vector_t L = make_vector(0, 0, 1, 0);
	float s = MAX(vec_dot(L, data.norm), 0.25);
	return make_vector(s, s, s, 1);
}
