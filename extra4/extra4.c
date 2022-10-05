/*
 Programma che legge un elenco di matricole dal file "extra4input.txt"
 Ordina un vettore di puntatori e le stampa nel file "extra4output.txt"
 */

#include<stdio.h>
#define MAX 20

struct studente{
    int matricola;
    float media;
} typedef stud;

void leggi_stud(stud lista_studenti[MAX],int *n);
void ordina_studByRefMatricola(stud **rifMat,int n);
void ordina_studByRefMedia(stud **rifMedia,int n);
void stampa_stud(stud **rifMat,stud **rifMedia,int n);

int main(){
    int n;
    stud lista_studenti[MAX];
    stud *rifMat[MAX];
    stud *rifMedia[MAX];
    leggi_stud(lista_studenti,&n);
    for(int i=0;i<n;i++){
        rifMat[i] = &lista_studenti[i];
        rifMedia[i] = &lista_studenti[i];
    }
    ordina_studByRefMatricola(rifMat,n);
    ordina_studByRefMedia(rifMedia,n);
    stampa_stud(rifMat,rifMedia,n);
}

void ordina_studByRefMedia(stud **rifMedia,int n){
   stud *temp;
   int i,j,imin;
   for(i=0;i<n-1;i++){
       imin = i;
       for(j=i+1;j<n;j++){
           if(rifMedia[j]->media<rifMedia[imin]->media)
               imin = j;
       }
       temp = rifMedia[i];
       rifMedia[i] = rifMedia[imin];
       rifMedia[imin] = temp;
   }
}

void ordina_studByRefMatricola(stud **rifMat,int n){
    stud *temp;
    int i,j,imin;
    for(i=0;i<n-1;i++){
        imin = i;
        for(j=i+1;j<n;j++){
            if(rifMat[j]->matricola<rifMat[imin]->matricola)
                imin = j;
        }
        temp = rifMat[i];
        rifMat[i] = rifMat[imin];
        rifMat[imin] = temp;
    }
}

void stampa_stud(stud **rifMat,stud **rifMedia,int n){
    printf("--Studenti Ordinati per matricola crescente--\n");
    for(int i=0;i<n;i++){
        printf("%d ",rifMat[i]->matricola);
        printf("%.2f\n",rifMat[i]->media);
    }
    printf("--Studenti Ordinati per media crescente--\n");
    for(int i=0;i<n;i++){
        printf("%d ",rifMedia[i]->matricola);
        printf("%.2f\n",rifMedia[i]->media);
    }
}

void leggi_stud(stud lista_studenti[MAX],int *n){
    FILE *fin;
    *n = 0;
    fin = fopen("../extra4input.txt","r");
    while(!feof(fin)){
        fscanf(fin,"%d",&lista_studenti[*n].matricola);
        fscanf(fin,"%f",&lista_studenti[*n].media);
        *n = *n + 1;
    }
    fclose(fin);
}