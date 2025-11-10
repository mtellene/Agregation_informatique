//tableau redimensionnable d'entiers

#include <stdlib.h>
#include <stdio.h>

#include "tableau.h"

Vector *vector_create(int capacity){
	Vector *v = malloc(sizeof(Vector));
	
	v->capacity = capacity;
	v->data = calloc(capacity, sizeof(int));
	v->size = 0;
	return v;
}

int vector_size(Vector *v){
	return v->size;
}


int vector_get(Vector *v, int i){
	if(i > vector_size(v)){
		printf("Impossible de récupérer cet élément\n");
		exit(EXIT_FAILURE);
	}else{
		return v->data[i];
	}
}

void vector_set(Vector *v, int x, int i){
	if(i < v->capacity){
		v->data[i] = x;
		printf("Ajout de %d\n", x);
	}else{
		printf("Impossible d'ajouter, taille trop petite\n");
		exit(EXIT_FAILURE);
	}
}


void vector_resize(Vector *v, int s){
	if(s >= 0){
		if(s > v->capacity){
			v->capacity = 2 * v->capacity;
			if(s > v->capacity){ v->capacity = s; }
			int *old = v->data;
			v->data = calloc(v->capacity, sizeof(int));
			for(int i=0 ; i<v->size ; i++){
				v->data[i] = old[i];
			}
			free(old);
		}
		v->size = s;
	}else{
		printf("Nouvelle taille = 0, impossible de faire l'opération\n");
		exit(EXIT_FAILURE);
	}
}

void vector_push(Vector *v, int x){
	int n = vector_size(v);
	vector_resize(v, n+1);
	vector_set(v, x, n);
}















