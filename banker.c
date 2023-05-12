#include<stdio.h>
void main() {
    int np, nr, sum, count=0, res=0;
    printf("Enter the no of processes: ");
    scanf("%d", &np);
    printf("Enter the no of resources: ");
    scanf("%d", &nr);
    int allocated[np][nr];
    int claimed[np][nr];
    int total_resources[nr];
    int remaining[np][nr];
    int safe_state[np];
    int finished[np];
    int available[nr];
    //Allocated matrix
    for(int i=0; i<np; i++) {
        printf("Enter allocated for Process P%d: ", i);
        for(int j=0; j<nr; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }
    //Claimed matrix
    for(int i=0; i<np; i++) {
        printf("Enter claimed for Process P%d: ", i);
        for(int j=0; j<nr; j++) {
            scanf("%d", &claimed[i][j]);
        }
    }
    //Remaining matrix
    for(int i=0; i<np; i++) {
        for(int j=0; j<nr; j++) {
            remaining[i][j] = claimed[i][j] - allocated[i][j];
            printf("%d ", remaining[i][j]);
        }
        printf("\n");
    }
    //Total resources for each resource
    printf("Enter total resources: ");
    for(int i=0; i<nr; i++) {
        scanf("%d", &total_resources[i]);
    }
    //Available for each resource
    printf("Available: ");
    for(int i=0; i<nr; i++) {
        sum = 0;
        for(int j=0; j<np; j++) {
            sum += allocated[j][i];
        }
        available[i] = total_resources[i] - sum;
        printf("%d ", available[i]);
    }
    for(int i=0; i<np; i++) {
        finished[i] = 0;
    }
    for (int k = 0; k < np; k++) {
        for (int i = 0; i < np; i++) {
            // first check if the process is not finished
            if (finished[i] == 0) {
                int flag = 0;
                for (int j = 0; j < nr; j++) {
                    if (remaining[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) { // if flag=0 it means the need is less than available so it can be fullfiled
                    safe_state[count++] = i;
                    for (int y = 0; y < nr; y++)
                        available[y] += allocated[i][y];
                    finished[i] = 1; // mark finished of that process 1 i.e need of this process is satisfied
                }
            }
        }
    }
    int flag = 1;
    // To check if sequence is safe or not
    for(int i = 0; i<np; i++){   
        if(finished[i] == 0) { // if f[i]=0 it means need of this process is not statisfied 
            flag = 0;
            printf("\nUnsafe state leading to Deadlock!!");
            break;
        }
    }
    if(flag == 1) {
        printf("\nSafe state:  ");
        for (int i = 0; i < np - 1; i++)
            printf(" P%d ->", safe_state[i]);
        printf(" P%d", safe_state[np-1]);
    }
}
