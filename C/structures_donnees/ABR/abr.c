#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "abr.h"

int max(int x, int y){
	if(x>y){ return x; }
	return y;
}

node *creation_arbre(char *cle, int x){
	node *t = malloc(sizeof(struct Node));
	t->left = NULL;
	t->cle = cle;
	t->val = x;
	t->right = NULL;
	return t;
}

int size(node *t){
	if(t == NULL){ return 0; }
	else{ return 1+size(t->left)+size(t->right); }
}

int height(node *t){
	if(t == NULL){ return 0; }
	else{ return 1+max(height(t->left), height(t->right)); }
}

node *add(node *t, char *cle, int x){
	if(t == NULL){ return creation_arbre(cle, x); }
	if(strcmp(t->cle, cle) < 0){ t->right = add(t->right, cle, x); }
	else if(strcmp(t->cle, cle) > 0){ t->left = add(t->left, cle, x); }
	else{
		t->val = x;
	}
	return t;
}

int find(node *t, char *cle){
	if(t == NULL){ return -1; }
	if(strcmp(t->cle, cle) < 0){ return find(t->right, cle); }
	else if(strcmp(t->cle, cle) > 0){ return find(t->left, cle); }
	else{ return t->val; }
}

void prefixe(node *t){
	if(t == NULL){ return; }
	else{
		printf("(%s, %d), ", t->cle, t->val);
		prefixe(t->left);
		prefixe(t->right);
	}
}

void infixe(node *t){
	if(t == NULL){ return; }
	else{
		infixe(t->left);
		printf("(%s, %d), ", t->cle, t->val);
		infixe(t->right);
	}
}

void postfixe(node *t){
	if(t == NULL){ return; }
	else{
		postfixe(t->left);
		postfixe(t->right);
		printf("(%s, %d), ", t->cle, t->val);
	}
}

node *rotation_droite(node *t){
	if(t == NULL || t->left == NULL){ return t; }
	node *l = t->left;
	t->left = l->right;
	l->right = t;
	return l;
}

node *rotation_gauche(node *t){
	if(t == NULL || t->right == NULL){ return t; }
	node *r = t->right;
	t->right = r->left;
	r->left = t;
	return r;
}










