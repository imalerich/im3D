#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

#define MAT_DIMM 4
#define MAT_SIZE (MAT_DIMM*MAT_DIMM)

typedef struct matrix {
	float data[16];
} matrix_t;

/**
 * Return the value from input matrix at
 * the given indecies. If invalid indecies are
 * given, this function returns 0.
 */
static inline float mat_get_val(matrix_t * m, unsigned row, unsigned col) {
	int idx = row * MAT_DIMM + col;
	if (idx < 0 || idx >= MAT_SIZE) {
		return 0.0;
	}

	return m->data[idx];
}

/**
 * Update the value at index [row, col] in matrix m to
 * the given 'val'. If invalid indecies are given,
 * this function does nothing.
 */
static inline void mat_set_val(matrix_t * m, unsigned row, unsigned col, float val) {
	int idx = row * MAT_DIMM + col;
	if (idx < 0 || idx >= MAT_SIZE) { return; }

	m->data[idx] = val;
}

/**
 * Creates a new 0 filled matrix.
 */ 
static inline matrix_t mat_zero() {
	matrix_t m;
	for (int i=0; i<MAT_SIZE; i++) { m.data[i] = 0; }
	return m;
}

/**
 * Creates a new matrix representing the identity matrix.
 */
static inline matrix_t mat_identity() {
	matrix_t m = mat_zero();
	for (int i=0; i<MAT_SIZE; i++) {
		mat_set_val(&m, i, i, 1.0);
	}

	return m;
}

/**
 * Creates a random matrix using integers 0-9.
 */
static inline matrix_t mat_rand() {
	matrix_t m;
	for (int i=0; i<MAT_SIZE; i++) { m.data[i] = rand() % 10; }
	return m;
}

/**
 * Creates a transformation which scales a vector by scalar s.
 */
matrix_t mat_trans_scale(float s);

/**
 * Creates a transformation matrix representing a rotationg
 * about the x-axis by angle theta (radians).
 */
matrix_t mat_trans_x_rot(float theta);

/**
 * Creates a transformation matrix representing a rotationg
 * about the y-axis by angle theta (radians).
 */
matrix_t mat_trans_y_rot(float theta);

/**
 * Creates a transformation matrix representing a rotationg
 * about the z-axis by angle theta (radians).
 */
matrix_t mat_trans_z_rot(float theta);

/**
 * Creates a transformation matrix representing a rotation 
 * about the input axis by angle theta (radians). 
 * This axis need not be a unit vector as it will be normalized 
 * by this function.
 */
matrix_t mat_trans_rot(vector_t axis, float theta);

/**
 * Creates a transformation matrix representation a 
 * translation by the given vector trans. Note
 * the w component of this input vector will be ignored.
 */
matrix_t mat_trans_translate(vector_t trans);

/**
 * Creates a projection matrix with the given near plane distance.
 * The first two parameters are the distances of the near and far plane.
 * The width parameter determines the width of the near plane.
 * The height parameter determines the height of the near plane.
 */
matrix_t mat_proj(float near, float far, float width, float height);

/**
 * Reads a row of the input matrix and returns it as a vector.
 */
vector_t get_row(matrix_t * m, unsigned row);

/**
 * Reads a column of the input matrix and returns it as a vector.
 */
vector_t get_col(matrix_t * m, unsigned col);

/**
 * Multiplies the two input matrices and returns the result.
 */
matrix_t mat_multiply(matrix_t * m0, matrix_t * m1);

/**
 * Creates a new matrix, who's values are equal to
 * corresponding values in m0 multiplied by s.
 */
matrix_t mat_scalar_multiply(matrix_t * m0, float s);

/**
 * Performs matrix-vector multiplication and returns the result.
 */
vector_t mat_vec_multiply(matrix_t * m, vector_t v);

/**
 * Debug utility, prints the input matrix to stdout.
 */
void mat_print(matrix_t * m);

#endif
