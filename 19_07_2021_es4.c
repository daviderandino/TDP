#include<stdio.h>
#include<ctype.h>

int copyFile(char *filename1, char *filename2);

int main(){
    char *filename1 = "../fin.txt";
    char *filename2="../fout.txt";
    int c;
    c = copyFile(filename1,filename2);
    printf("%d\n", c);
}

int copyFile(char *filename1, char *filename2){
    FILE *fin,*fout;
    char ch;
    int count = 0;
    fin = fopen(filename1,"r");
    fout = fopen(filename2,"w");
    if(!fin || !fout)
        return -1;

    while(!feof(fin)){
        ch = fgetc(fin);
        count++;
        if(isupper(ch))
            fprintf(fout,"%c", tolower(ch));
        else if(islower(ch))
            fprintf(fout,"%c", toupper(ch));
        else if(ch!=-1)
            fprintf(fout,"%c",ch);
    }
    fclose(fin); fclose(fout);
    return count;
}