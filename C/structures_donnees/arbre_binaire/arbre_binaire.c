#include <stdlib.h>
#include <stdio.h>

#include "arbre_binaire.h"

int max(int x, int y){
	if(x>y){ return x; }
	return y;
}

bintree *creation_arbre(bintree *l, int x, bintree *r){
	bintree *t = malloc(sizeof(struct Node));
	t->left = l;
	t->val = x;
	t->right = r;
	return t;
}

int size(bintree *t){
	if(t == NULL){ return 0; }
	else{ return 1+size(t->left)+size(t->right); }
}

int height(bintree *t){
	if(t == NULL){ return 0; }
	else{ return 1+max(height(t->left), height(t->right)); }
}

void prefixe(bintree *t){
	if(t == NULL){ return; }
	else{
		printf("%d", t->val);
		prefixe(t->left);
		prefixe(t->right);
	}
}

void infixe(bintree *t){
	if(t == NULL){ return; }
	else{
		infixe(t->left);
		printf("%d", t->val);
		infixe(t->right);
	}
}

void postfixe(bintree *t){
	if(t == NULL){ return; }
	else{
		postfixe(t->left);
		postfixe(t->right);
		printf("%d", t->val);
	}
}

/*Pile creation_pile(void){
	Pile p;
	p.top = NULL;
	return p;
}

int est_vide(Pile *p){
	return p->top == NULL;
}

void empiler(Pile *p, int x){
	Cell *c = malloc(sizeof(Cell));
	c->val = x;
	if(est_vide(p)){
		p->top = c;
		c->next = NULL;
	} else {
		c->next = p->top;
		p->top = c;
	}
	printf("Valeur %d empilée\n", x);
}

void afficher_pile(Pile *p){
	printf("Affichage pile :\n");
	if(est_vide(p)){ printf("/"); }
	else{
		Cell *c = p->top;
		printf("%d\n---\n", c->val);
		while(c->next != NULL){
			c = c->next;
			printf("%d\n---\n", c->val);
		}
	}
}

int depiler(Pile *p){
	assert(! est_vide(p));
	Cell *c = p->top;
	int x = c->val;
	p->top = c->next;
	free(c);
	return x;
}

int avoir_top(Pile *p){
	assert(! est_vide(p));
	return p->top->val;
}

void suppression_pile(Pile *p){
	while(! est_vide(p)){ depiler(p); }
}

*/












