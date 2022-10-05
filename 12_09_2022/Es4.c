#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void printDate(char *date);

void printDate(char *date){
    char nome_mese[20],mese[3],anno[5],giorno[3];
    int n_mese,n_giorno,n_anno;
    if(date[2]!='-' || date[5]!='-'){
        printf("errore"); return;
    }
    if((isdigit(date[0]) && date[0]>'3') || (isdigit(date[4] && date[4]>'2' && date[3]=='0')) || (isdigit(date[3]) && date[3]>'1')){
        printf("errore"); return;
    }
    for(int i=0;i< strlen(date);i++){
        if(!isdigit(date[i]) && i!=2 && i!=5){
            printDate("errore"); return;
        }
    }
    mese[0] = date[3]; mese[1] = date[4];
    n_mese = atoi(mese);
    giorno[0] = date[0]; giorno[1] = date[1];
    n_giorno = atoi(giorno);
    anno[0] =date[6]; anno[1] = date[7]; anno[2] = date[8]; anno[3] = date[9];
    n_anno = atoi(anno);

    switch (n_mese) {
        case(1):
            strcpy(nome_mese,"Gennaio");
            break;
        case(2):
            strcpy(nome_mese,"Febbraio");
            break;
        case(3):
            strcpy(nome_mese,"Marzo");
            break;
        case(4):
            strcpy(nome_mese,"Aprile");
            break;
        case(5):
            strcpy(nome_mese,"Maggio");
            break;
        case(6):
            strcpy(nome_mese,"Giugno");
            break;
        case(7):
            strcpy(nome_mese,"Luglio");
            break;
        case(8):
            strcpy(nome_mese,"Agosto");
            break;
        case(9):
            strcpy(nome_mese,"Settembre");
            break;
        case(10):
            strcpy(nome_mese,"Ottobre");
            break;
        case(11):
            strcpy(nome_mese,"Novembre");
            break;
        case(12):
            strcpy(nome_mese,"Dicembre");
            break;
    }

    printf("%d %s %d",n_giorno,nome_mese,n_anno);

}