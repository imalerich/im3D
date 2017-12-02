#ifndef MODEL_H
#define MODEL_H

#include "point.h"

typedef struct model {
	// stores information about the vertex buffer
	unsigned vert_count; // multiple of 3, vert_count/3 = face_count
	vector_t * vertices; // each set of 3 consecutive 3 vertices forms a triangle
	vector_t * tex_coords; // each vertex has texture coordinates
	vector_t * norms; // each vertex has a normal
} model_t;

/**
 * Loads a file of OBJ format, allocates memory,
 * and stores all necessary pointers in a model object.
 */
model_t obj_load(const char * filename);

/**
 * Frees all memory associated with the input model.
 */
void model_free(model_t * m);

/**
 * Returns the number of faces stored in the given model.
 */
static inline unsigned num_faces(model_t m) {
	return m.vert_count / 3;
}

/**
 * Outputs a list of all vertices for the given model.
 */
void model_print(model_t m);

#endif
