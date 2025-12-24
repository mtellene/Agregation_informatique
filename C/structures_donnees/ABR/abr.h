#ifndef NODE_H
#define NODE_H

typedef struct Node{
	struct Node *left;
	char *cle;
	int val;
	struct Node *right;
} node;


node *creation_arbre(char *cle, int x); //créer un ABR vide
int size(node *t); //renvoie la taille (nb de noeuds) d'un ABR
int height(node *t); //renvoie la hauteur d'un ABR

node *add(node *t, char *cle, int x);
int find(node *t, char *cle);

void prefixe(node *t);
void infixe(node *t);
void postfixe(node *t);

node *rotation_gauche(node *t);

#endif



