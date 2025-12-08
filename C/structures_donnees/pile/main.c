#include <stdio.h>
#include <stdlib.h>

#include "pile.c"

int main(int argc, char *argv[]){
	int top;
	Pile p = creation_pile();
	printf("Pile vide ? %d\n", est_vide(&p));
	
	//printf("Haut de la pile : %d\n", avoir_top(&p));
	
	//top = depiler(&p);
	//printf("Valeur dépilée : %d\n", top);
	
	empiler(&p, 1);
	printf("Pile vide ? %d\n", est_vide(&p));
	printf("Haut de la pile : %d\n", avoir_top(&p));
	
	afficher_pile(&p);
	
	empiler(&p, 2);
	printf("Haut de la pile : %d\n", avoir_top(&p));
	afficher_pile(&p);
	
	top = depiler(&p);
	printf("Valeur dépilée : %d\n", top);
	afficher_pile(&p);
	
	suppression_pile(&p);
	printf("Pile vide ? %d\n", est_vide(&p));
	//printf("Haut de la pile : %d\n", avoir_top(&p));

	return 0;
}
