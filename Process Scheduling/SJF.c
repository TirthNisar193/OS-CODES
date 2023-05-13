#include <stdio.h>
#define INT_MAX 2147483647
//Defining Structure for Processor
struct node{
    int at, bt, ct, wt, tat, start, id, com;
}pq[10];
void main(){
    int n,current=0,atat=0,awt=0,completed=0,short_bt=INT_MAX,short_p;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter Arrival and Burst Time of Process : ");
        scanf("%d%d", &pq[i].at, &pq[i].bt);
        pq[i].id = i+1;
        pq[i].com = 0;
    }

    //Sorting array using Insertion sort according to arrival time
    for (int i=1;i<n;i++){
        int j = i-1;
        struct node key = pq[i];
        while(j>=0 && pq[j].at > key.at){
            pq[j+1] = pq[j];
            j--;
        }
        pq[j+1] = key;
    }

    current = pq[0].at;
    while(completed<n){
        for (int i=0;i<n;i++){
            if(pq[i].at<=current && pq[i].com==0 && short_bt>pq[i].bt){
                short_p = i;
                short_bt = pq[i].bt;
            }
        }
        pq[short_p].start = current;
        pq[short_p].ct = pq[short_p].bt + current;
        current = pq[short_p].ct;
        pq[short_p].tat = pq[short_p].ct - pq[short_p].at;
        pq[short_p].wt = pq[short_p].tat - pq[short_p].bt;
        pq[short_p].com = 1;
        atat += pq[short_p].tat;
        awt += pq[short_p].wt;
        short_bt = INT_MAX;
        completed+=1;
    }

    printf("\n");
    for(int i=0; i<n; i++){
        printf("PID : %d, AT : %d, BT : %d, CT : %d, TAT : %d, WT : %d\n", pq[i].id, pq[i].at, pq[i].bt, pq[i].ct, pq[i].tat, pq[i].wt);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d....P%d....%d\n", pq[i].start, pq[i].id,pq[i].ct);

    }
    printf("\n");
    printf("Avg TAT : %.2f, Avg WT : %.2f", (float)atat/n, (float)awt/n);
}