/*
 * e10.c
 *
 * Esercizio:
 *   Scrivere un programma che calcoli la frequenza con cui
 *   compare ogni elemento di un array. Il programma può
 *   usare altri array.
 *
 * Esempio:
 *
 *   int arr[] = { 12, 1, 94, 5, 12, 7, 0, 5, 5, 10 };
 *
 *   output:
 *     12 compare 2 volta/e
 *     1 compare 1 volta/e
 *     ...
 *     5 compare 3 volta/e
 *     ...
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e10 e10.c
 */

#include <stdio.h>

#define EXAMINED    -999999

int main(void)
{
    int arr[] = { 12, 1, 94, 5, 12, 7, 0, 5, 5, 10 };
    int count[100] = {0};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == EXAMINED)
            continue;                                   // se l'abbiamo esaminato, saltalo

        count[i] = 1;

        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[i] == arr[j])
            {
                count[i]++;
                arr[j] = EXAMINED;                      // marca come esaminato
            }
        }
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (count[i] > 0)
        {
            printf("%d compare %d volta/e\n", arr[i], count[i]);
        }
    }
}
