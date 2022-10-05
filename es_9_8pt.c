#include<stdio.h>
#define MAXN 20
#define MAXM 20

void displRanking(int C[MAXN][MAXM], int n, int m);

int main(){
    int C[MAXN][MAXM] = {
            {3,1,0},
            {0,1,1},
            {1,1,1},
            {1,1,3}
    }, n=4,m=3;
    displRanking(C,n,m);

}

void displRanking(int C[MAXN][MAXM], int n, int m){
    int V[MAXM] = {0},max=0,index;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            V[i] = V[i] + C[i][j];
            if(V[i]>max){
                max = V[i];
                index = i;
            }
        }
        printf("%d\n",index);
    }
}