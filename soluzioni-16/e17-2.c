/*
 * e17-2.c
 *
 * Esercizio:
 *   Scrivere un programma che per default stampi gli
 *   argomenti ricevuti sulla riga di comando così come
 *   sono, ma che gestisca un flag opzionale --upper che
 *   se specificato fa stampare in uppercase i restanti argomenti.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e17-2 e17-2.c
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    int flag_upper = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--upper") == 0)
        {
            flag_upper = 1;
        } else
        {
            if (flag_upper)
                print_upper(argv[i]);
            else
                printf("%s\n", argv[i]);
        }
    }

    return 0;
}
