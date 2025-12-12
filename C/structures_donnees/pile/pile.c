#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "pile.h"

Pile creation_pile(void){
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














