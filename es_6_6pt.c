/*
 Sia data una matrice di caratteri A di dimensioni n × m ed una stringa s.
 Si scriva una funzione C che conti quante volte la stringa è contenuta nelle righe e nelle colonne della matrice.
 La stringa va considerata in orizzontale da sinistra a destra o in verticale dall’alto al basso. Il prototipo della
 funzione sia:
 int count(char A[][MAXM], int n, int m, char str[]);
 */

#include<stdio.h>
#include<string.h>
#define MAXM 5

int count(char A[][MAXM], int n, int m, char str[]);

int main(){
    char A[][MAXM] = {
            "xceca",
            "waecq",
            "dtpaz",
            "pcatf"
    };
    int n=4,m=5,conta;
    char str[] = "cat";
    conta = count(A,n,m,str);
    printf("%d",conta);

}

int count(char A[][MAXM], int n, int m, char str[]){
    char x[MAXM];
    int conta=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            x[j] = A[i][j];
        }
        if(strstr(x,str))
            conta++;
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<m;i++){
            x[i] = A[i][j];
        }
        if(strstr(x,str))
            conta++;
    }
    return conta;

}