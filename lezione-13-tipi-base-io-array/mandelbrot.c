#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/*
 * for an intro to the Mandelbrot set:
 *   - https://simple.wikipedia.org/wiki/Mandelbrot_set
 *
 * for ppm format, see:
 *   - http://netpbm.sourceforge.net/doc/ppm.html
 *
 * install ImageMagick:
 *   debian/ubuntu: apt-get install imagemagick
 *   macos: brew install imagemagick
 *
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o mandelbrot mandelbrot.c
 *
 * run:
 *   $ ./mandelbrot >mandelbrot.ppm && convert mandelbrot.ppm mandelbrot.jpg
 */

/* --------------------------------------------------------------------
 *   MACROS AND CONSTANTS
 * -------------------------------------------------------------------- */

#define WIDTH	12800
#define HEIGHT	10240

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

img_t img;

/* --------------------------------------------------------------------
 *   CODE
 * -------------------------------------------------------------------- */

void set_pixel(img_t img, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	img[RED][y][x]   = r;
	img[GREEN][y][x] = g;
	img[BLUE][y][x]  = b;
}

#define MAX_ITER 100

double complex_sq_abs(double re, double im)
{
	return (re * re) + (im * im);
}

int mandelbrot(double c_re, double c_im)
{
	// z_0 = 0
	// z_{n+1} = (z_n)^2 + c
	// it's in the mandelbrot set if |z_n| < 2 after MAX_ITER

	// |z| = |x+yi| = sqrt(x*x + y*y)
	// (a+bi)(c+di) = ac + adi + bci + bdi^2 = (ac−bd) + (ad+bc)i
	// z^2 = (x+yi)^2 = (x^2-y^2) + (xy+yx)i = (x^2-y^2) + 2xyi

	double z_re = 0.0, z_im = 0.0;
	double z_new_re = 0.0, z_new_im = 0.0;
	int n = 0;
	while (n < MAX_ITER) {
		if (complex_sq_abs(z_re, z_im) > 4.0)
			break;
		// z_{n+1} = (z_n)^2 + c
		z_new_re = ((z_re * z_re) - (z_im * z_im)) + c_re;
		z_new_im = 2 * z_re * z_im + c_im;

		z_re = z_new_re;
		z_im = z_new_im;
		n++;
	}
	return n;
}

int main(void)
{
	double c_start_re = -2.0, c_start_im = -1.0, c_end_re = 1.0, c_end_im = 1.0;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			set_pixel(img, x, y, 255, 255, 255);
		}
	}

	double c_re, c_im;
	for (int y = 0; y < HEIGHT; y++) {
		c_im = c_start_im + ((double)y / (double)HEIGHT) * (c_end_im - c_start_im);

		for (int x = 0; x < WIDTH; x++) {
			c_re = c_start_re + ((double)x / (double)WIDTH) * (c_end_re - c_start_re);

			int m = mandelbrot(c_re, c_im);
			int color = 255 - (int)((double)m * 255.0 / (double)MAX_ITER);
			set_pixel(img, x, y, (uint8_t)color, (uint8_t)color, (uint8_t)color);
		}
	}

	printf("P3\n");
	printf("# mandelbrot.ppm\n");
	printf("%d %d\n", WIDTH, HEIGHT);
	printf("%d\n", 255);
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			printf(" %d %d %d  ", img[RED][y][x], img[GREEN][y][x], img[BLUE][y][x]);
		}
		printf("\n");
	}
}
