// exo paris dauphine

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

int produit1(int x, int y){
	return x*y;
}

void echange(int *x, int *y){
	int z = *x;
	*x = *y;
	*y = z;
}

void affichage_ascii(char *c){
	printf("caractère : %s\t code : %d\t code hexa : %x\n", c, *c, *c);
}

bool est_pair(int x){
	return (x%2 == 0);
}

int max3(int x, int y, int z){
	if(x>=y && x>=z){ return x; }
	else if(y>=x && y>=z){ return y; }
	else{ return z; }
}

void affiche_pg_nb(){
	int nb_min = INT_MAX;
	int nb_max = INT_MIN;
	int x = -1;
	while(x != 0){
		printf("Entrer un nombre : ");
		scanf("%d", &x);
		if(nb_min > x){ nb_min = x; }
		if(nb_max < x){ nb_max = x; }
		printf("Plus grand nb : %d\n", nb_max);
		printf("Plus petit nb : %d\n", nb_min);
	}
}

void liste_diviseur(int x){
	printf("Liste des diviseurs de %d : ", x);
	for(int i=2 ; i<=x ; i++){
		if(x%i == 0){ printf("%d ", i); }
	}
	printf("\n");
}

void division(){
	int a, b;
	printf("Entrer un nombre : ");
	scanf("%d", &a);
	printf("Entrer un second nombre : ");
	scanf("%d", &b);
	int diviseur, divise;
	if(a > b){
		divise = a;
		diviseur = b;
	}else{
		divise = b;
		diviseur = a;
	}
	printf("Division de %d par %d\n", divise, diviseur);
	int quotient = 0;
	int reste = divise;
	while(diviseur <= reste){
		quotient = quotient + 1;
		reste = reste - diviseur;
	}
	printf("quotient = %d ; reste : %d\n", quotient, reste);
}

void multiplication(){
	int a, b;
	printf("Entrer un nombre : ");
	scanf("%d", &a);
	printf("Entrer un second nombre : ");
	scanf("%d", &b);
	int acc = a;
	printf("%d * %d", a, b);
	while(b>0){
		if(b%2 == 1){
			b = b-1;
			printf("\t = %d * %d + %d\n", acc, b, a);
			acc = acc*2;
		}else{
			b = b/2;
			printf("\t = %d * %d + %d\n", acc, b, a);
			a = a+acc;
		}
	}
	printf("\t = %d\n", a);
}

void calculatrice(){
	char calcul[20], operateur;
	int a, b;
	printf("Entrer un calcul : ");
	scanf("%[^\n]%*c", calcul);
	printf("Calcul : %s\n", calcul);
	
	for(int i=0 ; calcul[i] != '\0' ; i++){
		if(calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' || calcul[i] == '%' || calcul[i] == '/'){
			operateur = calcul[i];
			calcul[i] = '\0';
			a = atoi(calcul);
			b = atoi(&calcul[i+1]);
			break;
		}
	}
	if(operateur == '+'){ printf("%d\n", a+b); }
	else if(operateur == '-'){ printf("%d\n", a-b); }
	else if(operateur == '*'){ printf("%d\n", a*b); }
	else if(operateur == '%' && b != 0){ printf("%d\n", a%b); }
	else if(operateur == '/' && b != 0){ printf("%d\n", a/b); }
}

void changement_valeur_pointeur(){
	int i = 6;
	int *p = &i;
	printf("Valeur de i %d\n", i);
	*p = 12;
	printf("Valeur de i %d\n", i);
}

void elements_nuls_tab(){
	int tab[8] = {0,1,0,1,0,0,0,1};
	for(int i=0 ; i<8 ; i++){
		if(tab[i] == 0){
			printf("Element nul à l'indice %d\n", i);
		}
	}
}


#define NMAX 10
typedef char mot[NMAX];

void miroir(mot dest, mot src){
	for(int i=0 ; i<strlen(src) ; i++){
		dest[strlen(src) - 1 - i] = src[i];
	}
}




int main(int argc, char *argv[]){
	mot a = "bonjour";
	mot b;
	miroir(b, a);
	printf("Mot source : %s\nMot destination : %s\n", a, b);
	return 0;
}
