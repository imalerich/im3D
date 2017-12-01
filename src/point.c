#include <stdio.h>
#include <math.h>
#include "point.h"
#include "math.h"

float vec_mag(vector_t v) {
	return sqrt(
		v.x * v.x +
		v.y * v.y + 
		v.z * v.z + 
		v.w * v.w
	);
}

vector_t vec_norm(vector_t v) {
	float mag = vec_mag(v);
	return make_vector(v.x / mag, v.y / mag, v.z / mag, v.w / mag);
}

vector_t vec_cross(vector_t v1, vector_t v2) {
	return make_vector(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x,
		MAX(v1.w, v2.w)
	);
}

vector_t interpolate(vector_t v[3], vector_t b) {
	return make_vector(
		v[0].x * b.x + v[1].x * b.y + v[2].x * b.z,
		v[0].y * b.x + v[1].y * b.y + v[2].y * b.z,
		v[0].z * b.x + v[1].z * b.y + v[2].z * b.z,
		v[0].w * b.x + v[1].w * b.y + v[2].w * b.z
	);
}

void print_vector(vector_t v) {
	printf("[%.2f %.2f %.2f %.2f]", v.x, v.y, v.z, v.w);
}

void print_point(point_t p) {
	printf("<%d %d>", p.x, p.y);
}
