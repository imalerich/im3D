#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void strip_comments(char * line) {
	size_t len = strlen(line);
	bool found_comment = false;

	for (int i=0; i<len; i++) {
		if (line[i] == '#') {
			found_comment = true;
		}

		line[i] = found_comment ? '\0' : line[i];
	}
}

char * trim_trailing_whitespace(char * line) {
	size_t len = strlen(line);
	for (unsigned i=len-1; i>0; i--) {
		if (isspace(line[i])) {
			line[i] = '\0';
		}
	}

	return line;
}

bool is_vertex(char * line) {
	char init = get_initial_char(line++);
	char last = *line;

	// a vertex takes the form "v "
	return init == 'v' && isspace(last);
}

bool is_texture_coord(char * line) {
	char init = get_initial_char(line++);
	char next = *line++;
	char last = *line;

	// a texture coordinate takes the form "vt "
	return init == 'v' && next == 't' && isspace(last);
}

bool is_vertex_norm(char * line) {
	char init = get_initial_char(line++);
	char next = *line++;
	char last = *line;

	// a vertex normal takes the form "vn "
	return init == 'v' && next == 'n' && isspace(last);
}

bool is_face(char * line) {
	char init = get_initial_char(line++);
	char last = *line++;

	// a face takes the form "f "
	return init == 'f' && isspace(last);
}

bool is_object_start(char * line) {
	char init = get_initial_char(line++);
	char last = *line++;

	// a model declaration takes the form "o "
	return init == 'o' && isspace(last);
}

char * read_string(const char * header, char * line) {
	while (isspace(*line)) { line++; }
	size_t h_length = strlen(header);
	char sub[h_length+1]; memcpy(sub, line, h_length); sub[h_length] = '\0';
	if (strcmp(sub, header) != 0) { return NULL; }

	line += h_length;
	while (isspace(*line)) { line++; }
	size_t length = strlen(line);
	char * ret = malloc(sizeof(char) * (length + 1));
	memcpy(ret, line, length);
	ret[length] = '\0';
	return trim_trailing_whitespace(ret);
}

bool is_ambient(char * line) {
	char init = get_initial_char(line++);
	char next = *line++;
	char last = *line;

	// a texture coordinate takes the form "vt "
	return init == 'K' && next == 'a' && isspace(last);
}

bool is_diffuse(char * line) {
	char init = get_initial_char(line++);
	char next = *line++;
	char last = *line;

	// a texture coordinate takes the form "vt "
	return init == 'K' && next == 'd' && isspace(last);
}

bool is_specular(char * line) {
	char init = get_initial_char(line++);
	char next = *line++;
	char last = *line;

	// a texture coordinate takes the form "vt "
	return init == 'K' && next == 's' && isspace(last);
}

vector_t get_vertex(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'v') { ++line; }

	float x, y, z;
	sscanf(line, "%f %f %f", &x, &y, &z);
	return make_vector(x, y, z, 1.0);
}

vector_t get_texture_coord(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'v' || *line == 't') { ++line; }

	float u, v;
	sscanf(line, "%f %f", &u, &v);
	return make_vector(u, v, 0.0, 0.0);
}

vector_t get_vertex_norm(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'v' || *line == 'n') { ++line; }

	float x, y, z;
	sscanf(line, "%f %f %f", &x, &y, &z);
	return make_vector(x, y, z, 0.0);
}

vector_t get_vector(char * line, unsigned skip) {
	// skip the line header
	while (isspace(*line) || *line == 'K' || *line == 'a') { ++line; }
	line += skip;

	float x, y, z;
	sscanf(line, "%f %f %f", &x, &y, &z);
	return make_vector(x, y, z, 1.0);
}

// utility for get_face
// decrements indecies from 1 based to 0 based
obj_vert_t obj_vert_decrement(obj_vert_t o) {
	return (obj_vert_t){
		o.v - 1, o.t - 1, o.n - 1
	};
}

obj_face_t get_face(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'f') { ++line; }
	obj_face_t ret;

	sscanf(line, "%d/%d/%d %d/%d/%d %d/%d/%d",
		&ret.a.v, &ret.a.t, &ret.a.n,
		&ret.b.v, &ret.b.t, &ret.b.n,
		&ret.c.v, &ret.c.t, &ret.c.n
	);

	// given indecies are 1 based, convert them to 0 based
	ret.a = obj_vert_decrement(ret.a);
	ret.b = obj_vert_decrement(ret.b);
	ret.c = obj_vert_decrement(ret.c);

	return ret;
}

char get_initial_char(char * line) {
	size_t len = strlen(line);
	for (int i=0; i<len; i++) {
		if (!isspace(line[i])) {
			return line[i];
		}
	}

	return '\0';
}

void obj_face_print(obj_face_t face) {
	printf("%d/%d/%d %d/%d/%d %d/%d/%d\n",
		face.a.v, face.a.t, face.a.n,
		face.b.v, face.b.t, face.b.n,
		face.c.v, face.c.t, face.c.n
	);
}
