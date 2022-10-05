#include<stdio.h>
#include<math.h>

#define MAX 100

typedef struct {
    char surname[MAX],name[MAX];
    int id;
    float avg;
} student_t;

int mostFrequent(student_t s[], int n);
void printStudents(student_t s[], int n, int select);

int main(){
    int max_media;
    student_t s[6];
    s[0].avg = 18.1;
    s[1].avg = 22.1;
    s[2].avg = 28.7;
    s[3].avg = 21.9;
    s[0].id = 00000;
    s[1].id = 11111;
    s[2].id = 22222;
    s[3].id = 33333;
    int n=4;
    max_media = mostFrequent(s,n);
    printStudents(s,n,max_media);

}

void printStudents(student_t s[], int n, int select){
    int m;
    for(int i=0;i<n;i++){
        m = roundf(s[i].avg);
        if(m == select)
            printf("%d\n",s[i].id);
    }
}

int mostFrequent(student_t s[], int n){
    int V[31] = {0};
    int m,max_occ=0,max_media=0;
    for(int i=0;i<n;i++){
        m = roundf(s[i].avg);
        V[m]++;
    }
    for(int i=30;i>18;i--){
        if(V[i]>max_occ){
            max_occ = V[i];
            max_media = i;
        }
    }
    return max_media;
}