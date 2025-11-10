#ifndef TAB_H
#define TAB_H

typedef struct{
	int capacity;
	int *data;
	int size;
} Vector;

Vector *vector_create(int capacity);
int vector_size(Vector *v);
int vector_get(Vector *v, int i);
void vector_set(Vector *v, int x, int i);
void vector_resize(Vector *v, int s);

void vector_push(Vector *v, int x);


#endif
