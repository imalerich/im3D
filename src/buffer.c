#include <stdlib.h>
#include <stdio.h>
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
	clear_back_buffer(buffer, width, height);
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
	int _y = (int)round(-y * img.height) % img.height;
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

vector_t sample_linear(image_t img, float x, float y) {
	float _fx = floor(x * img.width) / img.width;
	float _fy = floor(y * img.height) / img.height;
	float _cx = ceil(x * img.width) / img.width;
	float _cy = ceil(y * img.height) / img.height;

	vector_t fxfy = sample_nearest(img, _fx, _fy);
	vector_t fxcy = sample_nearest(img, _fx, _cy);
	vector_t cxfy = sample_nearest(img, _cx, _fy);
	vector_t cxcy = sample_nearest(img, _cx, _cy);

	// vertical scalar, this represents the percentage of fy to use
	float vert_s = ceil(y) - y;

	vector_t fx = vec_add(vec_scale(fxfy, vert_s), vec_scale(fxcy, 1.0 - vert_s));
	vector_t cx = vec_add(vec_scale(cxfy, vert_s), vec_scale(cxcy, 1.0 - vert_s));

	// horizontal scalar this represents the percentage of fx to use
	float horiz_s = ceil(x) - x;
	return vec_add(vec_scale(fx, horiz_s), vec_scale(cx, 1.0 - horiz_s));
}
