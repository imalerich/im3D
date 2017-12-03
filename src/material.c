#include <stdlib.h>
#include <stdio.h>

#include "material.h"
#include "io.h"

material_t new_material(char * name) {
	return (material_t){
		name,
		VECTOR_ZERO,
		VECTOR_ONE,
		VECTOR_ZERO,
		EMPTY_IMG,
		EMPTY_IMG
	};
}

material_t * find_material(material_group_t m, char * name) {
	for (int i=0; i<m.mat_count; i++) {
		material_t * mat = &m.mats[i];
		if (strcmp(name, mat->name) == 0) {
			return mat;
		}
	}

	return NULL;
}

void material_free(material_t * m) {
	free_img(&m->tex);
	free(m->name);
	m->name = NULL;
}

void material_group_free(material_group_t * m) {
	for (unsigned i=0; i<m->mat_count; i++) {
		material_free(&m->mats[i]);
	}

	free(m->mats);
	m->mats = NULL;
}

material_group_t obj_load_materials(const char * filename) {
	FILE * fp = fopen(filename, "r");
	char line[1000];
	material_group_t ret = (material_group_t){0, NULL};
	
	// get the directory structure from the input filename
	size_t length = strlen(filename);
	char * directory = malloc(sizeof(char) * (length+1));
	memcpy(directory, filename, length);
	directory[length] = '\0';

	for (int i=length; i>0; i--) {
		if (directory[i] == '/') { break; }
		directory[i] = '\0';
	}
	size_t dir_len = strlen(directory);

	// read each line from the file
	// comment lines or unsupported directives are ignored
	while (fgets(line, sizeof(line), fp) != NULL) {
		strip_comments(line);
		char * name = read_string("mtllib", line);

		if (name) {
			size_t name_len = strlen(name);
			directory = realloc(directory, name_len + dir_len + 1);
			strcat(directory, name);
			directory[name_len + dir_len] = '\0';

			// found a material file reference
			// close the current file & load the materials
			fclose(fp);
			ret = load_materials(directory);

			free(name);
			free(directory);
			return ret;
		}
	}

	free(directory);
	fclose(fp);
	return ret;
}

material_group_t load_materials(const char * filename) {
	FILE * fp = fopen(filename, "r");
	char line[1000];

	unsigned material_count = 0, buffer_size = 8;
	material_t * buffer = malloc(sizeof(material_t) * buffer_size);

	// read each line from the file
	// comment lines or unsupported directives are ignored
	while (fgets(line, sizeof(line), fp) != NULL) {
		strip_comments(line);
		char * name = read_string("newmtl", line);
		char * tex = read_string("map_Kd", line);
		char * bump = read_string("map_Bump", line);

		if (name) {
			buffer[material_count++] = new_material(name);

		} else if (tex) {
			buffer[material_count-1].tex = load_img(tex);
			free(tex);

		} else if (bump) {
			buffer[material_count-1].bump = load_img(bump);
			free(bump);

		} else if (is_ambient(line)) {
			buffer[material_count].ambient = get_vector(line, 2);

		} else if (is_diffuse(line)) {
			buffer[material_count].diffuse = get_vector(line, 2);

		} else if (is_specular(line)) {
			buffer[material_count].specular = get_vector(line, 2);

		}

		// check if we need to reallocate buffer size
		if (material_count == buffer_size) {
			buffer_size *= 2;
			buffer = realloc(buffer, sizeof(material_t) * buffer_size);
		}
	}

	fclose(fp);
	return (material_group_t){ material_count, buffer };
}

