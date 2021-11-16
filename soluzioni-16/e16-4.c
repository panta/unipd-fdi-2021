/*
 * e16-4.c
 *
 * Esercizio:
 *   Scrivere un programma che determini la dimensione
 *   di un char usando l'aritmetica dei puntatori, senza
 *   cioè usare direttamente sizeof.
 *
 *   Ripetere per int, int, long, float e double.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e16-4 e16-4.c
 */

#include <stdio.h>

int main()
{
    char v_char;

    char *ch_ptr_1 = &v_char;
    char *ch_ptr_2 = ch_ptr_1 + 1;
    printf("size of char: %ld\n", (unsigned long)ch_ptr_2 - (unsigned long)ch_ptr_1);


    short v_short;
    short *short_ptr_1 = &v_short;
    short *short_ptr_2 = short_ptr_1 + 1;
    printf("size of short: %ld\n", (unsigned long)short_ptr_2 - (unsigned long)short_ptr_1);

    int v_int;
    int *int_ptr_1 = &v_int;
    int *int_ptr_2 = int_ptr_1 + 1;
    printf("size of int: %ld\n", (unsigned long)int_ptr_2 - (unsigned long)int_ptr_1);

    long v_long;
    long *long_ptr_1 = &v_long;
    long *long_ptr_2 = long_ptr_1 + 1;
    printf("size of long: %ld\n", (unsigned long)long_ptr_2 - (unsigned long)long_ptr_1);

    float v_float;
    float *float_ptr_1 = &v_float;
    float *float_ptr_2 = float_ptr_1 + 1;
    printf("size of float: %ld\n", (unsigned long)float_ptr_2 - (unsigned long)float_ptr_1);

    double v_double;
    double *double_ptr_1 = &v_double;
    double *double_ptr_2 = double_ptr_1 + 1;
    printf("size of double: %ld\n", (unsigned long)double_ptr_2 - (unsigned long)double_ptr_1);

    return 0;
}
