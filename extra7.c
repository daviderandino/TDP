/*
 Dato un vettore di struct humans, creare un vettore di puntatori e ordinare per età crescente
 */

#include<stdio.h>
#define N 5

struct humans{
    int eta;
} typedef hum;

void ordinaHumansByRef(hum **p);

int main(){
    hum lista_umani[N];
    hum *p[N];
    for(int i=0;i<N;i++)
        p[i] = &lista_umani[i];
    lista_umani[0].eta = 2;
    lista_umani[1].eta = 1;
    lista_umani[2].eta = 15;
    lista_umani[3].eta = 10;
    lista_umani[4].eta = 9;
    ordinaHumansByRef(p);

    for(int i=0;i<N;i++)
        printf("%d\n",p[i]->eta);
}

void ordinaHumansByRef(hum **p){
    hum *temp;
    int imin;
    for(int i=0;i<N;i++){
        imin = i;
        for(int j=i+1;j<N;j++){
            if(p[j]->eta<p[imin]->eta)
                imin = j;
        }
        if(imin!=i){
            temp = p[i];
            p[i] = p[imin];
            p[imin] = temp;
        }
    }
}