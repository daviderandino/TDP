#include<stdio.h>
#include<string.h>

int printReservations(FILE * fp);
char * numberToDay(int number);
int dayToNumber(char * name);

int main(){
    FILE *fp = fopen("../file040722.txt","r");
    int n = printReservations(fp);
    printf("%d\n",n);
}

int printReservations(FILE * fp){
    char giorno[9];
    int V_prenotazioni[7] = {0},V_clienti[7] = {0},num_clienti,n_giorno,max;
    while(!feof(fp)){
        fscanf(fp,"%s",giorno);
        fscanf(fp,"%d",&num_clienti);
        n_giorno = dayToNumber(giorno);
        V_prenotazioni[n_giorno]++;
        V_clienti[n_giorno]+=num_clienti;
    }

    max = V_clienti[0];
   for(int i=0;i<7;i++){
       strcpy(giorno, numberToDay(i));
       if(V_prenotazioni[i]!=0){
           float media = (float) V_clienti[i]/V_prenotazioni[i];
           printf("%s: %d prenotazioni, %.2f clienti in media per tavolo\n",giorno,V_prenotazioni[i],media);
       }
       else
           printf("%s: %d prenotazioni, 0.00 clienti in media per tavolo\n",giorno,V_prenotazioni[i]);
       if(V_clienti[i]>max) max = V_clienti[i];
   }
    return max;
}

char * numberToDay(int number){
    switch(number){
        case 0:
            return "Lunedi";
        case 1:
            return "Martedi";
        case 2:
            return "Mercoledi";
        case 3:
            return "Giovedi";
        case 4:
            return "Venerdi";
        case 5:
            return "Sabato";
        case 6:
            return "Domenica";
    }
}
int dayToNumber(char * name){
    if(strcmp(name,"Lunedi")==0)
        return 0;
    else if(strcmp(name,"Martedi")==0)
        return 1;
    else if(strcmp(name,"Mercoledi")==0)
        return 2;
    else if(strcmp(name,"Giovedi")==0)
        return 3;
    else if(strcmp(name,"Venerdi")==0)
        return 4;
    else if(strcmp(name,"Sabato")==0)
        return 5;
    else if(strcmp(name,"Domenica")==0)
        return 6;

}