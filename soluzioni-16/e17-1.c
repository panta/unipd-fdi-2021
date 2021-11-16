/*
 * e17-1.c
 *
 * Esercizio:
 *   Scrivere un programma che stampi in uppercase gli
 *   argomenti ricevuti sulla riga di comando.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e17-1 e17-1.c
 */

#include <stdio.h>
#include <ctype.h>

void print_upper(const char *str)
{
    const char *strp = str;
    char ch;

    while ((ch = *strp++) != '\0')
    {
        putc(toupper(ch), stdout);  // or printf("%c", toupper(ch));
    }
    putc('\n', stdout);             // or printf("\n");
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        print_upper(argv[i]);
    }

    return 0;
}
