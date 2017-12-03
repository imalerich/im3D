#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "point.h"

typedef struct obj_vert {
	unsigned v; // vertex index
	unsigned t; // texture coord index
	unsigned n; // vertex normal index
} obj_vert_t;

typedef struct obj_face {
	obj_vert_t a;
	obj_vert_t b;
	obj_vert_t c;
} obj_face_t;

/**
 * Given a line from a .obj file, removes
 * any comment character and any characters found after.
 */
void strip_comments(char * line);

/**
 * Removes trailing whitespace from the input line.
 * Returns the same pointer as was given for convenience.
 */
char * trim_trailing_whitespace(char * line);

/**
 * Given a line from a .obj file, determines whether
 * or not the input line contains a vertex or not.
 */
bool is_vertex(char * line);

/**
 * Given a line from a .obj file, determines whether
 * or not the input line contains a vertex or not.
 */
bool is_texture_coord(char * line);

/**
 * Given a line from a .obj file, determines whether
 * or not the input line contains a vertex normal.
 */
bool is_vertex_norm(char * line);

/**
 * Given a line from a .obj file, determines whether
 * or not the input line contains a face.
 */
bool is_face(char * line);

/**
 * Given a line from a .obj file, determines whether
 * or not the input line contains a model declaration.
 */
bool is_object_start(char * line);

/**
 * First checks the start of the string to see if it matches
 * header, if not this method returns NULL, else skip remaining
 * white space then return the string stored in the rest of the line.
 */
char * read_string(const char * header, char * line);

/**
 * Determines whether or not the given line contains
 * ambient lighting data.
 */
bool is_ambient(char * line);

/**
 * Determines whether or not the given line contains
 * diffuse lighting data.
 */
bool is_diffuse(char * line);

/**
 * Determines whether or not the given line contains
 * specular lighting data.
 */
bool is_specular(char * line);

/**
 * Assumes is_texture_coord(line) == true. This
 * function will not perform this check.
 * Returns the texture coordinate stored
 * in the given line.
 */
vector_t get_texture_coord(char * line);

/**
 * Returns vector data stored in the given line. Skips 'skip'
 * characters following the first non-whitespace character.
 */
vector_t get_vector(char * line, unsigned skip);

/**
 * Assume is_face(line) == true. This
 * function will not perform this check.
 * Returns the indecies into vertex/texture/normal
 * buffers which correspond to each vertex of the triangle.
 */
obj_face_t get_face(char * line);

/**
 * Gets the first non white-space character in the input line.
 */
char get_initial_char(char * line);

/**
 * Prints a face to stdout as it would appear in a .obj file.
 */
void obj_face_print(obj_face_t face);

#endif
