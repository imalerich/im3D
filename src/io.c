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

bool is_vertex(char * line) {
	char init = get_initial_char(line++);
	char last = get_initial_char(line);

	// a vertex takes the form "v "
	return init == 'v' && isspace(last);
}

bool is_texture_coord(char * line) {
	char init = get_initial_char(line++);
	char next = get_initial_char(line++);
	char last = get_initial_char(line);

	// a texture coordinate takes the form "vt "
	return init == 'v' && next == 't' && isspace(last);
}

bool is_vertex_norm(char * line) {
	char init = get_initial_char(line++);
	char next = get_initial_char(line++);
	char last = get_initial_char(line);

	// a vertex normal takes the form "vn "
	return init == 'v' && next == 'n' && isspace(last);
}

bool is_face(char * line) {
	char init = get_initial_char(line++);
	char last = get_initial_char(line);

	// a vertex takes the form "v "
	return init == 'n' && isspace(last);
}

vector_t get_vertex(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'v') { ++line; }

	float x, y, z;
	sscanf(line, "%f %f %f", x, y, z);
	return make_vector(x, y, z, 1.0);
}

coord_t get_texture_coord(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'v' || *line == 't') { ++line; }

	float u, v;
	sscanf(line, "%f %f", u, v);
	return make_coords(u, v);
}

vector_t get_vertex_norm(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'v' || *line == 'n') { ++line; }

	float x, y, z;
	sscanf(line, "%f %f %f", x, y, z);
	return make_vector(x, y, z, 0.0);
}

obj_face_t get_face(char * line) {
	// skip the line header
	while (isspace(*line) || *line == 'h') { ++line; }
	obj_face_t ret;

	sscanf(line, "%d %d %d  %d %d %d  %d %d %d",
		ret.a.v, ret.a.t, ret.a.n,
		ret.b.v, ret.b.t, ret.b.n,
		ret.c.v, ret.c.t, ret.c.n
	);
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
