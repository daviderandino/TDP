/*
 Siano dati 2 vettori di interi (positivi, negativi o nulli) v1 e v2 di lunghezza rispettivamente d1 e d2. Si scriva una
 funzione prodCartFilt che stampi il prodotto cartesiano dei due vettori, filtrato eliminando le coppie di
 numeri uguali o che differiscano di 1.
 Il prototipo della funzione prodCartFilt sia:
 void prodCartFilt(int *v1, int d1, int *v2, int d2) ;
 Si ricorda che il prodotto cartesiano di due insiemi è dato dall’insieme di tutte le possibili coppie di un elemento
 del primo e di uno del secondo insieme.
 */

#include<stdio.h>
#include<math.h>

void prodCartFilt(int *v1, int d1, int *v2, int d2);

int main(){
    int v1[] = {1,2,3};
    int v2[] = {3,4,5,6};
    int d1=3,d2=4;
    prodCartFilt(v1,d1,v2,d2);
}

void prodCartFilt(int *v1, int d1, int *v2, int d2){

    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            if(abs(v2[j]-v1[i])>1)
                printf("(%d,%d)",v1[i],v2[j]);
        }
    }

}