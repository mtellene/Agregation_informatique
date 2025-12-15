#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "pile.c"

bool verif_parentheses(char *expr){
	int n = strlen(expr);
	if(n%2 == 1){ return false; }
	Pile p = creation_pile();
	for(int i=0 ; i<n ; i++){
		printf("%c\n", expr[i]);
		if(expr[i] == '('){ empiler(&p, 1); }
		else if(expr[i] == ')'){
			if(est_vide(&p) || depiler(&p) != 1){ return false; }
		}
	}
	return est_vide(&p);
}

int eval_npi(char *expr){
	Pile p = creation_pile();
	int n = strlen(expr);
	for(int i=0 ; i<n ; i++){
		if(expr[i] == '+'){
			empiler(&p, (depiler(&p) + depiler(&p)));
		}
		else if(expr[i] == '-'){
			empiler(&p, (depiler(&p) - depiler(&p)));
		}
		else if(expr[i] == '*'){
			empiler(&p, (depiler(&p) * depiler(&p)));
		}
		else if(expr[i] == '/'){
			empiler(&p, (depiler(&p) / depiler(&p)));
		}
		else{ empiler(&p, expr[i] - '0'); }
	}
	return avoir_top(&p);
}


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
	
	char *expr = "()()()()(()()())";
	printf("L'expression %s est bien parenthésée : %s\n", expr, verif_parentheses(expr)?"true":"false");
	
	char *expr2 = "34+2*";
	printf("Le calcul en npi suivant %s est égal à %d\n", expr2, eval_npi(expr2));

	return 0;
}
