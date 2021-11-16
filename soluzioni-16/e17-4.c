/*
 * e17-4.c
 *
 * Esercizio:
 *   Scrivere un programma legga linea per linea dallo
 *   standard input, costruendo una tabella di parole
 *   (sequenza alfabetiche separate da punteggiatura o spazi),
 *   contando quante volte compare ogni parola. Alla fine stampa
 *   tutte le parole distinte trovate con il numero di
 *   occorrenze per ognuna.
 *   Considerare una dimensione massima per le linee in
 *   input (es. 250), un numero massimo di parole distinte
 *   gestibili (es. 1000), ed una lunghezza massima delle
 *   parole (es. 26).
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e17-4 e17-4.c
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* -- CONSTANTS ---------------------------------------------------- */

#define MAX_LINES 250
#define MAX_WORDS 1000
#define MAX_WORD_LEN 26
#define MAX_LINE_LEN 1000

/* -- STRUCT ------------------------------------------------------- */

struct word_freq
{
    char word[MAX_WORD_LEN + 1];
    int freq;
};

struct freq_table
{
    struct word_freq wfreqs[MAX_WORDS];
    int n_words;
};

/* -- PROTOTYPES --------------------------------------------------- */

void init_freq_table(struct freq_table *ft);
void count_words(struct freq_table *ft, const char *line);
void print_counts(const struct freq_table *ft);

/* -- IMPLEMENTATION ----------------------------------------------- */

void init_freq_table(struct freq_table *ft)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        ft->wfreqs[i].word[0] = '\0';
        ft->wfreqs[i].freq = 0;
    }
    ft->n_words = 0;
}

void count_words(struct freq_table *ft, const char *line)
{
    const char *ch_ptr = line;

    while (*ch_ptr)
    {
        // skip everything that is not alphabetic (spaces, punctuation, ...)
        while (!isalpha(*ch_ptr))
            ch_ptr++;

        char word[MAX_WORD_LEN + 1];
        char *word_dst_ptr = word;
        while (isalpha(*ch_ptr))
        {
            *word_dst_ptr++ = *ch_ptr++;
        }
        *word_dst_ptr++ = '\0';     // terminate the string!
        word[MAX_WORD_LEN] = '\0';

        // if no word has been found, try with the next
        if (*word == '\0')
            continue;

        // do we have this word already?
        int word_at = -1;
        for (int i = 0; i < ft->n_words; i++)
        {
            if (strcasecmp(ft->wfreqs[i].word, word) == 0)
            {
                // yes
                word_at = i;
                break;
            }
        }

        if (word_at < 0)
        {
            // no, we have to add it

            if (ft->n_words >= MAX_WORDS) {
                // too bad we already reached our max number of words!
            } else {
                word_at = ft->n_words++;
                strncpy(ft->wfreqs[word_at].word, word, MAX_WORD_LEN);
                ft->wfreqs[word_at].freq = 0;
            }
        } else {
            // yes, the word is already in our "db", at position `word_at`
        }

        if (word_at >= 0)
        {
            // now we have the word at `word_at` position for sure, increment the counter
            ft->wfreqs[word_at].freq++;
        }
    }
}

void print_counts(const struct freq_table *ft)
{
    for (int i = 0; i < ft->n_words; i++)
    {
        printf("%s: %d\n", ft->wfreqs[i].word, ft->wfreqs[i].freq);
    }
}

int main()
{
    struct freq_table ft;

    init_freq_table(&ft);

    char line[MAX_LINE_LEN + 1];
    while (gets(line) != NULL)
    {
        // it's better to terminate just to be safe (line has MAX_LINE_LEN + 1 characters)
        line[MAX_LINE_LEN] = '\0';

        count_words(&ft, line);
    }

    print_counts(&ft);

    return 0;
}
