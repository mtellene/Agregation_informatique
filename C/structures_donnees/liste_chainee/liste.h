#ifndef LISTE_H
#define LISTE_H

#include "cell.h"

typedef struct{
	Cell *head;
} Liste;

Liste liste_vide(void); //créer une liste vide
int est_vide(Liste *l); //1 si liste vide, 0 sinon
void afficher_liste(Liste *l);
int longueur(Liste *l); //renvoie la taille de la liste

void ajouter_tete(int x, Liste *l); //ajoute une valeur en tête
void ajouter_queue(int x, Liste *l); //ajoute une valeur à la fin
void ajouter_i(int x, int i, Liste *l); //ajoute une valeur à un certain indice

void supprimer_tete(Liste *l);
void supprimer_queue(Liste *l);
void supprimer_maillon(int i, Liste *l); //supprime le maillon à l'indice i

int est_present(int x, Liste *l); //1 si x dans l, 0 sinon

#endif



