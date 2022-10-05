#include<stdio.h>

int areaIntersection(FILE *fp);

int main(){
    FILE *fp = fopen("../030722.txt","r");
    int area;
    area = areaIntersection(fp);
    printf("%d\n",area);
}

int areaIntersection(FILE *fp){
    int x1,y1,x2,y2,x3,y3,x4,y4,l_com,h_com;
    fscanf(fp,"%d",&x1);
    fscanf(fp,"%d",&y1);
    fscanf(fp,"%d",&x2);
    fscanf(fp,"%d",&y2);
    fscanf(fp,"%d",&x3);
    fscanf(fp,"%d",&y3);
    fscanf(fp,"%d",&x4);
    fscanf(fp,"%d",&y4);
    l_com = x2 - x1 + x4 - x3 - (x4-x1);
    h_com = y2 - y1 + y4 - y3 - (y4 - y1);
    return l_com*h_com;
}