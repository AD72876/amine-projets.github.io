#include <stdio.h>

int main(){
    int t = 8;
    int L[]={0,1,1,0,0,1,0,1};
    int taille = t;
    int i;

    for(i=0;taille!=1;i++){
        taille  = taille/2;

        int j = 0;
        int count = 0;
        while(j != t){
            count++;
            int n = 0;
            while(n != taille && count%2 == 1){
                printf("[%d]", L[j]);§
                n++;
                j++;
            }
            while(n != taille && count%2 == 0){
                L[j] = (L[j] + L[j-taille])%2;
                printf("[%d]", L[j]);
                n++;
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}
