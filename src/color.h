#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include "point.h"

#define WHITE make_color(255, 255, 255)
#define LIGHT_GRAY make_color(180, 180, 180)
#define DARK_GRAY make_color(20, 20, 20)
#define BLACK make_color(0, 0, 0)

#define RED make_color(255, 0, 0)
#define GREEN make_color(0, 255, 0)
#define BLUE make_color(0, 0, 255)

#define MAGENTA make_color(255, 0, 255)
#define CYAN make_color(0, 255, 255)
#define YELLOW make_color(255, 255, 0)

typedef struct color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} color_t;

/*
 * Function initializer for the color type.
 */
static inline color_t make_color(uint8_t r, uint8_t g, uint8_t b) {
	return (color_t){r, g, b};
}

/**
 * Converts the vector data type to an integer color type.
 */
static inline color_t vector_to_color(vector_t v) {
	return (color_t){(uint8_t)(v.x * 255), (uint8_t)(v.y * 255), (uint8_t)(v.z * 255)};
}

#endif
