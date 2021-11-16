/*
 * e16-3.c
 *
 * Esercizio:
 *   Scrivere una funzione
 *
 *     void print_ints(int *values, int n);
 * 
 *   che stampi un array di interi sullo standard output.
 *   Per ogni elemento, stampare l'indice dell'elemento,
 *   il valore dell'elemento, il valore del puntatore all'elemento
 *   (utilizzare lo specificatore di formato %p - che stampa un
 *   puntatore in modo opportuno).
 *
 *   Scrivere la funzione in due modi distinti: la prima versione
 *   deve utilizzare l'operatore di indicizzazione, la seconda versione non può usarlo e deve usare l'operatore di dereferenziamento. Nella seconda versione l'indice dev'essere ottenuto come offset rispetto al puntatore al primo
 *   elemento.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e16-3 e16-3.c
 */

#include <stdio.h>

void print_ints_v1(int *values, int n);
void print_ints_v2(int *values, int n);

void print_ints_v1(int *values, int n)
{
    printf("values array pointer: %p\n", (void *)values);

    printf("values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\tvalues[%d]: %d  ptr:%p\n", i, values[i], (void *)&values[i]);
    }
}

void print_ints_v2(int *values, int n)
{
    printf("values array pointer: %p\n", (void *)values);

    printf("values:\n");
    int *first_ptr = values;
    int *elem_ptr = first_ptr;
    while (1)
    {
        long i = elem_ptr - first_ptr;
        if (i >= n)
            break;
        printf("\tvalues[%ld]: %d  ptr:%p\n", i, *elem_ptr, (void *)elem_ptr);

        elem_ptr++;
    }
}

int main()
{
    int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    printf("VERSION 1\n");
    print_ints_v1(arr, sizeof(arr)/sizeof(arr[0]));

    printf("\n");
    printf("VERSION 2\n");
    print_ints_v2(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
