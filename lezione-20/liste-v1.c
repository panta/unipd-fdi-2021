/*
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o liste-v1 liste-v1.c
 *
 * run:
 *   $ ./liste-v1
 */

#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

void print_list(struct node *head)
{
    struct node *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%d", ptr->value);
        if (ptr->next != NULL)
            printf(" -> ");
        else
            printf("\n");
    }
}

int main(void)
{
    struct node a, b, c;
    
    a.value = 5;
    a.next = &b;
    
    b.value = 7;
    b.next = &c;
    
    c.value = 53;
    c.next = NULL;

    print_list(&a);

    struct node d;
    d.value = 38;
    d.next = &c;
    b.next = &d;
    print_list(&a);

    return 0;
}
