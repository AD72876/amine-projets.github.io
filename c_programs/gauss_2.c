#include<stdio.h>
#include<stdlib.h>
#include<math.h>


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
void GaussAdd(GaussType*s,GaussType x,GaussType y){
s->a=y.d*x.a+x.d*y.a;
s->b=(y.d*x.b+x.d*y.b);
s->d=(x.d*y.d);
Reduire(s);
}
void GaussMul(GaussType*p,GaussType x,GaussType y){
p->a=x.a+y.a+5*x.b*y.b;
p->b=(x.a*y.b+y.a*x.b);
p->d=x.d*y.d;
Reduire(p);
}
int main(void){
GaussType x;
x.a=-1;
x.b=5;
x.d=45;
GaussType y;
y.a=-6;
y.b=7;
y.d=100;
GaussType s,p;
GaussAdd(&s,x,y);
GaussMul(&p,x,y);
printf("Somme = ");
GaussAffiche(s,1);
printf("Produit = ");
GaussAffiche(p,1);


return 0;
}


