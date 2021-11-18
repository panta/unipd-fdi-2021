/*
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o any-v3 any-v3.c
 *
 * run:
 *   $ ./any-v3
 */

#include <stdio.h>

enum field_type { T_CHAR, T_INT, T_DOUBLE, T_STR };

/*
 * e dato che usiamo l'unione solo dentro la struttura any,
 * non ci serve nemmeno l'etichetta, togliamola...
 */

struct any
{
    enum field_type ft;
    union
    {
        char c_value;
        int i_value;
        double d_value;
        char *str_value;
    } v;
};

void any_print(const struct any *any) {
    switch (any->ft)
    {
    case T_CHAR:
        printf("char: %c\n", any->v.c_value);
        break;
    case T_INT:
        printf("int: %d\n", any->v.i_value);
        break;
    case T_DOUBLE:
        printf("double: %g\n", any->v.d_value);
        break;
    case T_STR:
        printf("string: %s\n", any->v.str_value);
        break;
    }
}

int main(void) {
    struct any any;

    any.ft = T_CHAR;
    any.v.c_value = 'B';
    any_print(&any);
    
    any.ft = T_STR;
    any.v.str_value = "Hello, World!";
    any_print(&any);

    any.ft = T_DOUBLE;
    any.v.d_value = 42.5;
    any_print(&any);

    return 0;
}
