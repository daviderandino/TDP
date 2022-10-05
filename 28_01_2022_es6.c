/*
 Un campo minato viene rappresentato schematicamente con una matrice di caratteri, dove il
carattere '*' rappresenta una mina e il carattere '-' rappresenta un punto di passaggio sicuro.
Scrivere una funzione C che cerca un percorso per attraversare il campo minato da sinistra a destra,
evitando le mine. Fare le seguenti assunzioni:
- Il punto di partenza può essere solo nella prima colonna della matrice di caratteri.
- Ci si può muovere solo da sinistra a destra, da un punto di passaggio sicuro ad un altro che si
trova nella colonna seguente.
- Ci si può muovere orizzontalmente (nella stessa riga), o diagonalmente nella riga superiore o
inferiore.
- A partire da una sola cella, non ci sono più punti di passaggio sicuri su cui ci si può muovere.
Non ci sono cioè percorsi alternativi da dover esplorare, ma la scelta è sempre unica.
La funzione deve avere questo prototipo:
int findPath(char minefield[][M],int nr, int nc);
 */

#include<stdio.h>
#define M 20

int findPath(char minefield[][M],int nr, int nc);

int main(){
    char minefield[][M] = {
           "--*-*-****-",
           "**-*-***--*",
           "****-*-****",
           "--*-*-*-*-*",
           "**-*-***-*-"
    };
    int nr=4,nc=11,i;
    i = findPath(minefield,nr,nc);
    printf("%d\n",i);
}

int findPath(char minefield[][M],int nr, int nc){
    int flag;
    for(int i=0;i<nr;i++){
        flag=1;
        for(int j=0;j<nc-1 && flag==1;j++){
            if(!(minefield[i][j+1]=='-' || minefield[i-1][j+1] == '-' || minefield[i+1][j+1]=='-')) flag = 0;
        }
        if(flag==1) return i;
    }

}