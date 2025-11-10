#include <stdio.h>
#include <stdlib.h>

#include "liste.c"

int main(int argc, char *argv[]){
	Liste l = liste_vide();
	afficher_liste(&l);
	
	ajouter_tete(8, &l);
	afficher_liste(&l);
	
	ajouter_tete(4, &l);
	afficher_liste(&l);
	
	ajouter_queue(5, &l);
	afficher_liste(&l);
	
	ajouter_i(0, 0, &l);
	afficher_liste(&l);
	
	ajouter_i(0, 5, &l);
	afficher_liste(&l);
	
	ajouter_i(10, 3, &l);
	afficher_liste(&l);
	
	ajouter_i(20, 3, &l);
	afficher_liste(&l);
	
	supprimer_maillon(5, &l);
	afficher_liste(&l);
	
	supprimer_tete(&l);
	afficher_liste(&l);
	
	supprimer_queue(&l);
	afficher_liste(&l);
	
	supprimer_maillon(0, &l);
	afficher_liste(&l);
	
	printf("Element %d présent dans l : %d\n", 8, est_present(8, &l));
	printf("Element %d présent dans l : %d\n", 20, est_present(20, &l));
	printf("Element %d présent dans l : %d\n", 10, est_present(10, &l));
	printf("Element %d présent dans l : %d\n", 40, est_present(40, &l));
	
	return 0;
}
