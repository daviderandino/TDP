/*
Si scriva un programma C che, dato un intero N, generi una matrice quadrata NxN con tutti 0 sulla diagonale
principale, tutti 1 sulle 2 diagonali immediatamente sopra e sotto, tutti 2 su quelle sopra e sotto le precedenti, etc,
come nel seguente esempio per N=5
 */

#include<string.h>
#include<stdio.h>
#include<math.h>
#define MAX 20

void generaMatrice (int N);

int main(){
    int N=5;
    generaMatrice(N);


}

void generaMatrice (int N){
    int M[MAX][MAX] = {0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            M[i][j] = abs(i-j);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }

}

