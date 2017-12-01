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
 * Assumes is_vertex(line) == true. This
 * function will not perform this check.
 * Returns the vertex data stored in the given line.
 */
vector_t get_vertex(char * line);

/**
 * Assumes is_texture_coord(line) == true. This
 * function will not perform this check.
 * Returns the texture coordinate stored
 * in the given line.
 */
vector_t get_texture_coord(char * line);

/**
 * Assumes is_vertex_norm(line) == true. This
 * function will not perform this check.
 * Returns the vertex normal stored in the given line.
 */
vector_t get_vertex_norm(char * line);

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
