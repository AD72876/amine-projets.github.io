#include<stdio.h>
#include<stdlib.h>


typedef struct{
long int a,b,d;} GaussType;

void GaussAffiche(GaussType x,int cr){
printf("(%ld %s %ld V5) / %ld%s",
	x.a,
	x.b<0?"-":"+",
	x.b<0?-x.b:x.b,
	x.d,
	cr?"\n":" ");
	}
long int pgcd(long int a, long int b){
	if (a<0) a=-a;
	if (b<0) b=-b;
	if (b==0) return a; 
	while (a){
		b%=a;
		if (b==0) return a;
		a%=b;
		}
	return b;
}
void Reduire(GaussType *x){
	long int p;
	long int y;
	p=pgcd(x->a,x->b);
	y=pgcd(p,x->d);
	printf("%ld \n",y);
	if (y!=1){
	x->a=x->a/y;
	x->b=x->b/y;
	x->d=x->d/y;
	}
	

}
int main(void){
GaussType x;
x.a=9;
x.b=-72;
x.d=-45;
GaussAffiche(x,1);
Reduire(&x);
GaussAffiche(x,1);
return 0;
}


