/*
 Funzione in C che verifica se esiste una sottostringa di s2 di lunghezza d che è sottostringa di s1.
 In caso di successo la funzione ritorna 1, altrimenti -1
 */

#include<stdio.h>
#include<string.h>

int checkSubstrLengthD(char s1[],char s2[],int d);

int main(){
    char s1[] = "annappo",s2[] = "app";
    int d=6,check;
    check = checkSubstrLengthD(s1,s2,d);
    printf("%d\n",check);


}

int checkSubstrLengthD(char s1[],char s2[],int d){
    int c=0;
    char str[20];
    for(int i=c;i<d+c && i< strlen(s1);i++){
        str[i-c] = s1[i];
        if(i==d+c-1 && strstr(str,s2)>0)
            return 1;
        else if(i==d+c-1)
            c++;
    }
    return -1;


}