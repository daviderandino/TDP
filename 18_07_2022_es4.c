#include<stdio.h>
#include<string.h>
#include<ctype.h>

char* findSubstring(char s1[], char s2[]);
char* findSubstringVERS2(char s1[], char s2[]);

int main(){
    char s1[] = "limilano";
    char s2[] = "la";
    char *ch;
    ch = findSubstringVERS2(s1,s2);
    printf("%c",*ch);
}

char* findSubstringVERS2(char s1[], char s2[]){
    int count=0,len= strlen(s2);
    for(int i=0;i< strlen(s2);i++){
        for(int j=0;j< strlen(s1);j++){
            if(s2[i]==s1[j]){
                i++;
                count++;
                if(count==len)
                    return (s1+j)-len+1;
            } else{
                count=0;
                if(i>0) i--;
            }
        }
    }
}

char* findSubstring(char s1[], char s2[]){
        int l1,l2,i, j, equal;
        l1 = strlen(s1);
        l2 = strlen(s2);
        for (i=0; (l2<=l1)&&(i<=l1-l2);i++)
        {
            equal = 1;
            for(j = 0; j < l2; j++){
                if(tolower(*(s1+i+j)) != tolower(*(s2+j)))
                    equal = 0;
            }
            if (equal == 1)
                return s1+i;
        }
        return NULL;
}
