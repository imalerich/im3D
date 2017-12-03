#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "buffer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

uint8_t * malloc_buffer(unsigned width, unsigned height) {
	return malloc(sizeof(uint8_t) * width * height * CHANNELS);
}

float * malloc_back_buffer(unsigned width, unsigned height) {
	float * buffer = malloc(sizeof(float) * width * height);
	for (int i=0; i<width*height; i++) { buffer[i] = FLT_MAX; }
	return buffer;
}

void save_img(const char * name, uint8_t * buffer, unsigned width, unsigned height) {
	stbi_write_png(name, width, height, CHANNELS, buffer, sizeof(uint8_t) * CHANNELS * width);
}

image_t load_img(const char * name) {
	image_t ret;
	int channels; // will be the number of channels actually present in the image
	unsigned char * data = stbi_load(name, &ret.width, &ret.height, &channels, CHANNELS);
	if (data == NULL) {
		fprintf(stderr, "ERROR - Failed to load texture data.\n");
		fflush(stderr);
		exit(1);
	}

	ret.data = malloc(sizeof(uint8_t) * CHANNELS * ret.width * ret.height);
	// copy all data into ret.data, but convert from unsigned char to uint8_t
	for (int i=0; i<CHANNELS * ret.width * ret.height; i++) { ret.data[i] = (uint8_t)data[i]; }
	free(data); // we don't need this buffer anymore
	return ret;
}

void free_img(image_t * img) {
	free(img->data);
	img->data = NULL;
}

vector_t sample_nearest(image_t img, float x, float y) {
	// pick nearest and bind to rand -(width, height) to (width, height)
	int _x = (int)round(x * img.width) % img.width;
	int _y = (int)round(y * img.height) % img.height;
	// // make sure we get something positive
	_x = (_x + img.width) % img.width;
	_y = (_y + img.width) % img.width;
	// convert to the absolute index into our texture buffer
	int idx = (_y * img.width + _x) * CHANNELS; 

	return make_vector(
		(float)img.data[idx+0] / 255.0f,
		(float)img.data[idx+1] / 255.0f,
		(float)img.data[idx+2] / 255.0f,
		1.0f
	);
}
