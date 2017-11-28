#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "buffer.h"
#include "color.h"
#include "point.h"
#include "draw.h"

const unsigned WIDTH = 1366;
const unsigned HEIGHT = 768;
#define SIZE make_point(WIDTH, HEIGHT)

int main(int argc, char ** argv) {
	srand(time(NULL));
	uint8_t * buffer = malloc_buffer(WIDTH, HEIGHT);

	draw_clear(BLACK, buffer, SIZE);

	point_t p[3] = {
		make_point(710, 270),
		make_point(750, 360),
		make_point(770, 280)
	};

	draw_triangle(p, BLUE, buffer, SIZE);
	draw_triangle_frame(p, RED, buffer, SIZE);

	save_img("out.png", buffer, WIDTH, HEIGHT);
	return 0;
}
