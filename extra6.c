/*
 Ordinare V mediante l'utilizzo di un vettore di puntatori (quindi ordinare i puntatori)
 */


#include<stdio.h>
#define MAX 3

void ordinaVectByRef(int **p);

int main(){
    int V[MAX] = {3,1,2};
    int *p[MAX];
    for(int i=0;i<MAX;i++){
        p[i] = &V[i];
    }
    ordinaVectByRef(p);
    for(int i=0;i<MAX;i++){
        printf("%d\n",*p[i]);
    }

}

void ordinaVectByRef(int **p){
    int imin,*temp;
    for(int i=0;i<MAX;i++){
        imin = i;
        for(int j=i+1;j<MAX;j++){
            if(*p[j]<*p[imin])
                imin = j;
        }
        if(imin!=i){
            temp = p[i];
            p[i] = p[imin];
            p[imin] = temp;
        }
    }
}