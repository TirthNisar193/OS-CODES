#include <stdio.h>
#define INT_MAX 2147483647
//Defining Structure for Processor
struct node{
    int at, bt, ct, wt, tat, start, id, com, r_bt, in_queue;
}pq[10];
int front=-1,rear=-1,circularqueue[10];
void enqueue(int process){
    if(rear == -1){
        front = 0;
        rear = 0;
        circularqueue[rear] = process;
    }
    else if((rear+1)%10 == front){
        printf("Queue Full");
    }
    else{
        rear = (rear+1)%10;
        circularqueue[rear] = process;
    }
}
int dequeue(){
    int dequeue_process = -1;
    if(front == -1){
        printf("Queue Empty");
    }
    else if(front == rear){
        dequeue_process = circularqueue[front];
        front = -1;
        rear = -1;
    }
    else{
        dequeue_process = circularqueue[front];
        front = (front+1)%10;
    }
    return dequeue_process;
}
void main(){
    int n,current=0,atat=0,awt=0,completed=0,time_quantum,dequeued_process=0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    printf("\n");
    printf("Enter Time Quantum : ");
    scanf("%d", &time_quantum);
    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter Arrival , Burst Time of Process : ");
        scanf("%d%d", &pq[i].at, &pq[i].bt);
        pq[i].r_bt = pq[i].bt;
        pq[i].id = i+1;
        pq[i].com = 0;
        pq[i].in_queue = 0;
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
    enqueue(0);
    while(completed<n){
        dequeued_process = dequeue();
        if(dequeued_process != -1){
            if(pq[dequeued_process].r_bt == pq[dequeued_process].bt){
                pq[dequeued_process].start = current;
            }
            if(pq[dequeued_process].r_bt <= time_quantum){
                current += pq[dequeued_process].r_bt;
                pq[dequeued_process].r_bt = 0;
                pq[dequeued_process].com = 1;
                pq[dequeued_process].ct = current;
                pq[dequeued_process].in_queue = 0;
                completed++;
            }
            else{
                current += time_quantum;
                pq[dequeued_process].r_bt -= time_quantum;
            }
            for(int i=1;i<n;i++){
                if(!pq[i].com && !pq[i].in_queue && pq[i].at <= current){
                    enqueue(i);
                    pq[i].in_queue = 1;
                }
            }
            if(!pq[dequeued_process].com){
                enqueue(dequeued_process);
                pq[dequeued_process].in_queue = 1;
            }
        }
    }
    // For calculating the Completion, TurnAround & Wating time of each processes
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