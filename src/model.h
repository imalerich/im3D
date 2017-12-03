#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "buffer.h"
#include "material.h"

typedef struct model {
	// stores information about the vertex buffer
	unsigned vert_count; // multiple of 3, vert_count/3 = face_count
	vector_t * vertices; // each set of 3 consecutive 3 vertices forms a triangle
	vector_t * tex_coords; // each vertex has texture coordinates
	vector_t * norms; // each vertex has a normal
	vector_t * tangents; // each vertex has a tangent vector
	material_t * material; // material name, this references a material_t in a .mtl file
} model_t;

typedef struct model_group {
	unsigned model_count;
	model_t * models;
	unsigned texture_count;
	image_t * textures;
} model_group_t;

/**
 * Loads a file of OBJ format, allocates memory,
 * and stores all necessary pointers in a list of model objects,
 * count will be the number of models in the returned list.
 */
model_group_t obj_load(const char * filename);

/**
 * Generates tangent vectors for the input model.
 * These can be used alongside of the normal vectors
 * to create a tangent space for bump mapping.
 * Assumes m->tangent is already allocated and zero.
 */
void compute_model_tangents(model_t * m);

/**
 * Frees all memory associated with the input model.
 */
void model_free(model_t * m);

/**
 * Frees all data associated with the model group.
 */
void model_group_free(model_group_t * m);

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
