#include<stdio.h>
#include<stdlib.h>

void PrintPol(long unsigned x){
	int compteur=0;
	int plus = 0;
	while(compteur<64)
	{
	if((x&1)==1 && compteur==0){
	plus =  1;
	printf("1");
	}
	else if((x&1)==1){
	plus = 1;
	printf("X^%d",compteur);
	}
	x=x>>1;
	if(x!=0 && (x&1)==1 && plus==1){
	printf(" + ");
	}
	compteur++;
      	}
	printf("\n");
}
int main(void){
	long unsigned x;
	printf("Donner la valeur de x\n");
	scanf("%lu", &x);
	PrintPol(0x123);
	return 0;
}

