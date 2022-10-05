#include<stdio.h>
#include<string.h>
#include<ctype.h>

int textStats(char* filename);

int main(){
    char filename[] = "../file180722.txt";
    int count;
    count = textStats(filename);
    printf("%d\n",count);

}

int textStats(char* filename){
    FILE *fp = fopen(filename,"r");
    char str[21];
    int flag,count_parole=0,count_maiu=0,count_voc=0,max_len=0;
    int vet[20] = {0};

    while(!feof(fp)){
        flag=1;
        fscanf(fp,"%s",str);
        if(strlen(str)>max_len) max_len = strlen(str);
        vet[strlen(str)]++;
        count_parole++;
        for(int i=0;i< strlen(str);i++){
            if(islower(str[i]))
                flag = 0;
            if(strchr("AEIOUaeiou",str[i]) == 0)
                count_voc++;
        }
        if(flag==1)
            count_maiu++;
    }

    for(int i=1;i<=max_len;i++)
        printf("%d strings with length %d\n",vet[i],i);

    printf("%.2f % with all capital letters\n",(float)count_maiu/count_parole*100);
    printf("Average number of vowels: %.2f\n",(float)count_voc/count_parole);
    return count_parole;

}

