#ifndef BUFFER_H
#define BUFFER_H

#include <png.h>
#include <stdint.h>

#define CHANNELS 3

/**
 * Allocates a new image buffer for the given dimmensions.
 * This image will have CHANNELS uint8_t values for each
 * pixel for an RGB encoding.
 */
uint8_t * malloc_buffer(unsigned width, unsigned height);

/**
 * Saves a new png file at the given 'name' using
 * the image stored in 'buffer'. Width & Height
 * should be the dimmensions of the buffer.
 * Buffer is assumed to have 3 channels, RGB.
 */
void save_img(const char * name, uint8_t * buffer, unsigned width, unsigned height);

#endif
