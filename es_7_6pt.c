/*
    Sia data una un main che riceve come argomenti un certo numero di stringhe. Si ignori argv[0] e si consideri
    l’ultima stringa argv[argc-1]. Si vuole contare quante volte tale stringa compare nelle precedenti, ignorando la
    differenza tra lettere maiuscole e minuscole. Si realizzi a tale scopo la funzione:
    int conta(char *parole[], int nparole, char *cerca);
    Si mostri inoltre come tale funzione viene chiamata nel main.
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int conta(char *parole[], int nparole, char *cerca);

void lowerizza(char *string);

int main(int argc, char *argv[]){
    int n;
    n = conta(argv,argc-2,argv[argc-1]);
    printf("%d\n",n);


}

int conta(char *parole[], int nparole, char *cerca){
    lowerizza(cerca);
    int count=0;
    for(int i=1;i<=nparole;i++){
        lowerizza(parole[i]);
        if(strstr(parole[i],cerca))
            count++;
    }
    return count;
}

void lowerizza(char *parola) {
    for(int j=0;j< strlen(parola);j++)
        parola[j] = tolower(parola[j]);

}
