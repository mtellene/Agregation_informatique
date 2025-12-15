#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table_hachage.c"

int main(int argc, char *argv){
	hashtable ht = *creation_table(10);
	
	put(&ht, "salut", 8);
	put(&ht, "bonjour", 10);
	put(&ht, "adieu", 3);
	put(&ht, "test", -1);
	put(&ht, "hello", 2);
	put(&ht, "hey", 1);
	put(&ht, "hola", 5);
	
	char *expr = "bverfgvefvzeq";
	
	if(contains(&ht, expr) == 1) { printf("%s contenu dans ht\n", expr); }
	else { printf("%s pas contenu dans ht\n", expr); }
	
	printf("La valeur de %s est %d\n", expr, get_value(&ht, expr));
	
	return 0;
}
