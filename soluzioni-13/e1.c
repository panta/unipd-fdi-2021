/*
 * e1.c
 *
 * Esercizio:
 *   Scrivere un programma che copi l'input sull'output,
 *   sostituendo ogni tab con "\t", ogni backspace con "\b",
 *   ogni backslash con "\\" (questo rende visibili tab e backspace).
 * 
 *   NOTA: qui sopra per "\t" non si intente la sequenza di escape
 *   corrispondente ad un carattere TAB, ma proprio la sequenza di
 *   due lettere "backslash-t" nell'output. Idem per gli altri.
 */

#include <stdio.h>

int main(void)
{
    int ch;

    while (1)
    {
        ch = getchar();
        if (ch == EOF)
            break;
        
        switch (ch)
        {
        case '\t':
            putchar('\\');
            putchar('t');
            break;
        
        case '\b':
            putchar('\\');
            putchar('b');
            break;

        case '\\':
            putchar('\\');
            putchar('\\');
            break;

        default:
            putchar(ch);
            break;
        }
    }
}
