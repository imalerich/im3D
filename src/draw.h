#ifndef DRAW_H
#define DRAW_H

#include "material.h"
#include "shaders.h"
#include "color.h"
#include "point.h"
#include "model.h"

extern unsigned thread_count;

/**
 * Clears the input buffer to the given color.
 */
void draw_clear(color_t c, uint8_t * buffer, point_t buffer_size);

/**
 * Draws the given color to the input texture buffer at the given
 * (x,y) coordinates.
 */
void draw_point(point_t coords, color_t c, uint8_t * buffer, point_t buffer_size);

/**
 * Draws a line using the input color from the start point to the
 * end point onto the input buffer.
 */
void draw_line(point_t start, point_t end, color_t c, uint8_t * buffer, point_t buffer_size);

/**
 * Draws a wireframe triangle composed of the input 3 points using the given color.
 */
void draw_triangle_frame(point_t t[3], color_t c, uint8_t * buffer, point_t buffer_size);

/**
 * Draws a single triangle from the given mesh at the given face index.
 * Assumes vertices have already been transformed.
 */
void draw_triangle(model_t * m, unsigned idx, 
	vector_t (*shader)(shader_data_t data, material_t * mat),
	material_t * material,
	uint8_t * buffer, float * back, point_t buffer_size);

#endif
