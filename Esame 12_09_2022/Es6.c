#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char matricola[7];
    char name[30];
    int score;
} student;

int selectStudents(student listStudents[100], int n,student **selStudents, int threshold);
void printResults(student **selStudents, int nSuff, char *argv[2]);

int selectStudents(student listStudents[100], int n,student **selStudents, int threshold){
    int count=0,i;
    for(i=0;i<n;i++){
        if(listStudents[i].score>=threshold){
            selStudents[count] = &listStudents[i];
            count++;
        }
    }
    return count;
}

void printResults(student **selStudents, int nSuff, char *argv[2]){
    FILE *fp = fopen(argv[1],"r");
    int i,matricola;
    for(i=0;i<nSuff;i++){
        matricola = atoi(selStudents[i]->matricola);
        matricola+=100;
        fprintf(fp,"%d %d\n",matricola,selStudents[i]->score);
    }
    fclose(fp);
}