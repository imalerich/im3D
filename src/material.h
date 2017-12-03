#ifndef MATERIAL_H
#define MATERIAL_H

#include "buffer.h"
#include "point.h"

typedef struct material {
	char * name;
	vector_t ambient;
	vector_t diffuse;
	vector_t specular;
	image_t tex;
	image_t bump;
} material_t;

typedef struct material_group {
	unsigned mat_count;
	material_t * mats;
} material_group_t;

/**
 * Creates a new default material using the given name.
 * This material has no texture, no ambient, no specular,
 * and a white diffuse.
 */
material_t new_material(char * name);

/**
 * Searches the material group for the given material name.
 * If no material is found, NULL will be returned.
 */
material_t * find_material(material_group_t m, char * name);

/**
 * Releases all associated data from the given
 * material from memomry.
 */
void material_free(material_t * m);

/**
 * Free a list of materials, as return by load_materials.
 */
void material_group_free(material_group_t * m);

/**
 * Given a .obj filename, searches for a material reference, then
 * loads the given file using load_materials.
 */
material_group_t obj_load_materials(const char * filename);

/**
 * Load a list of materials from a .mtl file.
 */
material_group_t load_materials(const char * filename);

#endif
