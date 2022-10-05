#include<stdio.h>

int searchSequence(int vet[],int n,int m);

int main(){
    int vet[] = {1,2,0,3};
    int m=2,n=4,index;
    index = searchSequence(vet,n,m);
    printf("%d\n",index);
}

int searchSequence(int vet[],int n,int m){
    int a,b,count=1,primo=0,index;
    for(int i=0;i<n-1;i++){
        a = vet[i];
        b = vet[i+1];
        if(b>a && primo==0){
            count++;
            index = i;
            primo = 1;
        }
        else if(b>a)
            count++;
        else{
            count = 1;
            primo = 0;
        }

        if(count==m) return index;

    }
    return -1;
}