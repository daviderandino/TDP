/*
 Scrivere la funzione int charErase (char str[], int pos[]); che riceve una stringa str e un
 vettore di interi pos e modifica la stringa str cancellando i caratteri nelle posizioni indicate dal vettore pos.
 Cancellazione e compattazione vanno fatte direttamente sul str. Il vettore pos ha dimensione ignota, ma il suo
 ultimo elemento contiene il valore -1. La funzione ritorna, come intero, il numero di caratteri cancellati.
 */


#include<stdio.h>
#include<string.h>

int charErase (char str[], int pos[]);

int main(){
    char s[] = "ThisIsAString";
    int pos[] = {11,7,4,2,0,-1};
    charErase(s,pos);

}

int charErase (char str[], int pos[]){
    // Il vettore pos va ordinato in ordine decrescente
    int i=0,count=0;
    while(pos[i]!=-1){
        count++;
        for(int j=pos[i];j<strlen(str);j++)
            str[j] = str[j+1];
        i++;
    }

}