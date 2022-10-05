/*
 Dato un vettore V di struct, ordinare un vettore di puntatori al vettore di struct in ordine decrescente
 di media. Successivamente stampare nel file solo le matricole con media >=24.0
 */

#include<stdio.h>
#define MAX 20

struct matricola{
    int matricola;
    float media;
} typedef mat;

void leggi_matricole(mat lista_matricole[MAX],int *n);
void ordina_rif(mat **rif,int n);
void stampa_matByRef(mat **rif,int n);
void stampa_InFile(mat **rif,int n);

int main(){
    mat lista_matricole[MAX];
    mat *rif[MAX];
    int n=0;
    leggi_matricole(lista_matricole,&n);
    for(int i=0;i<n;i++)
        rif[i] = &lista_matricole[i];
    ordina_rif(rif,n);
    // stampa_matByRef(rif,n);
    stampa_InFile(rif,n);
}

void stampa_InFile(mat **rif,int n){
    FILE *fout = fopen("../extra8out.txt","w");
    for(int i=0;i<n;i++){
        if(rif[i]->media>=24)
            fprintf(fout,"%d : %.2f\n",rif[i]->matricola,rif[i]->media);
    }
}

void stampa_matByRef(mat **rif,int n){
    for(int i=0;i<n;i++){
        printf("%d : %.2f\n",rif[i]->matricola,rif[i]->media);
    }
}

void ordina_rif(mat **rif,int n){
    int imin;
    mat *temp;
    for(int i=0;i<n;i++){
        imin = i;
        for(int j=i+1;j<n;j++){
            if(rif[j]->media>rif[imin]->media)
                imin = j;
        }
        if(imin!=i){
            temp = rif[i];
            rif[i] = rif[imin];
            rif[imin] = temp;
        }
    }
}

void leggi_matricole(mat lista_matricole[MAX],int *n){
    FILE *fin = fopen("../extra8.txt","r");
    while(!feof(fin)){
        fscanf(fin,"%d",&lista_matricole[*n].matricola);
        fscanf(fin,"%f",&lista_matricole[*n].media);
        (*n)++;
    }
    fclose(fin);

}