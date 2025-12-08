#ifndef PILE_H
#define PILE_H

#include "cell.h"

typedef struct{
	Cell *top;
} Pile;

Pile creation_pile(void); //créer une pile vide
int est_vide(Pile *p); //1 si pile vide, 0 sinon
void empiler(Pile *p, int x); //ajoute (empile) une valeur en haut
int depiler(Pile *p); //enlève (dépile) la valeur du haut et la récupère
int avoir_top(Pile *p); //renvoie le haut de la pile (sans dépiler)
void suppression_pile(Pile *p);

void afficher_pile(Pile *p); //ne pas faire car pas en adéquation avec la pile (ok pour debug)

/*
void afficher_liste(Liste *l);
int longueur(Liste *l); //renvoie la taille de la liste

void ajouter_tete(int x, Liste *l); //ajoute une valeur en tête
void ajouter_queue(int x, Liste *l); //ajoute une valeur à la fin
void ajouter_i(int x, int i, Liste *l); //ajoute une valeur à un certain indice

void supprimer_tete(Liste *l);
void supprimer_queue(Liste *l);
void supprimer_maillon(int i, Liste *l); //supprime le maillon à l'indice i

int est_present(int x, Liste *l); //1 si x dans l, 0 sinon
*/
#endif



