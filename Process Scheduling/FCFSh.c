#include <stdio.h>
//Defining Structure for Processor
struct node{
    int at, bt, ct, wt, tat, start, id;
}pq[10];
void main(){
    int n,current=0,atat=0,awt=0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter Arrival and Burst Time of Process : ");
        scanf("%d%d", &pq[i].at, &pq[i].bt);
        pq[i].id = i+1;
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
    //For calculating the Completion, TurnAround & Wating time of each processes
    for (int i=0;i<n;i++){
        //Current time will be the max(Current, Process arrival time)
        current = current>pq[i].at?current:pq[i].at;
        pq[i].start = current;
        //Completion time of a process will be the sum of current and burst time of a process
        pq[i].ct = pq[i].bt + current;
        //Cuurent time will be updated to the completion time of the process
        current = pq[i].ct;
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