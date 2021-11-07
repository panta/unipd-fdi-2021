/*
 * e2-v2.c
 *
 * Esercizio:
 *   Scrivere un programma che copi l'input sull'output,
 *   sostituendo ogni sequenza di uno o più spazi con uno spazio singolo.
 * 
 * Soluzione 2:
 *   Questa soluzione risolve in maniera meno letterale l'esercizio, sostituendo
 *   le sequenze di spazi qualunque con un carattere uguale al primo carattere di
 *   spaziatura della sequenza.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e2-v2 e2-v2.c
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
            /* consumiamo tutti gli spazi, ma stampiamo (solo) il primo */

            int ch2;

            /* consuma tutti gli spazi della sequenza */
            while (((ch2 = getchar()) != EOF) && isspace(ch2))
                /* NOP */ ;

            /*
             * quando usciamo dal ciclo interno abbiamo un "non-spazio", quindi
             * dobbiamo stamparlo, dopo aver stampato l'unico carattere di spaziatura.
             */

            putchar(ch);        // carattere di spaziatura iniziale (unico stampato)

            if (ch2 == EOF)     // fine input: esci
                exit(0);

            putchar(ch2);       // ultimo carattere letto (non-spazio)

            /* ripartiamo dall'iterazione successiva del ciclo principale */
            continue;
        }

        /* qui siamo nel caso in cui il carattere letto non è uno spazio */
        putchar(ch);
    }
}
