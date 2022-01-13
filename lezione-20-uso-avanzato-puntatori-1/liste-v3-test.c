/*
 * compile:
 *   $ gcc -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror -o liste-v2 liste-v2.c
 *
 * run:
 *   $ ./liste-v2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utest.h"


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

// list_print_s() prints the list starting at 'head' into a string.
void list_print_s(char *dst, struct node *head)
{
    char buf[100];
    struct node *ptr;

    *dst = '\0';
    *buf = '\0';
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        sprintf(buf, "%d", ptr->value);
        strcat(dst, buf);
        if (ptr->next != NULL)
            strcat(dst, " -> ");
    }
}

void list_print(struct node *head)
{
    char buf[200];
    list_print_s(buf, head);
    printf("%s\n", buf);
}


/* --------------------------------------------------------------------
 *   TEST FUNCTIONS
 *
 *  These use the macros defined in utest.h
 * -------------------------------------------------------------------- */

test_data_t test_data;

test_result_t test_node_create() {
    struct node *n = node_create(42);
    T_ASSERT(n != NULL);
    T_ASSERT(n->value == 42);
    T_OK();
}

test_result_t test_list_add_new_head() {
    struct node *head = node_create(7);
    T_ASSERT(head->value == 7);

    head = list_add(head, 5);
    T_ASSERT(head->value == 5);
    T_ASSERT(head->next != NULL);
    T_ASSERT(head->next->value == 7);
    T_OK();
}

test_result_t test_list_add_tail() {
    struct node *head = node_create(7);
    T_ASSERT(head->value == 7);

    head = list_add(head, 12);
    T_ASSERT(head->value == 7);
    T_ASSERT(head->next != NULL);
    T_ASSERT(head->next->value == 12);
    T_OK();
}

test_result_t test_list_print_s() {
    char buf[100] = "";

    struct node *head = node_create(7);
    list_print_s(buf, head);
    T_ASSERT(strcmp(buf, "7") == 0);

    head = list_add(head, 5);
    list_print_s(buf, head);
    T_ASSERT(strcmp(buf, "5 -> 7") == 0);

    head = list_add(head, 38);
    list_print_s(buf, head);
    T_ASSERT(strcmp(buf, "5 -> 7 -> 38") == 0);

    head = list_add(head, 53);
    list_print_s(buf, head);
    T_ASSERT(strcmp(buf, "5 -> 7 -> 38 -> 53") == 0);

    head = list_add(head, 33);
    list_print_s(buf, head);
    T_ASSERT(strcmp(buf, "5 -> 7 -> 33 -> 38 -> 53") == 0);

    head = list_add(head, 2);
    list_print_s(buf, head);
    T_ASSERT(strcmp(buf, "2 -> 5 -> 7 -> 33 -> 38 -> 53") == 0);

    T_OK();
}

int all_tests() {
    T_RUN_TEST(test_node_create);
    T_RUN_TEST(test_list_add_new_head);
    T_RUN_TEST(test_list_add_tail);
    T_RUN_TEST(test_list_print_s);
    return 0;
} 

T_MAIN()
