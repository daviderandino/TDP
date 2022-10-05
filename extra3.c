// Ordinare un array di struct utilizzando un altro array che contiene gli indici ordinati
// Ordinare per media crescente

#include<stdio.h>

struct studente{
    int matricola;
    float media;
} typedef m;

void ordinaStruct(m *V, int V_ind[3]);

int main(){
    m V[3];
    int V_ind[3];
    V[0].matricola = 12345;
    V[1].matricola = 67890;
    V[2].matricola = 55555;
    V[0].media = 23.5;
    V[1].media = 22.1;
    V[2].media = 21.9;
    ordinaStruct(V,V_ind);
    for(int i=0;i<3;i++){
        printf("Matricola: %d, media: %.2f\n",V[i].matricola,V[i].media);
    }


}

void ordinaStruct(m *V, int V_ind[3]){
    // ordinamento della struct per matricola crescente con selection sort
    float min,temp;
    int ind;
    for(int i=0;i<3;i++){
        min = V[i].media;
        for(int j=i;j<3;j++){
            if(V[j].media<min){
                min = V[j].media;
                ind = j;
            }
        }
        if(V[i].media!=min){
            temp = V[i].media;
            V[i].media = min;
            V[ind].media = temp;
        }
    }


}