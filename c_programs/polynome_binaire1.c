#include<stdio.h>
#include<stdlib.h>

void PrintBinary(long unsigned x){
	int compteur;
	compteur=sizeof(x) * 8 - 1;
	printf("Un long unsigned int fait %d bits\n", compteur+1);
	printf("En écriture binaire x vaut :\n");
	while(compteur >=0)
	{
	printf("%lu", (x>>compteur) & 1);
	compteur --;
      	}
	printf("\n");
}
int main(void){
	long unsigned x;
	printf("Donner la valeur de x\n");
	scanf("%lu", &x);
	PrintBinary(x);
	return 0;
}

