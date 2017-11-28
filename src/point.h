#ifndef POINT_H
#define POINT_H

#define POINT_ZERO make_point(0, 0)

typedef struct point {
	int x;
	int y;
} point_t;

/**
 * Function initializer for a point.
 */
point_t make_point(int x, int y);

#endif
