#include <limits.h>
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
	return true;
}
