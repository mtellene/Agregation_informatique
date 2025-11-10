#include <stdlib.h>
#include <stdio.h>

#include "tableau.c"

int main(int argc, char *argv[]){
	Vector *v = vector_create(13);
	printf("Taille du tableau : %d\n", vector_size(v));
	
	vector_push(v, 20);
	vector_push(v, 12);
	vector_push(v, 1);
	
	printf("Taille du tableau : %d\n", vector_size(v));
	printf("Element à l'indice %d : %d\n", 0, vector_get(v, 0));
	printf("Element à l'indice %d : %d\n", 1, vector_get(v, 1));
	printf("Element à l'indice %d : %d\n", 2, vector_get(v, 2));
	return 0;
}
