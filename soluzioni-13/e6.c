/*
 * e6.c
 *
 * Esercizio:
 *   Scrivere un programma che richieda all'utente i coefficienti
 *   di un equazione di secondo grado della forma:
 *      a*x^2 + b*x + c = 0
 *   e che calcoli e visualizzi le radici reali (se presenti).
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e6 e6.c -lm
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;

    printf("Immettere di seguito i coefficienti di a*x^2 + b*x + c = 0\n");
    printf("a: ");
    scanf("%lg", &a);
    printf("b: ");
    scanf("%lg", &b);
    printf("c: ");
    scanf("%lg", &c);

    printf("\n");
    printf("Equazione: %g * x^2 + %g * x + %g = 0\n", a, b, c);
    printf("\n");

    double delta = b * b - 4.0 * a * c;
    if (delta < 0)
    {
        printf("Non ci sono soluzioni reali.\n");
    } else
    {
        printf("Soluzioni:\n");
        double x1 = (-b - sqrt(delta)) / (2.0 * a);
        double x2 = (-b + sqrt(delta)) / (2.0 * a);
        printf("  x1: %g\n", x1);
        printf("  x2: %g\n", x2);
    }
}
