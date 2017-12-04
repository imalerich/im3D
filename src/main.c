#include <omp.h>
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

	omp_set_num_threads(4);
	int thread_count = 4;
	#pragma omp parallel for num_threads(thread_count)
	for (int i=0; i<16; i++) {
		int tid = omp_get_num_threads();
		printf("thread_count = %d\n", tid);
		fflush(stdout);
	}

	// --- SETUP --- //

	uint8_t * buffer = malloc_buffer(WIDTH, HEIGHT);
	float * back_buffer = malloc_back_buffer(WIDTH, HEIGHT);

	const char * obj_file = "models/war.obj";
	model_group_t models = obj_load(obj_file);
	matrix_t proj = mat_proj(1.0, 100.0, NEAR_WIDTH, NEAR_HEIGHT);

	// --- RENDER --- //

	draw_clear(BLACK, buffer, SIZE);
	double start = omp_get_wtime();

	for (unsigned k=0; k<models.model_count; k++) {
		model_t m = models.models[k];

		#pragma omp parallel for num_threads(4)
		for (unsigned i=0; i<m.vert_count; i++) {
			int tid = omp_get_thread_num();
			if (tid != 0) {
				printf("thread_id = %d\n", tid);
				fflush(stdout);
			}
			transform_vertex(&m.vertices[i], &proj, WIDTH, HEIGHT);
		}

		// for (int i=0; i<num_faces(m); i++) {
		// 	draw_triangle(&m, i, simple_shader, m.material, buffer, back_buffer, SIZE);
		// }
	}

	double duration = omp_get_wtime() - start;
	printf("render completed in: %lf\n", duration);

	// --- OUTPUT & CLEANUP --- //

	save_img("out.png", buffer, WIDTH, HEIGHT);
	free(buffer);
	free(back_buffer);
	model_group_free(&models);
	return 0; 
}
