//With arrival time
#include<stdio.h>

void main() {
    int p[5] = {1, 2, 3, 4, 5};
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {4, 3, 1, 2, 5};
    int c[5], t[5], w[5], sum=0, sum1=0;
    c[0] = b[0];
    for(int i=0; i<5; i++) {
        if(i>0)
            c[i] = b[i] + c[i-1];
        //printf("%d", c[i]);
        t[i] = c[i] - a[i];
        w[i] = t[i] - b[i];
    }
    printf("Process\tArrival Time\tBurst Time\tCom Time\tTurn Time\tWaiting\n");
    for(int i=0; i<5; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], a[i], b[i], c[i], t[i], w[i]);
    }
    printf("Gantt Chart\n");
    printf("0\t");
    for(int i=0; i<5; i++) {
        printf("P%d\t%d\t", p[i], c[i]);
    }
    for(int i=0; i<5; i++) {
        sum += t[i];
        sum1 += w[i];
    }
    printf("\nAverage Turn Around Time = %d", sum);
    printf("\nAverage Waiting Time = %d", sum1);
}