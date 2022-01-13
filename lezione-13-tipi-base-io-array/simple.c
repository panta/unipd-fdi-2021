/*
 * Compile with:
 *   gcc -std=c89 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o simple simple.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double sum_of_squares(double x, double y)
{
	return x*x + y*y;
}

void greet_the_world(void)
{
	printf("Hello, World!\n");
}

int main(void)
{
	greet_the_world();

	{
		double c = 2.0;
		printf("length of <2, 1>: %g\n", sqrt(sum_of_squares(c, 1.0)));
	}
}
