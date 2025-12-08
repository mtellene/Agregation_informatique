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
	//free(p);
}

/*

void afficher_liste(Liste *l){
	printf("[");
	Cell *c = l->head;
	while(c != NULL){
		printf("%d", c->val);
		if(c->next != NULL){
			printf("->");
		}
		c = c->next;
	}
	printf("]\n");
}

int longueur(Liste *l){
	if(est_vide(l)){ return 0; }
	int cpt = 1;
	Cell *c = l->head;
	while(c->next != NULL){
		cpt = cpt+1;
		c = c->next;
	}
	return cpt;
}

void ajouter_tete(int x, Liste *l){
	Cell *c = malloc(sizeof(Cell));
	if(c == NULL){
		printf("Erreur : malloc a échoué\n");
		exit(EXIT_FAILURE);
	}
	c->val = x;
	c->next = l->head;
	l->head = c;
	printf("Ajout de %d en tete\n", x);
}

void ajouter_queue(int x, Liste *l){
	if(est_vide(l)){ ajouter_tete(x, l); }
	Cell *c = malloc(sizeof(Cell));
	if(c == NULL){
		printf("Erreur : malloc a échoué\n");
		exit(EXIT_FAILURE);
	}
	Cell *p = l->head;
	while(p->next != NULL){ p = p->next; }
	c->val = x;
	c->next = NULL;
	p->next = c;
	printf("Ajout de %d en queue\n", x);
}

void ajouter_i(int x, int i, Liste *l){
	if(est_vide(l) || i == 0){ ajouter_tete(x, l); }
	else if(i == longueur(l)+1){ ajouter_queue(x, l); }
	else{
		Cell *c = malloc(sizeof(Cell));
		if(c == NULL){
			printf("Erreur : malloc a échoué\n");
			exit(EXIT_FAILURE);
		}
		Cell *p = l->head;
		int cpt = 0;
		while(i != cpt+1){
			p = p->next;
			cpt = cpt+1;
		}
		c->val = x;
		c->next = p->next;
		p->next = c;
	}
	printf("Ajout de %d en à l'indice %d\n", x, i);
}

void supprimer_tete(Liste *l){
	if(est_vide(l)){
		printf("Erreur : impossible de supprimer, liste vide\n");
		exit(EXIT_FAILURE);
	}
	l->head = l->head->next;
	printf("Suppression en tete\n");
}

void supprimer_queue(Liste *l){
	if(est_vide(l)){
		printf("Erreur : impossible de supprimer, liste vide\n");
		exit(EXIT_FAILURE);
	}
	if(longueur(l) == 1) { supprimer_tete(l); }
	Cell *c = l->head;
	while(c->next->next != NULL){
		c = c->next;
	}
	c->next = NULL;
	printf("Suppression en queue\n");
}


void supprimer_maillon(int i, Liste *l){
	if(est_vide(l)){
		printf("Erreur : impossible de supprimer, liste vide\n");
		exit(EXIT_FAILURE);
	} else if(i > longueur(l)){
		printf("Erreur : impossible de supprimer, indice trop grand\n");
		exit(EXIT_FAILURE);
	}
	if(i == 0){ supprimer_tete(l); }
	else if (i == longueur(l)-1){ supprimer_queue(l); }
	else{
		Cell *p = l->head;
		int cpt = 0;
		while(i != cpt+1){
			p = p->next;
			cpt = cpt+1;
		}
		p->next = p->next->next;
	}
	printf("Suppression à l'indice %d\n", i);
}

int est_present(int x, Liste *l){
	if(est_vide(l)){ return 0; }
	Cell *c = l->head;
	while(c->next != NULL){
		if(c->val == x){ return 1; }
		c = c->next;
	}
	return c->val == x;
}
*/









