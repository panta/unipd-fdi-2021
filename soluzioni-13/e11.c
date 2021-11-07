/*
 * e11.c
 *
 * Esercizio:
 *   Scrivere una libreria di funzioni per gestire matrici in doppia
 *   precisione (double) 2x2 o 3x3. Includere funzioni per
 *   inizializzare una matrice a zero e alla matrice identità
 *   (diagonale a 1.0), trasporre una matrice, sommare e sottrarre
 *   due matrici, moltiplicare due matrici (prodotto righe per colonne).
 * 
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e11 e11.c
 */

#include <stdio.h>
#include <math.h>

#define MAT_SIDE 3

typedef double m3x3_t[MAT_SIDE][MAT_SIDE];

// m3_print() stampa la matrice m.
void m3_print(const m3x3_t m)
{
    // vogliamo stampare nella forma
    // [ RIGA0, RIGA1, ..., ]
    // dove RIGA_i := [ ..., ..., ... ]

    printf("[ ");
    for (int r = 0; r < MAT_SIDE; r++)
    {
        printf("[ ");
        for (int c = 0; c < MAT_SIDE; c++)
        {
            printf("%g%s", m[r][c], ((c+1) < MAT_SIDE) ? ", " : "");
        }
        printf(" ]%s", ((r+1) < MAT_SIDE) ? ", " : "");
    }
    printf(" ]\n");
}

// m3_zero() azzera la matrice m.
void m3_zero(m3x3_t m)
{
    for (int r = 0; r < MAT_SIDE; r++)
    {
        for (int c = 0; c < MAT_SIDE; c++)
        {
            m[r][c] = 0.0;
        }
    }
}

// m3_one() imposta la matrice m alla matrice identità.
void m3_one(m3x3_t m)
{
    for (int r = 0; r < MAT_SIDE; r++)
    {
        for (int c = 0; c < MAT_SIDE; c++)
        {
            m[r][c] = (r == c) ? 1.0 : 0.0;
        }
    }
}

// m3_transpose() calcola e memorizza in res la trasposta della matrice m.
void m3_transpose(m3x3_t res, const m3x3_t m)
{
    for (int r = 0; r < MAT_SIDE; r++)
    {
        for (int c = 0; c < MAT_SIDE; c++)
        {
            res[c][r] = m[r][c];
        }
    }
}

// m3_add() calcola e memorizza in res la somma a + b delle matrici a e b.
void m3_add(m3x3_t res, const m3x3_t a, const m3x3_t b)
{
    for (int r = 0; r < MAT_SIDE; r++)
    {
        for (int c = 0; c < MAT_SIDE; c++)
        {
            res[r][c] = a[r][c] + b[r][c];
        }
    }
}

// m3_sub() calcola e memorizza in res la differenza a - b.
void m3_sub(m3x3_t res, const m3x3_t a, const m3x3_t b)
{
    for (int r = 0; r < MAT_SIDE; r++)
    {
        for (int c = 0; c < MAT_SIDE; c++)
        {
            res[r][c] = a[r][c] - b[r][c];
        }
    }
}

// m3_mul() calcola e memorizza in res la matrice prodotto riga per colonna delle matrici a e b.
void m3_mul(m3x3_t res, const m3x3_t a, const m3x3_t b)
{
    for (int r = 0; r < MAT_SIDE; r++)
    {
        for (int c = 0; c < MAT_SIDE; c++)
        {
            res[r][c] = 0.0;
            for (int k = 0; k < MAT_SIDE; k++)
            {
                res[r][c] += a[r][k] * b[k][c];
            }
        }
    }
}

int main(void)
{
    m3x3_t zero, one;

    m3_zero(zero);
    m3_one(one);

    printf("zero:\n");
    m3_print(zero);

    printf("one:\n");
    m3_print(one);

    m3x3_t two;
    m3_add(two, one, one);
    printf("two:\n");
    m3_print(two);

    m3x3_t m1 = { { 0, 1.1, 0}, { 2, 0, 3}, { 5, 1, 0} };
    m3x3_t m1t;
    m3_transpose(m1t, m1);
    printf("m1:\n");
    m3_print(m1);
    printf("m1t:\n");
    m3_print(m1t);

    m3x3_t m2;
    m3_mul(m2, m1, two);
    printf("m2:\n");
    m3_print(m2);
}
