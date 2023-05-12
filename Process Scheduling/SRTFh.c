#include <stdio.h>
#define INT_MAX 2147483647
//Defining Structure for Processor
struct node{
    int at, bt, ct, wt, tat, start, id, com, r_bt;
}pq[10];
//Function for finding shortest remaining job
int shortJob(int n, int current){
    int min;
    for(int i=0; i<n; i++){
        if(pq[i].at <= current && !pq[i].com){
            min = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(pq[i].at <= current && !pq[i].com && pq[i].r_bt < pq[min].r_bt){
            min = i;
        }
    }
    return min;
}
void main(){
    int n,current=0,atat=0,awt=0,completed=0,short_job=0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter Arrival and Burst Time of Process : ");
        scanf("%d%d", &pq[i].at, &pq[i].bt);
        pq[i].r_bt = pq[i].bt;
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
        short_job = shortJob(n, current);
        if(pq[short_job].r_bt == pq[short_job].bt){
            pq[short_job].start = current;
        }
        pq[short_job].r_bt--;
        current++;
        if(pq[short_job].r_bt <= 0){
            pq[short_job].com = 1;
            pq[short_job].ct = current;
            completed++;
        }
    }

    //For calculating the Completion, TurnAround & Wating time of each processes
    for (int i=0;i<n;i++){
        //Turn around time will be Completion time - Arrival time
        pq[i].tat = pq[i].ct - pq[i].at;
        
        //Waiting time will be Turn around time - Burst time 
        pq[i].wt = pq[i].tat - pq[i].bt;
        
        atat += pq[i].tat;
        awt += pq[i].wt;
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