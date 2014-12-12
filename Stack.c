#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int allocated;
	int *data;
} stack;

void init(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int peek(stack *s);
int isEmpty(stack *s);
void resizeStack(stack *s);

void init(stack *s) {
	s->size = 0;
	s->allocated = 10;
	s->data = (int *)malloc(sizeof(int) * s->allocated);
}

void push(stack *s, int x) {
	if (s->size == s->allocated)
		resizeStack(s);

	s->data[s->size++] = x;
}

int pop(stack *s) {
	if (s->size == 0)
		return -1;
	else
		return s->data[--s->size];
}

int peek(stack *s) {
	return s->data[s->size - 1];
}

int isEmpty(stack *s) {
	return s->size == 0;
}

void resizeStack(stack *s) {
	if (s-> size == s->allocated) {
		s->allocated *= 2;
		s->data = (int *)realloc(s->data, sizeof(int) * s->allocated);	
	}
}