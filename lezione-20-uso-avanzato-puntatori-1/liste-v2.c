/*
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o liste-v2 liste-v2.c
 *
 * run:
 *   $ ./liste-v2
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

// node_create() allocates a node and sets its value to 'value'.
struct node *node_create(int value)
{
    struct node *node;

    node = (struct node *) malloc(sizeof(struct node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

// node_destroy() deallocate the given node.
void node_destroy(struct node *node)
{
    if (node)
        free(node);
}

// list_destroy() deallocates all nodes in the list starting at 'head'.
void list_destroy(struct node *head)
{
    struct node *ptr, *next;
    for (ptr = head; ptr != NULL; ptr = next) {
        next = ptr->next;

        node_destroy(ptr);
    }
}

// list_insert() insert the node 'node' after the node 'at'.
void list_insert(struct node *at, struct node *node)
{
    struct node *next = at->next;

    node->next = next;
    at->next = node;
}

// list_print() prints the list starting at 'head'.
void list_print(struct node *head)
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
    struct node *a = node_create(5);
    struct node *b = node_create(7);
    struct node *c = node_create(53);
 
    list_insert(a, b);
    list_insert(b, c);
    list_print(a);

    struct node *d = node_create(38);
    list_insert(b, d);
    list_print(a);

    list_destroy(a);

    return 0;
}
