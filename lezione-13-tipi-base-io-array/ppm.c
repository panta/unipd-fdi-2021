#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
 * for ppm format, see:
 *   - http://netpbm.sourceforge.net/doc/ppm.html
 *
 * install ImageMagick:
 *   debian/ubuntu: apt-get install imagemagick
 *   macos: brew install imagemagick
 *
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o ppm ppm.c
 *
 * run:
 *   $ ./ppm >image.ppm && convert image.ppm image.jpg
 */

/* --------------------------------------------------------------------
 *   MACROS AND CONSTANTS
 * -------------------------------------------------------------------- */

#define WIDTH	640
#define HEIGHT	480

/* --------------------------------------------------------------------
 *   TYPES
 * -------------------------------------------------------------------- */

typedef enum {
	RED = 0,
	GREEN = 1,
	BLUE = 2,
} ch_t;

typedef uint8_t img_channel_t[HEIGHT][WIDTH];
typedef img_channel_t img_t[3];


/* --------------------------------------------------------------------
 *   CODE
 * -------------------------------------------------------------------- */

void set_pixel(img_t img, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	img[RED][y][x]   = r;
	img[GREEN][y][x] = g;
	img[BLUE][y][x]  = b;
}

int main(void)
{
	img_t img;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			set_pixel(img, x, y, 255, 255, 255);
		}
	}

	for (double radius = 0; radius < 60.0; radius += 0.2) {
		for (double d = 0; d < 360.0; d += 1.0) {
			double r = d / 180.0 * M_PI;
			double x = (WIDTH / 2.0) + radius * cos(r);
			double y = (HEIGHT / 2.0) - radius * sin(r);
			set_pixel(img, (int)x, (int)y,
				(uint8_t) ((d / 360.0) * 250.0),
				(uint8_t) (250.0 - ((d / 360.0) * 250.0)),
				(uint8_t) ((d / 360.0) * 250.0));
		}
	}
	printf("P3\n");
	printf("# image.ppm\n");
	printf("%d %d\n", WIDTH, HEIGHT);
	printf("%d\n", 255);
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			printf(" %d %d %d  ", img[RED][y][x], img[GREEN][y][x], img[BLUE][y][x]);
		}
		printf("\n");
	}
}
