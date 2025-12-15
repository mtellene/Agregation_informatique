#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H

#include <stdbool.h>

#include "entry.h"

typedef struct Hashtable{
	int cap; //nombre d'entrée au maximum dans la table
	int size; //nombre d'entrée dans la table
	entry **data;
} hashtable;

hashtable *creation_table(int size); //créer une table de taille size
int hash(char *expr);
int bucket(hashtable *ht, char *expr);

void put(hashtable *ht, char *expr, int value);

entry *get_entry(hashtable *ht, int idx);
bool contains(hashtable *ht, char *expr);

int get_value(hashtable *ht, char *expr); //renvoie la valeur associée à une clé

void affichage(hashtable *ht);


#endif
