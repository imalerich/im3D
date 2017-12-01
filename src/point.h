#ifndef POINT_H
#define POINT_H

#include <math.h>

#define POINT_ZERO make_point(0, 0)
#define VECTOR_ZERO make_vector(0, 0, 0, 0)

typedef struct point {
	int x;
	int y;
} point_t;

typedef struct vector {
	float x;
	float y;
	float z;
	float w;
} vector_t;

/**
 * Function initializer for a point.
 */
static inline point_t make_point(int x, int y) {
	return (point_t){x, y};
}

/**
 * Function initializer for a vector.
 */
static inline vector_t make_vector(float x, float y, float z, float w) {
	return (vector_t){x, y, z, w};
}

/**
 * Constructs a vector representation of the input point.
 */
static inline vector_t point_to_vector(point_t p) {
	return (vector_t){(float)p.x, (float)p.y, 0.0, 0.0};
}

/**
 * Constructs a point representation of the input vector.
 */
static inline point_t vector_to_point(vector_t v) {
	return (point_t){(int)lroundf(v.x), (int)lroundf(v.y)};
}

/**
 * Perform vector vector addition.
 */
static inline vector_t vector_add(vector_t v0, vector_t v1) {
	return make_vector(
		v0.x + v1.x, 
		v0.y + v1.y,
		v0.z + v1.z,
		v0.w + v1.w
	);
}

/**
 * Perform vector scalar multiplication.
 */
static inline vector_t vector_scale(vector_t v, float s) {
	return make_vector(v.x * s, v.y * s, v.z * s, v.w * s);
}

/**
 * Computes the magnitude of the input vector.
 */
float vec_mag(vector_t v);

/**
 * Normalizes the input vector to unit length.
 */
vector_t vec_norm(vector_t v);

/**
 * Computes the vector dot product.
 */
static inline float vec_dot(vector_t v1, vector_t v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

/**
 * Computes the 3-D vector cross product.
 * This will ignore the w component of each vector.
 * The w component will be set to max(v1.w, v2.w).
 */
vector_t vec_cross(vector_t v1, vector_t v2);

/**
 * Interpolates the three input vectors using the bary centric coordinates.
 */
vector_t interpolate(vector_t v[3], vector_t b);

/**
 * Prints a vector to the standard output, does not include a new line.
 */
void print_vector(vector_t v);

/**
 * Prints a point to the standard output, does not include a new line.
 */
void print_point(point_t p);

#endif
