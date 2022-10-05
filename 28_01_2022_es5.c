/*
 Scrivere una funzione C con il seguente prototipo:

 int findOddSubSequence(int vet[], int n);

 dove vet è un vettore di interi ed n è il numero di elementi in esso contenuti. La funzione deve
 calcolare la sequenza di numeri dispari di lunghezza massima contenuta in vet. La funzione ritorna
 l’indice del primo elemento di tale sequenza (in caso di più sequenze di pari lunghezza, ritornare
 l’indice della prima sequenza trovata). Se vet non contiene elementi dispari, restiture -1.
 */

#include<stdio.h>

int findOddSubSequence(int vet[], int n);

int main(){
    int vet[]={1,2,1,1,3,4},n=6,i;
    i = findOddSubSequence(vet,n);
    printf("%d\n",i);
}

int findOddSubSequence(int vet[], int n){
    int len = 0,len_max=0,index;
    for(int i=0;i<n;i++){
        if(vet[i]%2==1)
            len++;
        else if(len>len_max){
            len_max = len;
            index = i-len_max;
            len = 0;
        }
        else
            len = 0;
    }

    if(len_max>0) return index;
    else return -1;

}