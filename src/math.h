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

/**
 * Computes the 2D bounding box on the set of input points.
 */
bbox_t find_bbox(point_t * points, unsigned count);

/**
 * Determines whether or not the input point is contained
 * within the given triangle.
 */
bool is_point_in_triangle(point_t p, point_t t[3]);

#endif
