/*
 Ordinare un vettore di puntatore a struct che contiene numeri interi
 */

#include<stdio.h>

struct interi{
    int n;
};

ordinaRef(struct interi **ref);

int main(){
    struct interi V[3];
    V[0].n = 2;
    V[1].n = 3;
    V[2].n = 1;
    struct interi *ref[3];
    for(int i=0;i<3;i++)
        ref[i] = &V[i];
    ordinaRef(ref);

    for(int i=0;i<3;i++)
        printf("%d\n",ref[i]->n);

}

ordinaRef(struct interi **ref){
    int imin;
    struct interi *temp;
    for(int i=0;i<3;i++){
        imin = i;
        for(int j=i+1;j<3;j++){
            if(ref[imin]->n>ref[j]->n){
                imin = j;
            }
        }
        if(imin!=i){
            temp = ref[i];
            ref[i] = ref[imin];
            ref[imin] = temp;
        }
    }
}
