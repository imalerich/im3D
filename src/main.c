#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "shaders.h"
#include "buffer.h"
#include "model.h"
#include "color.h"
#include "point.h"
#include "draw.h"
#include "math.h"

const unsigned WIDTH = 3840;
const unsigned HEIGHT = 2160;
#define SIZE make_point(WIDTH, HEIGHT)
#define ARATIO ((float)WIDTH / (float)HEIGHT)
#define NEAR_WIDTH 2.0
#define NEAR_HEIGHT (NEAR_WIDTH / ARATIO)

int main(int argc, char ** argv) {
	srand(time(NULL));

	// --- SETUP --- //

	uint8_t * buffer = malloc_buffer(WIDTH, HEIGHT);
	float * back_buffer = malloc_back_buffer(WIDTH, HEIGHT);

	const char * obj_file = "models/dragon.obj";
	model_group_t models = obj_load(obj_file);
	matrix_t proj = mat_proj(1.0, 100.0, NEAR_WIDTH, NEAR_HEIGHT);

	// --- RENDER --- //

	draw_clear(BLACK, buffer, SIZE);

	for (unsigned k=0; k<models.model_count; k++) {
		model_t m = models.models[k];

		for (int i=0; i<num_faces(m); i++) {
			vector_t v[3] = {
				mat_vec_multiply(&proj, m.vertices[3*i + 0]),
				mat_vec_multiply(&proj, m.vertices[3*i + 1]),
				mat_vec_multiply(&proj, m.vertices[3*i + 2]),
			};

			vector_t offset = make_vector(1.0, 1.0, 0.0, 0.0);
			for (int i=0; i<3; i++) {
				v[i].y = -v[i].y;
				v[i] = vec_scale(v[i], 1.0 / v[i].w);
				v[i] = vec_add(v[i], offset);
				v[i] = vec_scale(v[i], 0.5);
				v[i].x = v[i].x * WIDTH;
				v[i].y = v[i].y * HEIGHT;
			}

			m.vertices[3*i + 0] = v[0];
			m.vertices[3*i + 1] = v[1];
			m.vertices[3*i + 2] = v[2];

			draw_triangle(&m, i, simple_shader, m.material, buffer, back_buffer, SIZE);
		}
	}

	// --- OUTPUT & CLEANUP --- //

	save_img("out.png", buffer, WIDTH, HEIGHT);
	free(buffer);
	free(back_buffer);
	model_group_free(&models);
	return 0; 
}
