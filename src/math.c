#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

bbox_t find_bbox(vector_t * v, unsigned count) {
	point_t min = make_point(INT_MAX, INT_MAX);
	point_t max = make_point(INT_MIN, INT_MIN);

	for (int i=0; i<count; i++) {
		min.x = MIN(min.x, (int)floor(v[i].x)); 
		min.y = MIN(min.y, (int)floor(v[i].y));

		max.x = MAX(max.x, (int)ceil(v[i].x)); 
		max.y = MAX(max.y, (int)ceil(v[i].y));
	}

	return (bbox_t){min, max};
}

bbox_t intersect_bbox(bbox_t b0, bbox_t b1) {
	return (bbox_t){
		{MAX(b0.min.x, b1.min.x), MAX(b0.min.y, b1.min.y)},
		{MIN(b0.max.x, b1.max.x), MIN(b0.max.y, b1.max.y)}
	};
}

void print_bbox(bbox_t b) {
	printf("[ min: ");
	print_point(b.min);
	printf(", max: ");
	print_point(b.max);
	printf(" ]\n");
}

bool is_point_in_triangle(vector_t p, vector_t t[3]) {
	vector_t bc = bary_centric(p, t);
	return bc.x >= 0 & bc.y >= 0 && bc.z >= 0;
}

float area_of_triangle(point_t t[3]) {
	return 0.5 * abs(
			-t[1].y * t[2].x + 
			t[0].y * (-t[1].x + t[2].x) +
			t[0].x * (t[1].y - t[2].y) + 
			t[1].x * t[2].y);
}

vector_t bary_centric(vector_t p, vector_t t[3]) {
	vector_t c0 = make_vector(
		t[2].x - t[0].x,
		t[1].x - t[0].x,
		t[0].x - p.x, 0.0
	);

	vector_t c1 = make_vector(
		t[2].y - t[0].y, 
		t[1].y - t[0].y, 
		t[0].y - p.y, 0.0
	);
	
	vector_t u = vec_cross(c0, c1);

	if (abs(u.z) < 1) {
		return make_vector(-1, 1, 1, 0);
	} else {
		return make_vector(1.0 - (u.x + u.y)/u.z, u.y/u.z, u.x/u.z, 0);
	}
}
