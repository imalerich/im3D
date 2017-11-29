#ifndef MODEL_H
#define MODEL_H

#include "point.h"

typedef struct model {
	// stores information about the vertex buffer
	unsigned vert_count;
	vector_t * vertices;
	vector_t * tex_coords; // each vertex has texture coordinates
	vector_t * norms; // each vertex has a normal

	// each set of 3 indecies forms a triangle
	unsigned index_count;
	unsigned * indecies;
} model_t;

/**
 * Loads a file of OBJ format, allocates memory,
 * and stores all necessary pointers in a model object.
 */
model_t obj_load(const char * filename);

/**
 * Frees all memory associated with the input model.
 */
void model_free(model_t m);

#endif
