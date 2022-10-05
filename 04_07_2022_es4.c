#include<stdio.h>
#include<string.h>

void compressString(char * testo);

int main(){
    compressString("abbabbbaAAAAAaCCaDDDeeeF");
}

void compressString(char * testo){
    char a,b;
    int count=1;
    for(int i=0;i<= strlen(testo)-1;i++){
        a = testo[i];
        b = testo[i+1];
        if(a==b)
            count++;
        else if(count==1)
            printf("%c",a);
        else{
            printf("%c%d",a,count);
            count = 1;
        }
    }


}