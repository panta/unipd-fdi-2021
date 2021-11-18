/*
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o any-v2 any-v2.c
 *
 * run:
 *   $ ./any-v2
 */

#include <stdio.h>

enum field_type { T_CHAR, T_INT, T_DOUBLE, T_STR };

/*
 * usiamo l'unione solo dentro la struttura any, quindi
 * possiamo definirla direttamente dentro la struttura
 * e contemporaneamente dichiarare il campo 'v' della
 * struttura (con tipo "union any_union").
 */

struct any
{
    enum field_type ft;
    union any_union
    {
        char c_value;
        int i_value;
        double d_value;
        char *str_value;
    } v;
};

void any_print(struct any any) {
    switch (any.ft)
    {
    case T_CHAR:
        printf("char: %c\n", any.v.c_value);
        break;
    case T_INT:
        printf("int: %d\n", any.v.i_value);
        break;
    case T_DOUBLE:
        printf("double: %g\n", any.v.d_value);
        break;
    case T_STR:
        printf("string: %s\n", any.v.str_value);
        break;
    }
}

int main(void) {
    struct any any;

    any.ft = T_CHAR;
    any.v.c_value = 'B';
    any_print(any);
    
    any.ft = T_STR;
    any.v.str_value = "Hello, World!";
    any_print(any);

    any.ft = T_DOUBLE;
    any.v.d_value = 42.5;
    any_print(any);

    return 0;
}
