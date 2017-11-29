#ifndef POINT_H
#define POINT_H

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
point_t make_point(int x, int y);

/**
 * Function initializer for a vector.
 */
vector_t make_vector(float x, float y, float z, float w);

/**
 * Constructs a vectory representations of 
 * the input coordinate.
 */
vector_t point_to_vector(point_t p);

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
float vec_dot(vector_t v1, vector_t v2);

/**
 * Computes the 3-D vector cross product.
 * This will ignore the w component of each vector.
 * The w component will be set to max(v1.w, v2.w).
 */
vector_t vec_cross(vector_t v1, vector_t v2);

#endif
