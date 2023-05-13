#include <stdio.h>
//Defining Structure for Processor
struct node{
    int at, bt, ct, wt, tat, start, id, com,priority;
}pq[10];
int highPriorityJob(int n, int current){
    int high_priority_job;
    for(int i=0; i<n; i++){
        if(pq[i].at <= current && !pq[i].com){
            high_priority_job = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(pq[i].at <= current && !pq[i].com && pq[i].priority > pq[high_priority_job].priority){
            high_priority_job = i;
        }
    }
    return high_priority_job;
}
void main(){
    int n,current=0,atat=0,awt=0,completed=0,high_priority_job;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter Arrival , Burst Time and Priority of Process : ");
        scanf("%d%d%d", &pq[i].at, &pq[i].bt, &pq[i].priority);
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
        high_priority_job = highPriorityJob(n, current);
        pq[high_priority_job].start = current;
        pq[high_priority_job].ct = pq[high_priority_job].bt + current;
        current = pq[high_priority_job].ct;
        pq[high_priority_job].tat = pq[high_priority_job].ct - pq[high_priority_job].at;
        pq[high_priority_job].wt = pq[high_priority_job].tat - pq[high_priority_job].bt;
        pq[high_priority_job].com = 1;
        atat += pq[high_priority_job].tat;
        awt += pq[high_priority_job].wt;
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