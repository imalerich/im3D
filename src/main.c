#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "img.h"

#define IMG_W		800
#define IMG_H		600

int main(int argc, char ** argv) {
	srand(time(NULL));
	uint8_t * buffer = malloc_buffer(IMG_W, IMG_H);

	for (int y=0; y<IMG_H; y++) {
		for (int x=0; x<IMG_W; x++) {
			buffer[CHANNELS * (y*IMG_W + x) + 0] = 256 * x/(float)IMG_W;
			buffer[CHANNELS * (y*IMG_W + x) + 1] = 256 * y/(float)IMG_H;
			buffer[CHANNELS * (y*IMG_W + x) + 2] = 256 * (x*y) / (float)(IMG_W*IMG_H);
		}
	}

	save_img("out.png", buffer, IMG_W, IMG_H);

	return 0;
}
