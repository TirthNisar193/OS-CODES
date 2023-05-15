#include<stdio.h>
void main() {
    int tracks, n, current_position, sum;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int fcfs[n];
    printf("Enter track numbers of request queue:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &fcfs[i]);
    }
    printf("Enter current position: ");
    scanf("%d", &current_position);
    if(fcfs[0] > current_position)
        sum = fcfs[0] - current_position;
    else
        sum = current_position - fcfs[0];
    for(int i=0; i<n-1; i++) {
        if(fcfs[i+1] > fcfs[i]) {
            sum += fcfs[i+1] - fcfs[i];            
        }
        else {
            sum += fcfs[i] - fcfs[i+1];
        }
    }
    printf("Total number of track movements = %d", sum);
}