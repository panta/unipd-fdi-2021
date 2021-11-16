/*
 * e16-2.c
 *
 * Esercizio:
 *   Scrivere una funzione
 *
 *     int solve2(double a, double b, double c, double *x1_p, double *x2_p);
 *
 *   che risolva un'equazione di secondo grado della forma
 *
 *     ax2 + bx + c = 0
 *
 *   e che restituisca le radici reali (se presenti) tramite i due puntatori x1_p e x2_p. La funzione
 *   ritorna il numero di radici reali trovate (0, 1, 2).
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e16-2 e16-2.c -lm
 */

#include <stdio.h>
#include <math.h>

int solve2(double a, double b, double c, double *x1_p, double *x2_p);

int solve2(double a, double b, double c, double *x1_p, double *x2_p)
{
    double delta = b*b - 4.0 * a * c;

    if (delta < 0)
    {
        // delta < 0: no real solutions found
        return 0;
    }

    // delta >= 0
    double x1 = (-b - sqrt(delta)) / (2.0 * a);
    double x2 = (-b + sqrt(delta)) / (2.0 * a);

    if (x1_p)
        *x1_p = x1;
    if (x2_p)
        *x2_p = x2;
    return (delta > 0) ? 2 : 1;
}

int main()
{
    double a, b, c;

    printf("Immettere i coefficienti a, b, c dell'equazione ax^2+bx+c = 0\n");
    printf("a:");
    scanf("%lf", &a);
    printf("b:");
    scanf("%lf", &b);
    printf("c:");
    scanf("%lf", &c);

    double x1, x2;
    int n_solutions = solve2(a, b, c, &x1, &x2);

    if (n_solutions <= 0)
    {
        printf("non ci sono soluzioni reali\n");
    } else
    {
        printf("%d soluzione/i:\n", n_solutions);
        if (n_solutions == 1)
            printf("\tx1,2: %g\n", x1);
        else
            printf("\tx1:%g x2:%g\n", x1, x2);
    }

    return 0;
}
