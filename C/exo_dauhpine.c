// exo paris dauphine

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

int main(int argc, char *argv[]){
	//affiche_pg_nb();
	//division();
	multiplication();
	if(argv[1] != NULL){
		int x = atoi(argv[1]);
		affichage_ascii(argv[1]);
		printf("%d\n", est_pair(x));
		liste_diviseur(x);

		if(argv[2] != NULL){
			int y = atoi(argv[2]);
			printf("%d\n", produit1(x, y));
			printf("avant échange : x = %d, y = %d\n", x, y);
			echange(&x, &y);
			printf("après échange : x = %d, y = %d\n", x, y);

			if(argv[3] != NULL){
				int z = atoi(argv[3]);
				printf("le plus grand des nombres est %d\n", max3(x, y, z));
			}
		}
	}
	return 0;
}
