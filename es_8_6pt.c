/*
Data una matrice quadrata N x N, con N dispari (N<=MAXN, con MAXN costante), scrivere una funzione
caratterizzata dal seguente prototipo:
int sommaCornici(int mat[MAXN][MAXN], int N, int vet[]);
che memorizzi nel vettore vet, che si suppone di dimensione sufficiente a contenere il risultato, la somma degli
elementi su ogni cornice della matrice. La funzione deve ritornare come risultato intero il numeri di cornici.
A titolo di esempio, la seguente matrice 5x5 è caratterizzata dalla presenza di 3 cornici, evidenziate per facilità di
comprensione da toni diversi (bianco, grigio chiaro, grigio scuro). Si osservi che esiste una cornice formata dal
solo elemento centrale.
 */

#include<stdio.h>
#include<stdlib.h>

#define MAXN 10

int sommaCornici(int mat[MAXN][MAXN], int N, int vet[]);

int main(){
    int mat[MAXN][MAXN] = {
            {1,2,3,4,5},
            {6,7,8,9,0},
            {1,2,3,4,5},
            {6,7,8,9,0},
            {1,1,1,1,1}
    };
    int N=5;
    int vet[MAXN] = {0};
    sommaCornici(mat,N,vet);
    for(int i=0;i<N-2;i++)
        printf("%d ",vet[i]);
}

int sommaCornici(int mat[MAXN][MAXN], int N, int vet[]){
    for(int i=0;i<N;i++){
        for(int j=i;j<=N-1-i;j++){
            vet[i] = vet[i] + mat[i][j];
        }
    }
    for(int j=0;j<N;j++){
        for(int i=j;i<=N-1-j;i++){
            if(i!=j) vet[j] = vet[j] + mat[i][j];
        }
    }
    for(int i=N-1;i>0;i--){
        for(int j=N-i-1;j<=i;j++){
            if(i!=N-j-1) vet[N-i-1] = vet[N-i-1] + mat[i][j];
        }
    }
    for(int j=N-1;j>0;j--){
        for(int i=j-1;i>=N-j;i--){
            if(i!=j){
                vet[N-j-1] = vet[N-j-1] + mat[i][j];
            }

        }
    }



}