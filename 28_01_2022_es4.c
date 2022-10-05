/*
 Negli Stati Uniti, i numeri di telefono sono scritti nel formato: (###)###-####, dove # rappresenta una
 cifra da 0 a 9. Scrivere la funzione C isValid con il seguente prototipo:
 int isValid(char listOfNumbers[][M], int n);

 dove listOfNumbers è un vettore di stringhe, n è il numero di numeri di telefono contenuti in
 listOfNumbers, uno per riga, e M è una costante di valore 14. La funzione deve controllare che ogni
 numero di telefono sia nel formato corretto: se tutti i numeri sono nel formato corretto, la funzione
 restituisce 1; se anche solo un numero non è nel formato corretto, la funzione deve ritornare 0.
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define M 14

int isValid(char listOfNumbers[][M], int n);

int main(){
    char listOfNumbers[][M] = {
            "(039)123-4567", "(039)123-4577","(077)113-4567", "(074)124-4557"
    };
    int n=4,f;
    f = isValid(listOfNumbers,n);
    printf("%d\n",f);
}

int isValid(char listOfNumbers[][M], int n){
    for(int i=0;i<n;i++){
        if(listOfNumbers[i][0]!='('||listOfNumbers[i][4]!=')'||listOfNumbers[i][8]!='-')
            return 0;
        for(int j=0;j<strlen(listOfNumbers[i]);j++){
            if(!isdigit(listOfNumbers[i][j]) && j!=0 &j!=4 && j!=8)
                return 0;
        }
    }
    return 1;

}