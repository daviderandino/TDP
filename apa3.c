#include<stdio.h>
#define MAX 20

int subMatMax (int mat[MAX][MAX], int r, int c);

int main(){
    int r=3,c=4;
    int mat[][MAX] = {
            {5,2,3,1},
            {3,1,6,4},
            {3,0,5,2}
    };
    subMatMax(mat,r,c);

}

int subMatMax (int mat[MAX][MAX], int r, int c){
    int V[4],sum,sum_max=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i+1<r && j+1<c){
                sum = mat[i][j]+mat[i][j+1]+mat[i+1][j]+mat[i+1][j+1];
                if(sum>sum_max){
                    sum_max = sum;
                    V[0] = mat[i][j]; V[1] = mat[i][j+1]; V[2] = mat[i+1][j]; V[3] = mat[i+1][j+1];
                }
            }
        }
    }

    printf("Sottomatrice massima:\n%d %d \n%d %d\n",V[0],V[1],V[2],V[3]);

}