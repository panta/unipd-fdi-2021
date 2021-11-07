/*
 * e3.c
 *
 * Esercizio:
 *   Scrivere un programma che conti e visualizzi il numero di spazi e di
 *   linee nell'input.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e3 e3.c
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int n_spaces = 0;
    int n_lines = 0;

    int ch;

    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;

        /* NOTA: un newline è (anche) un carattere di spaziatura, va contato anche tra gli spazi! */
        if (ch == '\n')
            n_lines++;

        if (isspace(ch))
            n_spaces++;
    }

    printf("spazi: %d\n", n_spaces);
    printf("linee: %d\n", n_lines);
}
