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

typedef struct coords {
	float u;
	float v;
} coord_t;

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
 * Function initializer for vertex coordinates.
 */
static inline coord_t make_coords(float u, float v) {
	return (coord_t){u, v};
}

/**
 * Constructs a vectory representations of 
 * the input coordinate.
 */
static inline vector_t point_to_vector(point_t p) {
	return (vector_t){(float)p.x, (float)p.y, 0.0, 0.0};
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
 * Prints a vector to the standard output, does not include a new line.
 */
void print_vector(vector_t v);

/**
 * Prints a vector to the standard output, does not include a new line.
 */
void print_coord(coord_t c);

#endif
