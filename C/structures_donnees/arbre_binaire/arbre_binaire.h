#ifndef NODE_H
#define NODE_H

typedef struct Node{
	struct Node *left;
	int val;
	struct Node *right;
} bintree;


bintree *creation_arbre(bintree *l, int x, bintree *r); //créer un arbre binaire vide
int size(bintree *t); //renvoie la taille (nb de noeuds) d'un arbre binaire
int height(bintree *t); //renvoie la hauteur d'un arbre binaire

void prefixe(bintree *t);
void infixe(bintree *t);
void postfixe(bintree *t);

#endif



