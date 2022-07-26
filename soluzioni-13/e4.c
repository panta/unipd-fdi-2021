/*
 * e4.c
 *
 * Esercizio:
 *   Scrivere un programma che conti e visualizzi il numero di
 *   parole nell'input (una parola è una sequenza di soli
 *   caratteri alfabetici e separata da spazi o punteggiatura -
 *   "C'era una volta" contiene 4 parole, "h@x0r" e "1337" non
 *   contano come parole).
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e4 e4.c
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int n_words = 0;
    bool in_word = false;

    int ch;

    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;

        if (isalpha(ch)) {
            if (!in_word) {
                /* stiamo iniziando una nuova parola */
                in_word = true;
                n_words++;
            }
        } else {
            in_word = false;
        }
    }

    printf("parole: %d\n", n_words);
}
