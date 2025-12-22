#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "arbre_binaire.c"


int main(int argc, char *argv[]){
	bintree *t = creation_arbre(
		creation_arbre(NULL, 3, NULL),
		5,
		creation_arbre(NULL, 4, NULL)
	);
	
	printf("La taille de l'arbre est de %d\n", size(t));
	printf("La hauteur de l'arbre est de %d\n", height(t));
	
	printf("Parcours prefixe : ");
	prefixe(t);
	printf("\n");
	
	printf("Parcours infixe : ");
	infixe(t);
	printf("\n");
	
	printf("Parcours postfixe : ");
	postfixe(t);
	printf("\n");
	return 0;
}
