#include<stdio.h>
#define MAXR 20
#define MAXC 20

int buildMatrix(int V[], int N, int M[MAXR][MAXC], int nr, int nc);

int main(){
    int M[MAXR][MAXC];
    int V[] = {1, 2, 17, 2, 3, 1, 8, 4, 6, 1, 7, 3, 5, 2},nr=3,nc=5,N=14;
    buildMatrix(V,N,M,nr,nc);
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }

}

int buildMatrix(int V[], int N, int M[MAXR][MAXC], int nr, int nc){
    int i=0,j=0,num,rip;
    for(int k=0;k<N-1;k+=2){
        num = V[k];
        rip = V[k+1];
        for(int l=0;l<rip;l++){
            if(j>nc-1){
                l=0;
                j=0;
                i++;
            }
            M[i][j] = num;
            j++;
        }
    }

}