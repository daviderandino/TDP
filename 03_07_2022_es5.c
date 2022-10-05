#include<stdio.h>
#define DIM 20

float matrMaxDiag(float M[DIM][DIM],int n);

int main(){
    float M[DIM][DIM] = {
            {1.0,2.0,3.0,4.0,5.0},
            {2.0,2.0,2.0,2.0,-2.0},
            {1.1,2.2,3.3,-4.4,5.5},
            {2.2,2.2,-3.2,4.2,4.2},
            {1.8,-2.3,3.1,4.9,5.0}
    },avg_max;
    avg_max = matrMaxDiag(M,5);
    printf("%f",avg_max);

}

float matrMaxDiag(float M[DIM][DIM],int n){
    float V1[DIM] = {0},V2[DIM] = {0},V1_count[DIM]={0},V2_count[DIM]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=n-1;k>=0;k--){
                if(i==j-k){
                    V1[k] = M[i][j] + V1[k];
                    V1_count[k]++;
                }
                if(i==j+k){
                    V2[k] = M[i][j] + V2[k];
                    V2_count[k]++;
                }
            }
        }
    }
    float avg_max = 0,avg;
    for(int i=0;i<n;i++){
        avg = V1[i] / V1_count[i];
        if(avg>avg_max)
            avg_max = avg;
        avg = V2[i] / V2_count[i];
        if(avg>avg_max)
            avg_max = avg;
    }
    return avg_max;
}