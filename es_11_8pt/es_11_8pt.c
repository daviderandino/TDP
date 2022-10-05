#include<stdio.h>
#include<math.h>


int areaTot(FILE *fp);

int main(){
    FILE *fp = fopen("../file11.txt","r");
    int area;
    area = areaTot(fp);
    printf("%d\n",area);
}

int areaTot(FILE *fp){
    int V1[4],V2[4],h1,l1,h2,l2,h_com,l_com,area,i,n,c=0,j=0,y_max,y_min;
    char riga[10],*p;

    while(!feof(fp)){
        fgets(riga,10,fp);
        p = riga;
        j=0;
        while(sscanf(p,"%d%n",&n,&i)>0){
            p = p+i;
            if(c==0) V1[j] = n;
            else if(c==1) V2[j] = n;
            j++;
        }
        c++;
    }
    l1 = V1[2]-V1[0];
    l2 = V2[2]-V2[0];
    if(V1[3]>V2[3]){
        y_max = V1[3];
    } else{
        y_max = V2[3];
    }
    if(V1[1]<V2[1]){
        y_min = V1[1];
    } else{
        y_min = V2[1];
    }

    h_com = y_max-y_min-(V2[3]-V1[3]) - (V2[1]-V1[1]);
    l_com = abs(l1-l2);
    area = h_com*l_com;
    return area;


}