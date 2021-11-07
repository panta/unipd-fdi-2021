/*
 * e9.c
 *
 * Esercizio:
 *   Scrivere un programma che conti il numero di valori
 *   duplicati in un array. L'array in input può contenere
 *   valori interi tra 0 e 100. Il programma non deve usare altri array.
 *
 * Esempio:
 *
 *   int arr[] = { 12, 1, 94, 5, 12, 7, 0, 5, 5, 10 };
 *
 *   output:
 *     # elementi duplicati: 5
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e9 e9.c
 */

#include <stdio.h>

#define EXAMINED    -999999

int main(void)
{
    int arr[] = { 12, 1, 94, 5, 12, 7, 0, 5, 5, 10 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int duplicates = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == EXAMINED)
            continue;                                   // se l'abbiamo esaminato, saltalo

        int duplicates_for_i = 0;
        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicates_for_i++;
                arr[j] = EXAMINED;                      // marca come esaminato
            }
        }

        if (duplicates_for_i > 0)
            duplicates += (1 + duplicates_for_i);       // numero di duplicati più 1 per l'originale
    }

    printf("# elementi duplicati: %d\n", duplicates);
}
