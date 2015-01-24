#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int data;
	struct node_t *next;
} node;

typedef struct {
	node *head;
	int size;
} linked_list;

void linkedListInit(linked_list *l);
void add(linked_list *l, int x);
void addAtIndex(linked_list *l, int index, int x);
int get(linked_list *l, int index);
int listRemove(linked_list *l);
int removeAtIndex(linked_list *l, int index);
int getFirst(linked_list *l);
int getLast(linked_list *l);
int getSize(linked_list *l);

void init(linked_list *l) {
	l->size = 0;
}

//Adds Node to the End of the Linked List
void add(linked_list *l, int x) {	
	node *curr, *temp;

	curr = l->head;

	temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;

	if (l->size == 0)
		l->head = temp;
	else {
		while (curr->next != NULL)
			curr = curr->next;

		curr->next = temp;
	}

	l->size++;
}

//Adds Node to the Specified Index
void addAtIndex(linked_list *l, int index, int x) {
	if (index < 0 || index > l->size)
		return;

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;

	if (index == 0) {
		temp->next = l->head;
		l->head = temp;
	} else {
		node *curr = l->head;
		int counter = 0;

		while (counter < index - 1) {
			curr = curr->next;
			counter++;
		}

		node *temp = (node *)malloc(sizeof(node));
		temp->data = x;

		node *temp2 = curr->next;
		curr->next = temp;
		temp->next = temp2;

		l->size++;
	}
}

//Retrieves the Value of a Specified Index
int get(linked_list *l, int index) {
	if (index < 0)
		return -1;

	int counter = 0;
	node *curr = l->head;

	while (counter < index) {
		if (curr->next == NULL)
			return -1;

		curr = curr->next;
		counter++;
	}

	return curr->data;
}

//Removes the Last Element
int listRemove(linked_list *l) {
	node *curr = l->head;

	int counter = 0;
	while (counter < l->size - 1) {
		curr = curr->next;
		counter++;
	}

	int val = curr->next->data;
	curr->next = NULL;

	l->size--;

	return val;
}

//Remove Element at Specified Index
int removeAtIndex(linked_list *l, int index) {
	if (index == 0) {
		int val = l->head->data;
		l->head = l->head->next;
		return val;
	} else {
		node *curr = l->head;
		int counter = 0;

		while (counter < index - 1) {
			if (curr->next == NULL)
				return -1;

			curr = curr->next;
			counter++;
		}

		node *temp = curr;
		node *temp2 = curr->next;
		temp->next = temp2->next;

		l->size--;

		return temp2->data;
	}
}

//Returns the First Element
int getFirst(linked_list *l) {
	return l->head->data;
}

//Returns the Last Element
int getLast(linked_list *l) {
	node *curr = l->head;
	while (curr->next != NULL) 
		curr = curr->next;

	return curr->data;
}

int getSize(linked_list *l) {
	return l->size;
}
