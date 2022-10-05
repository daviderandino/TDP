#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

int strFindSimilar(char str1[], char str2[]);

int main(){
    char str1[] = "FifthOfNovember";
    char str2[] = "September";
    int ind;
    ind = strFindSimilar(str1,str2);
    printf("%d",ind);
}

int strFindSimilar(char str1[], char str2[]){
    int len = strlen(str2)/2;
    if(strlen(str2)%2==1)
        len++;
    int c=0,count=0;
    while(c< strlen(str1)- strlen(str2)){
        for(int i=c;i< strlen(str2)+c;i++){
            for(int j=0;j< strlen(str2);j++){
                if(str1[i]==str2[j])
                    count++;
                if(count>=len)
                    return i-len;
            }
        }
        count=0;
        c++;
    }
    return -1;
}