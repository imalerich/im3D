#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include "point.h"

#define WHITE make_color(255, 255, 255)
#define LIGHT_GRAY make_color(180, 180, 180)
#define DARK_GRAY make_color(80, 80, 80)
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
color_t make_color(uint8_t r, uint8_t g, uint8_t b);

#endif
