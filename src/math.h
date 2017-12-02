#ifndef MATH_H
#define MATH_H

#include <stdbool.h>
#include <math.h>

#include "point.h"
#include "matrix.h"

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

typedef struct bbox {
	point_t min;
	point_t max;
} bbox_t;

/**
 * Computes the 2D bounding box on the set of transformed input vectors.
 */
bbox_t find_bbox(vector_t * v, unsigned count);

/**
 * Bounds 'box' within the context of 'within'.
 */
bbox_t intersect_bbox(bbox_t b0, bbox_t b1);

/**
 * Prints the input bounding box to the screen.
 */
void print_bbox(bbox_t b);

/**
 * Computes the area of the input triangle.
 */
float area_of_triangle(point_t t[3]);

/**
 * Determines whether or not the input point is contained
 * within the given triangle.
 */
bool is_point_in_triangle(vector_t p, vector_t t[3]);

/**
 * Given 2-Dimmensional vectors (y,z components are ignored)
 * computes the bary-centric coordinates for the input
 * coordinate with respect to the given triangle.
 */
vector_t bary_centric(vector_t p, vector_t t[3]);

#endif
