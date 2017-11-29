#ifndef MATH_H
#define MATH_H

#include <stdbool.h>
#include <math.h>
#include "point.h"

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

typedef struct bbox {
	point_t min;
	point_t max;
} bbox_t;

typedef struct vector3 {
	float x;
	float y;
	float z;
} vector3_t;

/**
 * Computes the 2D bounding box on the set of input points.
 */
bbox_t find_bbox(point_t * points, unsigned count);

/**
 * Computes the area of the input triangle.
 */
float area_of_triangle(point_t t[3]);

/**
 * Determines whether or not the input point is contained
 * within the given triangle.
 */
bool is_point_in_triangle(point_t p, point_t t[3]);

/**
 * Given 2-Dimmensional vectors (y,z components are ignored)
 * computes the bary-centric coordinates for the input
 * coordinate with respect to the given triangle.
 */
vector_t bary_centric(vector_t p, vector_t t[3]);

#endif
