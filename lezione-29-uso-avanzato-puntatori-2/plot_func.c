/*
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o plot_func plot_func.c -lm
 *
 * run:
 *   $ ./plot_func
 */

#include <stdio.h>
#include <math.h>

#define ROWS 24
#define COLS 78

char display_mem[ROWS][COLS + 1];

void clear(char ch)
{
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            display_mem[r][c] = ch;
        }
        display_mem[r][COLS] = '\0';
    }
}

void display(void)
{
    for (int r = 0; r < ROWS; r++) {
        printf("%s\n", display_mem[r]);
    }
}

void plot_func(double x_min, double x_max, double (*f)(double), char ch)
{
    double x, y;
    double x_step = (x_max - x_min) / (double)COLS;
    for (x = x_min; x < x_max; x += x_step) {
        y = f(x);
        
        int ix = (int) ((x - x_min) / (x_max - x_min) * (double)(COLS - 1));
        if (ix < 0)
            ix = 0;
        if (ix >= COLS)
            ix = COLS - 1;

        int iy = (ROWS - 1) - (int) ((y - -1.0) / (1.0 - -1.0) * (double)(ROWS - 1));
        if (iy < 0)
            iy = 0;
        if (iy >= ROWS)
            iy = ROWS - 1;
        display_mem[iy][ix] = ch;
    }
}


double myf(double x)
{
    if (fabs(x) < 0.01)
        return 1.0;
    return (sin(x)*sin(x)) / (x*x);
}

int main(void)
{
    clear(' ');
    plot_func(-M_PI, M_PI, sin, '*');
    // plot_func(-M_PI, M_PI, cos, 'o');
    plot_func(-7.0, 7.0, myf, '.');
    display();

    return 0;
}
