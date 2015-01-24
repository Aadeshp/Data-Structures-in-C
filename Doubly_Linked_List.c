#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int data;
	struct node_t *next;
    struct node_t *prev;
} node;

typedef struct {
	node *head;
    node *tail;
    int size;
} doubly_linked_list;

void doublyLinkedListInit(doubly_linked_list *dl);
void add(doubly_linked_list *dl, int value);
void addAtIndex(doubly_linked_list *dl, int value, int index);
void remove(doubly_linked_list *dl);
void removeAtIndex(doubly_linked_list *dl, int index);
int getFirst(doubly_linked_list *dl);
int getLast(doubly_linked_list *dl);
int getSize(doubly_linked_list *dl);

void doublyLinkedListInit(doubly_linked_list *dl) {
    dl->size = 0;
    dl->head = NULL;
    dl->tail = NULL;
}

void add(doubly_linked_list *dl, int value) {
    node *curr, *temp;

    curr = dl->head;

    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;

    if (dl->size == 0) {
        dl->head = temp;
        dl->tail = temp;
    } else {
        while (curr->next != NULL)
            cur = cur->next;

        curr->next = temp;
        curr->next->prev = curr;
        dl->tail = curr->next;
    }

    dl->size++
}

void addAtIndex(doubly_linked_list *dl, int value, int index) {
    node *n = (node *)malloc(sizeof(node));
    n->data = value;

    int counter = 0;

    if (index >= dl->size / 2) {
        int indexFromTail = dl->size - index - 1;

        node *curr = dl->tail;
        while (counter < indexFromTail) {
            curr = curr->prev;
            counter++;
        }

        n->prev = curr->prev;
        n->next = curr;
        curr->prev->next = n;
    } else {
        node *curr = dl->head;
        while (counter < index) {
            curr = curr->next;
            counter++;
        }

        n->prev = curr->prev;
        n->next = curr;
        curr->prev->next = n;
    }
}

//Remove Last Element
void remove(doubly_linked_list *dl) {
    node *newLast = dl->tail->prev;
    newLast->next = NULL;
    dl->tail = newLast;
    dl->size--;
}

void removeAtIndex(doubly_linked_list *dl, int index) {
    int counter = 0;

    if (index >= dl->size / 2) {
        int indexFromTail = dl->size - index - 1;
        
        node *curr = dl->tail;
        while (counter < indexFromTail) {
            curr = curr->prev;
            counter++;
        }
        
        curr->prev->next = curr->next;
    } else {
        node *curr = dl->head;
        while (counter < index) {
            curr = curr->next;
            counter++;
        }
        
        curr->prev->next = curr->next;
    }

    dl->size--;
}

int getFirst(doubly_linked_list *dl) {
    return dl->head->data;
}

int getLast(doubly_linked_list *dl) {
    return dl->tail->data;
}

int getSize(doubly_linked_list *dl) {
    return dl->size;
}
