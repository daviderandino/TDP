/*
Si implementi la funzione
void searchStr (char *str, int *start, int *length);
che riceve in ingresso la stringa str e rintraccia in tale stringa la sequenza di caratteri uguali di lunghezza
maggiore, ritornandone l'indice di inizio nella variabile start e la sua lunghezza nella variabile length.
Ad esempio, se la funzione ricevesse la stringa
abbcccddddeeeee
dovrebbe rintracciare la sequenza eeeee e ritornare i valori start = 10 e length = 5.
 */

#include<stdio.h>
#include<string.h>

void searchStr (char *str, int *start, int *length);

int main(){
    char str[] = "abbcccddddeeeee";
    int start,length;
    searchStr(str,&start,&length);
    printf("Lenght: %d\nStart: %d\n",length,start);

}

void searchStr (char *str, int *start, int *length){
    int l = 0;
    *length = 0;

    for(int i=0;i< strlen(str);i++){
        if(str[i]==str[i+1]){
            l++;
            if(l>*length) {
                *length = l;
                *start = i+1 - l;
            }
        }
        else{
            if(l>*length){
                *length = l;
                *start = i - l;
                l = 0;
            }
            else l =0;
        }
    }
    *(length) = *length+1;



}