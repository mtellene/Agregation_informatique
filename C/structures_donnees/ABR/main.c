#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "abr.c"


int main(int argc, char *argv[]){
	node *t = creation_arbre("foo",1);
	
	printf("La taille de l'arbre est de %d\n", size(t));
	printf("La hauteur de l'arbre est de %d\n", height(t));
	
	t = add(t, "bar", 4);
	t = add(t, "baz", 2);
	t = add(t, "gee", 1);
	
	printf("Parcours prefixe : ");
	prefixe(t);
	printf("\n");
	
	printf("Parcours infixe : ");
	infixe(t);
	printf("\n");
	
	printf("Parcours postfixe : ");
	postfixe(t);
	printf("\n");
	
	char *cle = "foo";
	printf("La valeur associée à la clé %s est %d\n", cle, find(t, cle));
	
	t = rotation_droite(t);
	printf("Parcours prefixe : ");
	prefixe(t);
	printf("\n");
	
	t = rotation_gauche(t);
	printf("Parcours prefixe : ");
	prefixe(t);
	printf("\n");
	return 0;
}
