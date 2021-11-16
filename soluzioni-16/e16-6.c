/*
 * e16-6.c
 *
 * Esercizio:
 *   Implementare una funzione
 *
 *     int scan_double(double *nump);
 * 
 *   che legga un numero razionale decimale (con eventuale segno)
 *   dallo standard input, saltando eventuali caratteri di
 *   spaziatura iniziali, e ritorni il numero letto tramite il puntatore nump.
 *
 *   La funzione ritorna 0 in caso di errore e 1 in caso di successo. 
 *   Per leggere dallo standard input la funzione utilizza
 *   getchar() per leggere un carattere e ungetc() per rimettere un
 *   carattere letto sullo standard input.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e16-6 e16-6.c
 */

#include <stdio.h>
#include <ctype.h>

int scan_double(double *nump);

int scan_double(double *nump)
{
    double sign = 1.0;
    double value = 0;

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
        sign = -1.0;
    else
    {
        sign = 1.0;
        ungetc(ch, stdin);
    }

    // leggi parte intera
    int int_value = 0;
    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;
        if (isdigit((char)ch))
        {
            int_value = (int_value * 10) + ((char)ch - '0');
        } else
        {
            ungetc(ch, stdin);
            break;
        }
    }

    value = sign * (double)int_value;

    // leggi punto decimale
    ch = getchar();
    if (ch != (int)'.')
    {
        if (nump)
            *nump = value;
        return 1;
    }

    // letto il punto, leggiamo la parte frazionaria
    long frac_value = 0;
    double frac_divisor = 1.0;
    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;
        if (isdigit((char)ch))
        {
            frac_value = (frac_value * 10) + ((char)ch - '0');
            frac_divisor *= 10.0;
        } else
        {
            ungetc(ch, stdin);
            break;
        }
    }

    value = value + sign * (double)frac_value / frac_divisor;

    if (nump)
        *nump = value;
    return 1;
}

int main()
{
    printf("Immettere una sequenza di numeri razionali: ");
    double value;
    while(scan_double(&value))
    {
        printf("letto %f\n", value);
    }

    printf("FINE\n");

    return 0;
}
