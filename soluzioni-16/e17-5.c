/*
 * e17-5.c
 *
 * Esercizio:
 *   Implementare la funzione:
 * 
 *     size_t strlcpy(char *dst, const char *src, size_t dst_size);
 *
 *   che:
 *     – copia la stringa src in dst, che ha dimensione dst_size, copiando al più
 *       dst_size - 1 caratteri
 *     – termina sempre la stringa dst con NUL (tranne quando dst_size == 0)
 *     – ritorna la lunghezza totale di src (eq. a strlen(src)).
 * 
 *   Verificarne il corretto funzionamento nei casi:
 *     – dst ha dimensione 0
 *     – dst ha dimensione 1
 *     – src è più corta / più lunga / ha la stessa lunghezza della dimensione di dst
 *
 * Compilare con:
 *   gcc -std=c99 -Wall -Wextra -Wstrict-prototypes -Wconversion -Werror -o e17-5 e17-5.c
 */

#include <stdio.h>

size_t strlcpy(char *dst, const char *src, size_t dst_size);
size_t mystrlen(const char *str);

size_t strlcpy(char *dst, const char *src, size_t dst_size)
{
    size_t n_copied = 0;
    char *dst_ptr = dst;
    const char *src_ptr = src;

    if (dst_size > 0)
    {
        while ((n_copied < (dst_size-1)) && *src_ptr)
        {
            *dst_ptr++ = *src_ptr++;
            n_copied++;
        }

        *dst_ptr++ = '\0';
    }

    while (*src_ptr)
        src_ptr++;
    return (size_t)(src_ptr - src);
}

size_t mystrlen(const char *str)
{
    const char *strp = str;

    while (*strp) {
        strp++;
    }

    return (size_t)(strp - str);
}

int main()
{
    const char *src1 = "The quick brown fox jumps over the lazy dog";
    char dst1[100];
    size_t l1 = strlcpy(dst1, src1, sizeof(dst1));
    printf("l1:%ld dst1:'%s' (source len:%ld)\n", (long)l1, dst1, (long)mystrlen(src1));

    char dst2[10];
    size_t l2 = strlcpy(dst2, src1, sizeof(dst2));
    printf("l2:%ld dst2:'%s' (source len:%ld)\n", (long)l2, dst2, (long)mystrlen(src1));

    char dst3[1];
    size_t l3 = strlcpy(dst3, src1, sizeof(dst3));
    printf("l3:%ld dst3:'%s' (source len:%ld)\n", (long)l3, dst3, (long)mystrlen(src1));

    char dst4[1];
    size_t l4 = strlcpy(dst4, src1, 0);
    printf("l4:%ld\n", (long)l4);

    return 0;
}

