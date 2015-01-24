#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int allocated;
	int *data;
} arrayList;

//Initialize the ArrayList
void init (arrayList *a) {
	a->size = 0;
	a->allocated = 10;
	a->data = (int *)malloc(sizeof(int) * a->allocated);
}

//Add Element at the end of the arraylist
void add (arrayList *a, int value) {
	if (a->size >= a->allocated)
		resizeArray(a);

	a->data[a->size++] = value;
}

//Add Element at Index and pushes the elements at that index and after that index over by one
void addAtIndex (arrayList *a, int index, int value) {
	if (a->size >= a->allocated)
		resizeArray(a);

	for (int x = index; x < a->size; x++)
		a->data[x + 1] = a->data[x];

	a->data[index] = value;
	a->size++;
}

//Gets Element at Index
int get (arrayList *a, int index) {
	if (index > a->size - 1 || index < 0)
		return -1;

	return a->data[index];
}

void remove (arrayList *a) {
	if (size <= 0)
		return;

	a->size--;
}

void removeAtIndex (arraylist *a, int index) {
	if (index > a->size - 1 || index < 0)
		return;

	for (int x = index; x < a->size - 1; x++)
		a->data[x] = a->data[x + 1];

	a->size--;
}

//Reallocate if Size > Allocated size
void resizeArray(arrayList *a) {
	if (a->size == a->allocated) {
		a->allocated *= 2;
		a->data = (int *)realloc(sizeof(int) * a->allocated);
	}
}