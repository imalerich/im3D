#include <limits.h>
#include <stdio.h>

#include "matrix.h"
#include "math.h"

matrix_t mat_trans_scale(float s) {
	matrix_t m = mat_identity();
	return mat_scalar_multiply(&m, s);
}

matrix_t mat_trans_x_rot(float theta) {
	matrix_t m = mat_identity();
	mat_set_val(&m, 1, 1, cos(theta));
	mat_set_val(&m, 1, 2, -sin(theta));
	mat_set_val(&m, 2, 1, sin(theta));
	mat_set_val(&m, 2, 2, cos(theta));
	return m;
}

matrix_t mat_trans_y_rot(float theta) {
	matrix_t m = mat_identity();
	mat_set_val(&m, 0, 0, cos(theta));
	mat_set_val(&m, 0, 2, -sin(theta));
	mat_set_val(&m, 2, 0, sin(theta));
	mat_set_val(&m, 2, 2, cos(theta));
	return m;
}

matrix_t mat_trans_z_rot(float theta) {
	matrix_t m = mat_identity();
	mat_set_val(&m, 0, 0, cos(theta));
	mat_set_val(&m, 0, 1, -sin(theta));
	mat_set_val(&m, 1, 0, sin(theta));
	mat_set_val(&m, 1, 1, cos(theta));
	return m;
}

vector_t get_row(matrix_t * m, unsigned row) {
	unsigned idx = row * MAT_DIMM;
	return make_vector(
		m->data[idx + 0],
		m->data[idx + 1],
		m->data[idx + 2],
		m->data[idx + 3]
	);
}

matrix_t mat_trans_rot(vector_t axis, float theta) {
	matrix_t m = mat_identity();
	const vector_t A = vec_norm(axis);
	const float c = cos(theta);
	const float s = sin(theta);

	// row 0
	m.data[0] = c + (1-c)*pow(A.x, 2);
	m.data[1] = (1-c) * A.x * A.y - s * A.z;
	m.data[2] = (1-c) * A.x * A.z + s * A.y;
	m.data[3] = 0;

	// row 1
	m.data[4] = (1-c) * A.x * A.y + s * A.z;
	m.data[5] = c + (1-c) * pow(A.y, 2);
	m.data[6] = (1-c) * A.y * A.z - s * A.x;
	m.data[7] = 0;
	
	// row 2
	m.data[8] = (1-c) * A.x * A.z - s * A.y;
	m.data[9] = (1-c) * A.y * A.z + s * A.x;
	m.data[10] = c + (1-c) * pow(A.z, 2);
	m.data[11] = 0;

	// row 3 = default

	return m;
}

matrix_t mat_trans_translate(vector_t trans) {
	matrix_t m = mat_identity();
	mat_set_val(&m, 0, 3, trans.x);
	mat_set_val(&m, 1, 3, trans.y);
	mat_set_val(&m, 2, 3, trans.z);
	return m;
}

matrix_t mat_proj(float near) {
	matrix_t m = mat_identity();
	mat_set_val(&m, 3, 2, -1.0/near);
	return m;
}

vector_t get_col(matrix_t * m, unsigned col) {
	return make_vector(
		m->data[col + 0 * MAT_DIMM],
		m->data[col + 1 * MAT_DIMM],
		m->data[col + 2 * MAT_DIMM],
		m->data[col + 3 * MAT_DIMM]
	);
}

matrix_t mat_multiply(matrix_t * m0, matrix_t * m1) {
	vector_t r[MAT_DIMM];
	vector_t c[MAT_DIMM];

	for (int i=0; i<MAT_DIMM; i++) {
		r[i] = get_row(m0, i);
		c[i] = get_col(m1, i);
	}

	matrix_t m;
	for (int i=0; i<MAT_DIMM; i++) {
		for (int j=0; j<MAT_DIMM; j++) {
			// the value is computed by taking the dot product
			// of rows from m0 and columns from m1
			mat_set_val(&m, i, j, vec_dot(r[i], c[j]));
		}
	}

	return m;
}

matrix_t mat_scalar_multiply(matrix_t * m0, float s) {
	matrix_t m;
	for (int i=0; i<MAT_DIMM; i++) {
		for (int j=0; j<MAT_DIMM; j++) {
			mat_set_val(&m, i, j, s * mat_get_val(m0, i, j));
		}
	}

	return m;
}

vector_t mat_vec_multiply(matrix_t * m, vector_t v) {
	return make_vector(
		vec_dot(get_row(m, 0), v),
		vec_dot(get_row(m, 1), v),
		vec_dot(get_row(m, 2), v),
		vec_dot(get_row(m, 3), v)
	);
}

void mat_print(matrix_t * m) {
	for (int i=0; i<MAT_DIMM; i++) {
		printf("[ ");
		for (int j=0; j<MAT_DIMM; j++) {
			printf("%.3f ", mat_get_val(m, i, j));
		}
		printf("]\n");
	}
}
