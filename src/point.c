#include <math.h>
#include "point.h"
#include "math.h"

point_t make_point(int x, int y) {
	return (point_t){x, y};
}

vector_t make_vector(float x, float y, float z, float w) {
	return (vector_t){x, y, z, w};
}

vector_t point_to_vector(point_t p) {
	return (vector_t){(float)p.x, (float)p.y, 0.0, 0.0};
}

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

float vec_dot(vector_t v1, vector_t v2) {
	return 
		v1.x * v2.x + 
		v1.y * v2.y + 
		v1.z * v2.z + 
		v1.w * v2.w;
}

vector_t vec_cross(vector_t v1, vector_t v2) {
	return make_vector(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x,
		MAX(v1.w, v2.w)
	);
}
