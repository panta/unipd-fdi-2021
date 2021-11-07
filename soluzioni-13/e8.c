/*
 * e8.c
 *
 * Esercizio:
 *   Scrivere una libreria di funzioni che ottengano il valore
 *   minimo, massimo, medio di un array di double. Le funzioni
 *   devono ricevere l'array e la dimensione come parametri.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e8 e8.c
 */

#include <stdio.h>
#include <float.h>

#define MAX_ARRAY_SIZE  100

double array_min(double arr[], int arr_size)
{
    double min_val = DBL_MAX;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    return min_val;
}

double array_max(double arr[], int arr_size)
{
    double max_val = -DBL_MAX;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

double array_avg(double arr[], int arr_size)
{
    double avg_val = 0.0;
    for (int i = 0; i < arr_size; i++)
        avg_val += arr[i];
    return avg_val / (double)arr_size;
}

void array_read_from_stdin(double arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("array[%d]: ", i);
        scanf("%lg", &arr[i]);
    }
}

void array_print(double arr[], int arr_size)
{
    printf("array (%d elements):\n", arr_size);
    for (int i = 0; i < arr_size; i++)
        printf("  array[%d]: %g\n", i, arr[i]);
}

int main(void)
{
    int n;
    double arr[MAX_ARRAY_SIZE];

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

    array_read_from_stdin(arr, n);
    double a_min = array_min(arr, n);
    double a_max = array_max(arr, n);
    double a_avg = array_avg(arr, n);
    printf("min:%g max:%g avg:%g\n", a_min, a_max, a_avg);
}
