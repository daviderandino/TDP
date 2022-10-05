/*
Un locale consente a 10 suoi client VIP di avere un conto aperto: il cliente può addebitare più
ricevute, e pagare il conto totale in un secondo momento. Il locale tiene traccia delle ricevute dei
client in un file chiamato bills.txt, in cui ogni riga riporta un ordine come:
 id del cliente VIP (4 caratteri);
 la cifra corrispondente all’ordine: cifre positive rappresentano il prezzo dell’ordine da
addebitare e da aggiungere quindi al conto aperto, mentre cifre negative
rappresentano saldi (anche parziali) del conto aperto.
 */

#include<stdio.h>
#include<string.h>
#define MAXCLIENTI 10

void analyseBill(FILE *fp, int *num);

typedef struct{
    char id[4];
    float saldo;
} cliente;

int main(void) {
    FILE * fp;
    int num,n_clienti;
    fp = fopen("../040722.txt", "r");
    if(fp == NULL){
        return -1;
    }
    analyseBill(fp, &num);
    printf("Number of customers: %d \n", num);
    return 0;
}

void analyseBill(FILE *fp, int *num){
    cliente clienti[MAXCLIENTI];
    int n;
    char id[4],max_cust[4];
    float operazione,max;
    *num = 0;
    int V[11] = {0};

    while(!feof(fp)) {

        fscanf(fp, "%s", id);
        fscanf(fp, "%f", &operazione);
        if (id[2] == '0') n = id[3] - '0';
        else n = 10;
        if(V[n]==0){
            *num = *num + 1;
            strcpy(clienti[n].id, id);
        }
        V[n]++;
        clienti[n].saldo = clienti[n].saldo + operazione;
    }

   max = clienti[0].saldo;
   strcpy(max_cust, clienti[0].id);

   for(int i=1;i<=*num;i++){
       printf("Customer %s: %.2f\n",clienti[i].id,clienti[i].saldo);
       if(clienti[i].saldo>max){
           strcpy(max_cust, clienti[i].id);
           max = clienti[i].saldo;
       }
   }

    printf("Customer with highest debt: %s, %.2f\n",max_cust,max);

}