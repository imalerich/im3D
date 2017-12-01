#ifndef SHADERS_H
#define SHADERS_H

#include "point.h"
#include "model.h"
#include "math.h"

typedef struct shader_data {
	vector_t pos;
	vector_t tex_coord;
	vector_t norm;
} shader_data_t;

/**
 * A basic shader, no texturing, just lighting.
 */
vector_t simple_shader(shader_data_t data);

#endif
