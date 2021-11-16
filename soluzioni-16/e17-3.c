/*
 * e17-2.c
 *
 * Esercizio:
 *   Scrivere un programma che per default stampi gli
 *   argomenti ricevuti sulla riga di comando così come
 *   sono, ma che gestisca un flag opzionale con
 *   parametro --case CASE che se specificato fa stampare
 *   in lowercase o uppercase i restanti argomenti a
 *   seconda del valore di CASE.
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e17-3 e17-3.c
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

void print_lower(const char *str)
{
    const char *strp = str;
    char ch;

    while ((ch = *strp++) != '\0')
    {
        putc(tolower(ch), stdout);  // or printf("%c", tolower(ch));
    }
    putc('\n', stdout);             // or printf("\n");
}

#define CASE_AS_IS 0
#define CASE_LOWER 1
#define CASE_UPPER 2

int main(int argc, char *argv[])
{
    int opt_case = CASE_AS_IS;

    for (int i = 1; i < argc; i++)
    {
        if ((strcmp(argv[i], "--case") == 0) && ((i+1) < argc))
        {
            if (strcmp(argv[i+1], "lower") == 0)
                opt_case = CASE_LOWER;
            else if (strcmp(argv[i+1], "upper") == 0)
                opt_case = CASE_UPPER;
            else
                opt_case = CASE_AS_IS;
            i++;
        } else
        {
            switch (opt_case)
            {
            case CASE_LOWER:
                print_lower(argv[i]);
                break;

            case CASE_UPPER:
                print_upper(argv[i]);
                break;

            default:
            case CASE_AS_IS:
                printf("%s\n", argv[i]);
                break;
                break;
            }
        }
    }

    return 0;
}
