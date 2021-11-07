/*
 * e7.c
 *
 * Esercizio:
 *   Scrivere una funzione che inizializzi un array di interi o
 *   floating point con valori letti dallo standard input tramite
 *   scanf(). La funzione deve ricevere l'array e la dimensione come parametri.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e7 e7.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE  100

void array_read_from_stdin(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void array_print(int arr[], int arr_size)
{
    printf("array (%d elements):\n", arr_size);
    for (int i = 0; i < arr_size; i++)
        printf("  array[%d]: %d\n", i, arr[i]);
}

int main(void)
{
    int n;
    int a[MAX_ARRAY_SIZE];

    printf("Immettere la dimensione dell'array: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("ERRORE: la dimensione non può essere negativa!\n");
        return 1;
    } else if (n > MAX_ARRAY_SIZE)
    {
        printf("ERRORE: la dimensione non può essere maggiore di %d\n", MAX_ARRAY_SIZE);
        return 1;
    }

    array_read_from_stdin(a, n);
    array_print(a, n);
}
