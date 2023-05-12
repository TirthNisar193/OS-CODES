#include<stdio.h>

void main() {
    int tracks, n, current_position, sum,pos;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int look[n];
    printf("Enter track numbers of request queue:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &look[i]);
    }
    printf("Enter current position: ");
    scanf("%d", &current_position);
    printf("Enter the direction: 0=RIGHT OR 1=LEFT\n");
    scanf("%d", &pos);
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(look[j] > look[j+1]) {
                int temp = look[j];
                look[j] = look[j+1];
                look[j+1] = temp;
            }
        }
    }
    int s;
    for(int i=0; i<n; i++) {
        if(look[i] > current_position) {
            s = i;
            break;
        }
    }
    if(pos==0){
    printf("Seek Sequence is: ");
    printf("%d\t", current_position);
    for(int i=s; i<n; i++) {
        printf("%d\t", look[i]);
    }
    for(int i=s-1; i>=0; i--) {
        printf("%d\t", look[i]);
    }
    sum = (2*look[n-1])-current_position-look[0];
    printf("\nTotal number of track movements = %d", sum);}
    if(pos==1){
    printf("Seek Sequence is: ");
    printf("%d\t", current_position);
    for(int i=s-1; i>=0; i--) {
        printf("%d\t", look[i]);
    }
    for(int i=s; i<n; i++) {
        printf("%d\t", look[i]);
    }
    sum = current_position-2*look[0]+look[n-1];
    printf("\nTotal number of track movements = %d", sum);}
}