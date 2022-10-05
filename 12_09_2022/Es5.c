#include<stdio.h>
#include<string.h>

char *findSequence(char s[],char ch, int n);

char *findSequence(char s[],char ch, int n){
    int count=0,i;
    for(i=0;i<strlen(s);i++){
        if(s[i]==ch) count++;
        else count=0;
        if(count==n) return (s+i-n+1);
    }
    return NULL;
}
