/*
 * e16-1.c
 *
 * Esercizio:
 *   Implementare una funzione
 * 
 *     void swap_int(int *a_p, int *b_p);
 * 
 *   che scambi due interi, tramite il passaggio di puntatori.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e16-1 e16-1.c
 */

#include <stdio.h>

void swap_int(int *a_p, int *b_p);

void swap_int(int *a_p, int *b_p)
{
    if (a_p && b_p) {
        int tmp_a = *a_p;

        *a_p = *b_p;
        *b_p = tmp_a;
    }
}

int main()
{
    int v1 = 11;
    int v2 = 99;

    printf("{1} v1:%d v2:%d\n", v1, v2);

    swap_int(&v1, &v2);

    printf("{2} v1:%d v2:%d\n", v1, v2);

    return 0;
}
