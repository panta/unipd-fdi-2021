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

// predecessor() returns the predecessor of 'value'
// in the sorted list beginning at 'head'.
// The predecessor is the last node with a value smaller
// then 'value'.
// Returns: the predecessor found, or NULL (if no smaller node is found).
struct node *predecessor(struct node *head, int value)
{
    struct node *pred = head;

    if (pred->value >= value)
        return NULL;
    while (pred->next && (pred->next->value < value)) {
        pred = pred->next;
    }

    return pred;
}

// list_add() allocates a new node of value 'value' and
// adds it to the sorted list starting at 'head', keeping
// the list sorted.
// The function returns the (possibly new) head of the
// sorted list.
struct node *list_add(struct node *head, int value)
{
    struct node *node = node_create(value);
    if (!node)
        return NULL;

    struct node *pred = predecessor(head, value);

    if (pred == NULL) {
        // no value smaller than 'value'
        // our node will be the new head
        node->next = head;
        return node;
    }

    node->next = pred->next;
    pred->next = node;

    return head;
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
    struct node *head = node_create(7);
    list_print(head);

    head = list_add(head, 5);
    list_print(head);
    head = list_add(head, 38);
    list_print(head);
    head = list_add(head, 53);
    list_print(head);
    head = list_add(head, 33);
    list_print(head);
    head = list_add(head, 2);
    list_print(head);

    list_destroy(head);
    head = NULL;

    return 0;
}
