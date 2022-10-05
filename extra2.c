// Stampa tutti i sottovettori di lunghezza 3 tali che l'intero centrale sia 0

#include<stdio.h>

void printSpecialSubvectors(int *V, int N);

int main(){
    int V[] = {3,4,5,0,2,3,0,0,7,5,3,0,3},N=13;
    printSpecialSubvectors(V,N);
}

void printSpecialSubvectors(int *V, int N){
    for(int i=1;i<N-1;i++){
        if(V[i]==0 && V[i-1]!=0 && V[i+1]!=0)
            printf("[%d,%d,%d]\n",V[i-1],V[i],V[i+1]);
    }

}