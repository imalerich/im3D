#include <stdlib.h>
#include <stdio.h>
#include "model.h"

model_t obj_load(const char * filename) {
	return (model_t){0, NULL, NULL, NULL, 0, NULL};
}

void model_free(model_t m) {
	free(m.vertices);
	free(m.tex_coords);
	free(m.norms);
	free(m.indecies);

	m.vertices = NULL;
	m.tex_coords = NULL;
	m.norms = NULL;
	m.indecies = NULL;
}
