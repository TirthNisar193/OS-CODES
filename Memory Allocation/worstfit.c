#include<stdio.h>
#include<string.h>

void worstFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n];
    for(int i =0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0; i<n; i++){
        int wstIdx = -1;
        for(int j=0; j<m; j++){
            if(blockSize[j] >= processSize[i]){
                if(wstIdx == -1)
                    wstIdx = j;
                else if(blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
        if(wstIdx != -1){
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0; i<n; i++){
        printf(" %d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d", allocation[i]+1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main(){
    int blockSize[100],processSize[100],m,n;
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    printf("Enter the no of blocks: ");
    scanf("%d",&m);
    printf("Enter the process size: ");
    for(int i=0; i<n; i++){
        scanf("%d", &processSize[i]);
    }
    printf("Enter the block size: ");
    for(int i=0; i<m; i++){
        scanf("%d", &blockSize[i]);
    }
    worstFit(blockSize, m, processSize, n);
    return 0;
}