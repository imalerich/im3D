#include <limits.h>
#include <stdio.h>

#include "matrix.h"
#include "math.h"

vector_t get_row(matrix_t * m, unsigned row) {
	unsigned idx = row * MAT_DIMM;
	return make_vector(
		m->data[idx + 0],
		m->data[idx + 1],
		m->data[idx + 2],
		m->data[idx + 3]
	);
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

void mat_print(matrix_t * m) {
	for (int i=0; i<MAT_DIMM; i++) {
		printf("[ ");
		for (int j=0; j<MAT_DIMM; j++) {
			printf("%.3f ", mat_get_val(m, i, j));
		}
		printf("]\n");
	}
}
