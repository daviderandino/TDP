/*
Si realizzi una funzione C invertSequence con il seguente prototipo:
void invertSequence (int *v1, int n, int *v2);
La funzione riceve come parametri 2 vettori di interi v1 e v2 e la loro dimensione n e memorizza in v2 lo stesso
insieme di numeri presente in v1 ma con tutte le sottosequenze ascendenti in v1 trasformate in sottosequenze
discendenti in v2.
 */

#include<stdio.h>
#define MAX 20

void invertSequence (int *v1, int n, int *v2);

int main(){
    int v1[] = {1,2,3,4,5,0,12,13,14,2,3,4},n=12;
    int v2[MAX] = {0};
    invertSequence(v1,n,v2);
    for(int i=0;i<n;i++)
        printf("%d ",v2[i]);

}

void invertSequence (int *v1, int n, int *v2){
    int count = 0,c2=0,k,i,r;
    for(i=1;i<n;i++){
        if(v1[i]>v1[i-1])
            count++;
        else{
            r = i;
            k = i-1;
            while(count>=0){
                v2[c2] = v1[k];
                count--;
                c2++;
                k--;
            }
            count = 0;
        }
    }

    if(r<i){
        for(int j=r;j<i;j++){
            v2[c2] = v1[j];
            c2++;
        }

    }
}