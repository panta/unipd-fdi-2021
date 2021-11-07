/*
 * e2-v1.c
 *
 * Esercizio:
 *   Scrivere un programma che copi l'input sull'output,
 *   sostituendo ogni sequenza di uno o più spazi con uno spazio singolo.
 * 
 * Soluzione 1:
 *   Questa soluzione risolve in maniera letterale l'esercizio, sostituendo
 *   le sequenze di spazi qualunque (spazio, tab, tab verticale, newline, ...)
 *   con un carattere spazio ' '.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e2-v1 e2-v1.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;

    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;
        
        if (isspace(ch))
        {
            /* stampa solo uno spazio per tutta la sequenza */
            putchar(' ');

            /* consuma tutti gli spazi della sequenza */
            while (isspace(ch))
            {
                ch = getchar();
                if (ch == EOF)
                    exit(0);
            }

            /* quando usciamo dal ciclo abbiamo un "non-spazio", quindi dobbiamo stamparlo */
            putchar(ch);

            /* ripartiamo dall'iterazione successiva del ciclo principale */
            continue;
        }

        /* qui siamo nel caso in cui il carattere letto non è uno spazio */
        putchar(ch);
    }
}
