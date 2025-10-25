#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 *  Returns the last node of the linked list.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL)
        return NULL;
    struct ll_node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

/**
 * returns number of nodes in the linked list.
 */
int ll_size(struct ll_node *head) {
  int count = 0;
    struct ll_node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

/**
 * returns a pointer to the first node in the list for the value.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   struct ll_node *curr = head;
    while (curr != NULL) {
        if (curr->data == value)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

/**
 * linked list conv to dynamic array of ints.
 */
int *ll_toarray(struct ll_node *head) {
   int size = ll_size(head);
    if (size == 0)
        return NULL;

    int *array = malloc(sizeof(int) * size);
    if (array == NULL)
        return NULL;

    struct ll_node *curr = head;
    for (int i = 0; i < size; i++) {
        array[i] = curr->data;
        curr = curr->next;
    }
    return array;
}

/**
 * creates linked list with the new input being the new node.
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
    if (node == NULL)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * node delete
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *curr = head;
    while (curr != NULL) {
        struct ll_node *next = curr->next;
        free(curr);
        curr = next;
    }
}

/**
 * fnction to append the new node to the end of the list.
 */
void ll_append(struct ll_node *head, int data) {
 if (head == NULL)
        return; 

    struct ll_node *tail = ll_tail(head);
    struct ll_node *new_node = ll_create(data);
    tail->next = new_node;
}

/**
 * function for linked list from array of ints.
 */
struct ll_node *ll_fromarray(int* data, int len) {
if (data == NULL || len <= 0)
        return NULL;

    struct ll_node *head = ll_create(data[0]);
    struct ll_node *curr = head;

    for (int i = 1; i < len; i++) {
        curr->next = ll_create(data[i]);
        curr = curr->next;
    }

    return head;
}

/**
 * removes the given value node.
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
if (head == NULL)
        return NULL;

    if (head->data == value) {
        struct ll_node *next = head->next;
        free(head);
        return next;
    }

    struct ll_node *curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == value) {
            struct ll_node *to_delete = curr->next;
            curr->next = curr->next->next;
            free(to_delete);
            break;
        }
        curr = curr->next;
    }

    return head;
}

