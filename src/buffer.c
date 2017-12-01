#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "buffer.h"

uint8_t * malloc_buffer(unsigned width, unsigned height) {
	return malloc(sizeof(uint8_t) * width * height * CHANNELS);
}

float * malloc_back_buffer(unsigned width, unsigned height) {
	float * buffer = malloc(sizeof(float) * width * height);
	for (int i=0; i<width*height; i++) { buffer[i] = -FLT_MAX; }
	return buffer;
}

void save_img(const char * name, uint8_t * buffer, unsigned width, unsigned height) {
	FILE * fp;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	size_t x, y;
	png_byte ** row_pointers = NULL;

	int pixel_size = CHANNELS;
	int depth = 8;

	/* --- Initialize --- */
	fp = fopen(name, "wb");
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);
	png_set_IHDR(png_ptr, info_ptr, width, height, depth, PNG_COLOR_TYPE_RGB,
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	/* --- Initialize Rows --- */
	row_pointers = png_malloc(png_ptr, height * sizeof(png_byte *));
	for (y = 0; y < height; y++) {
		png_byte * row = png_malloc(png_ptr, sizeof(uint8_t) * width * pixel_size);
		row_pointers[y] = row;
		for (x = 0; x < width; x++) {
			*row++ = buffer[CHANNELS * (y*width + x) + 0];
			*row++ = buffer[CHANNELS * (y*width + x) + 1];
			*row++ = buffer[CHANNELS * (y*width + x) + 2];
		}
	}

	/* --- Write Data --- */
	png_init_io(png_ptr, fp);
	png_set_rows(png_ptr, info_ptr, row_pointers);
	png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

	/* --- Cleanup --- */
	for (y = 0; y < height; y++) {
		png_free(png_ptr, row_pointers[y]);
	}

	png_free(png_ptr, row_pointers);
	png_destroy_write_struct(&png_ptr, &info_ptr);
	fclose(fp);
}
