#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "buffer.h"
#include "model.h"
#include "color.h"
#include "point.h"
#include "draw.h"
#include "math.h"

const unsigned WIDTH = 1366;
const unsigned HEIGHT = 768;
#define SIZE make_point(WIDTH, HEIGHT)

int main(int argc, char ** argv) {
	srand(time(NULL));

	uint8_t * buffer = malloc_buffer(WIDTH, HEIGHT);
	model_t cube = obj_load("models/monkey.obj");
	matrix_t proj = mat_proj(1.0);

	draw_clear(BLACK, buffer, SIZE);

	color_t colors[7] = {
		RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, WHITE
	};

	for (int i=0; i<num_faces(cube); i++) {
		vector_t v[3] = {
			mat_vec_multiply(&proj, cube.vertices[3*i + 0]),
			mat_vec_multiply(&proj, cube.vertices[3*i + 1]),
			mat_vec_multiply(&proj, cube.vertices[3*i + 2]),
		};

		vector_t offset = make_vector(1.0, 1.0, 0.0, 0.0);
		for (int i=0; i<3; i++) {
			v[i].y = -v[i].y;
			v[i] = vector_scale(v[i], 1.0 / v[i].w);
			v[i] = vector_add(v[i], offset);
			v[i] = vector_scale(v[i], 0.5);
			v[i].x = v[i].x * WIDTH;
			v[i].y = v[i].y * HEIGHT;
		}

		point_t p[3] = {
			vector_to_point(v[0]),
			vector_to_point(v[1]),
			vector_to_point(v[2])
		};

		draw_triangle(p, colors[rand() % 7], buffer, SIZE);
	}

	save_img("out.png", buffer, WIDTH, HEIGHT);
	return 0;
}
