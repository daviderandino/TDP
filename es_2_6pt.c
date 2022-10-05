/*
 Sia data un vettore V di N interi. Si scriva una funzione C che visualizzi tutti i sottovettori di dimensione
 massima formati da celle contigue contenenti dati dispari. La funzione abbia prototipo:
 void maxOdd(int v[], int N);
 */

#include<stdio.h>

void maxOdd(int v[], int N);

int main(){
    int v[] = {1,3,7,1,0,1,9,3,1,3,0};
    int N=11;
    maxOdd(v,N);
}

void maxOdd(int v[], int N){
    int max_len = 1,a,b,count=1;

    for(int i=0;i<N-1;i++){
        a = v[i];
        b = v[i+1];
        if(a%2==1 && b%2==1)
            count++;
        else if(count>max_len){
            max_len = count;
            count = 1;
        } else count = 1;
    }

    count = 1;
    for(int i=0;i<N-1;i++){
        a = v[i];
        b = v[i+1];
        if(a%2==1 && b%2==1)
            count++;
        else
            count=1;
        if(count==max_len){
            for(int j=i+2-count;j<=i+1;j++)
                printf("%d ",v[j]);
            printf("\n");
            count = 1;
        }
    }


}