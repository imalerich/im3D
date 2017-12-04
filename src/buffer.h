#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <float.h>
#include "point.h"

#define CHANNELS 3
#define EMPTY_IMG {0, 0, NULL}

typedef struct image {
	int width;
	int height;
	uint8_t * data;
} image_t;

/**
 * Allocates a new image buffer for the given dimensions.
 * This image will have CHANNELS uint8_t values for each
 * pixel for an RGB encoding.
 */
uint8_t * malloc_buffer(unsigned width, unsigned height);

/**
 * Allocates a new back buffer for the given dimensions.
 * This will allocate an array of width*height floating point values.
 */
float * malloc_back_buffer(unsigned width, unsigned height);

/**
 * Clear the input back buffer to FLT_MAX.
 */
static inline void clear_back_buffer(float * buffer, unsigned width, unsigned height) {
	for (int i=0; i<width*height; i++) { buffer[i] = FLT_MAX; }
}

/**
 * Saves a new png file at the given 'name' using
 * the image stored in 'buffer'. Width & Height
 * should be the dimmensions of the buffer.
 * Buffer is assumed to have 3 channels, RGB.
 */
void save_img(const char * name, uint8_t * buffer, unsigned width, unsigned height);

/**
 * Loads an image from the input file. Image will be forced
 * to use CHANNELS. The image loading library used by this 
 * method loads into 'unsigned char', on most systems, this
 * is equivalent to uint8_t used by my code, however this
 * method will explicitly convert between the two.
 */
image_t load_img(const char * name);

/**
 * Free data associated with the input image.
 */
void free_img(image_t * img);

/**
 * Given two input texture coordinates x and y (normalized), scale
 * them by the image size then round them to their
 * nearest integer values, then sample data from the input image.
 * The texture will tile for out of bound indecies.
 * Return the sampled color in vector format.
 */
vector_t sample_nearest(image_t img, float x, float y);

/**
 * Produces 4 samples using sample_nearest and the floor/ceil
 * of x and y. Then interpolates those 4 values based on x and y
 * for smoother texture mapping.
 */
vector_t sample_linear(image_t img, float x, float y);

#endif
