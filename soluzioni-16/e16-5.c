/*
 * e16-5.c
 *
 * Esercizio:
 *   Implementare una funzione
 *
 *     int scan_int(int *nump);
 * 
 *   che legga un numero intero decimale (con eventuale segno)
 *   dallo standard input, saltando eventuali caratteri di
 *   spaziatura iniziali, e ritorni il numero letto tramite il puntatore nump.
 *
 *   La funzione ritorna 0 in caso di errore e 1 in caso di successo. 
 *   Per leggere dallo standard input la funzione utilizza
 *   getchar() per leggere un carattere e ungetc() per rimettere un
 *   carattere letto sullo standard input.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e16-5 e16-5.c
 */

#include <stdio.h>
#include <ctype.h>

int scan_int(int *nump);

int scan_int(int *nump)
{
    int sign = 1;
    int value = 0;

    // salta spazi
    int ch;
    do {
        ch = getchar();
        if (ch == EOF)
            return 0;
    } while (isspace((char)ch));
    ungetc(ch, stdin);

    // leggi eventuale segno
    ch = getchar();
    if (ch == EOF)
        return 0;
    if (ch == (int)'-')
        sign = -1;
    else
    {
        sign = 1;
        ungetc(ch, stdin);
    }

    // leggi parte intera
    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;
        if (isdigit((char)ch))
        {
            value = (value * 10) + ((char)ch - '0');
        } else
        {
            ungetc(ch, stdin);
            break;
        }
    }
    value = sign * value;

    if (nump)
        *nump = value;
    return 1;
}

int main()
{
    printf("Immettere una sequenza di numeri interi: ");
    int value;
    while(scan_int(&value))
    {
        printf("letto %d\n", value);
    }

    printf("FINE\n");

    return 0;
}
