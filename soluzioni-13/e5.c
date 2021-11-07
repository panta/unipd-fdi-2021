/*
 * e5.c
 *
 * Esercizio:
 *   Scrivere un programma che stampi una tabella di conversione
 *   tra km e miglia, per i km tra 0 e 200 (inclusi) ogni 10.
 *   I km devono essere allineati a dx (senza decimali) e le
 *   miglia a sx (con un decimale). Includere una riga di intestazione.
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e5 e5.c
 */

#include <stdio.h>

#define MILES_PER_KM 0.62137119
#define KM_LO   0
#define KM_HI   200
#define KM_STEP 10

int main(void)
{
    int km;

    printf("%5s | %-6s\n", "KM", "MILES");
    printf("%5s-+-%-6s\n", "-----", "------");
    for (km = KM_LO; km <= KM_HI; km += KM_STEP)
    {
        double miles = (double)km * MILES_PER_KM;

        printf("%5d | %-6.1f\n", km, miles);
    }
}
