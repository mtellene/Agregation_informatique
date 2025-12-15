#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "table_hachage.h"

hashtable *creation_table(int capacity){
	assert(capacity>0);
	hashtable *ht = malloc(sizeof(hashtable));
	ht->cap = capacity;
	ht->size = 0;
	ht->data = calloc(capacity, sizeof(entry*));
	for(int i=0 ; i<capacity ; i++){
		ht->data[i] = NULL;	
	}
	return ht;
}

int hash(char *expr){
	int acc = 0;
	for(int i=0 ; i<strlen(expr) ; i++){
		acc = 31*acc + (int)expr[i];
	}
	return acc;
}

int bucket(hashtable *ht, char *expr){
	return hash(expr) % ht->cap;
}

void put(hashtable *ht, char *expr, int value){
	int idx = bucket(ht, expr);
	entry *e = malloc(sizeof(entry));
	e->key = expr;
	e->val = value;
	e->next = ht->data[idx];
	ht->data[idx] = e;
}

entry *get_entry(hashtable *ht, int idx){
	return ht->data[idx];
}

bool contains(hashtable *ht, char *expr){
	entry *e = get_entry(ht, bucket(ht, expr));
	while(e != NULL){
		if(e->key == expr){ return true; }
		e = e->next;
	}
	return false;
}

int get_value(hashtable *ht, char *expr){
	assert(contains(ht, expr) == 1);
	entry *e = get_entry(ht, bucket(ht, expr));
	while(e != NULL){
		if(e->key == expr){ return e->val; }
		e = e->next;
	}
}



void affichage(hashtable *ht){
	for(int i=0 ; i<ht->cap ; i++){
		printf("[");
		entry *e = ht->data[i];
		while(e != NULL){
			printf(" (%s, %d) ", e->key, e->val);
			e = e->next;
		}
		printf("]\n");
	}
}
