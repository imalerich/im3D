#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

bbox_t find_bbox(point_t * points, unsigned count) {
	point_t min = make_point(INT_MAX, INT_MAX);
	point_t max = make_point(INT_MIN, INT_MIN);

	for (int i=0; i<count; i++) {
		min.x = MIN(min.x, points[i].x); 
		min.y = MIN(min.y, points[i].y);

		max.x = MAX(max.x, points[i].x); 
		max.y = MAX(max.y, points[i].y);
	}

	return (bbox_t){min, max};
}

bool is_point_in_triangle(point_t p, point_t t[3]) {
	vector_t T[3] = {
		point_to_vector(t[0]),
		point_to_vector(t[1]),
		point_to_vector(t[2])
	};

	vector_t bc = bary_centric(point_to_vector(p), T);
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
