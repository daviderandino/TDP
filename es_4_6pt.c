/*
 Sia data una stringa S di caratteri. Si scriva una funzione C che conti quante sottostringhe di n caratteri in essa
 contenute hanno 2 vocali. Si ricorda che in C non esiste una funzione (quindi va realizzata) che determini se un
 carattere sia costante o vocale La funzione abbia prototipo:
 void countAndPrint(char str[], int n);
 */

#include<stdio.h>
#include<string.h>

void countAndPrint(char str[], int n);

int main(){
    char s[] = "forExample";
    int n=4;
    countAndPrint(s,n);
}

void countAndPrint(char str[], int n){
    char vocali[] = "aeiouAEIOU";
    int count_vocali = 0,count=0;
    for(int i=0;i< strlen(str)-4;i++){
        for(int j=i;j<i+n && count_vocali!=2;j++){
            if(strchr(vocali,str[j]))
                count_vocali++;
            if(count_vocali==2)
                count++;
        }
        count_vocali=0;
    }
    printf("%d",count);


}