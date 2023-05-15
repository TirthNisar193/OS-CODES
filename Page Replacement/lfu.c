#include <stdio.h>
#include <stdlib.h>

void main(){
    int noFrames, noPages, frames[10], pages[20], timestamp[10], frequency[10], fault=0;
    printf("Enter number of frames : ");
    scanf("%d", &noFrames);
    for (int i=0; i<noFrames; i++){
        frames[i] = -1;
    }
    for (int i=0; i<noFrames; i++){
        timestamp[i] = -1;
    }
    printf("Enter total number of pages : ");
    scanf("%d", &noPages);
    printf("Enter sequence : ");
    for (int i=0; i<noPages; i++){
        scanf("%d", &pages[i]);
    }
    for (int i=0; i<noPages; i++){
        int count = 0, flag=0;
        for (int j=0; j<noFrames; j++){
            if (frames[j] != pages[i]){
                count++;
            }else{
                frequency[j]++;
                flag=1;
                break;
            }
        }
        if(flag==0) {

        if(fault<noFrames){
            frames[fault] = pages[i];
            timestamp[fault] = i;
            frequency[fault] = 1;
            fault++;
        }
        else if(count == noFrames){
            fault++;
            int minFreq = 99, minElement;
            for(int j=0; j<noFrames; j++){
                if (frequency[j] < minFreq){
                    minFreq = frequency[j];
                    minElement = j;
                }
                else if(frequency[j] == minFreq){
                    if(timestamp[j] < timestamp[minElement]){
                        minFreq = frequency[j];
                        minElement = j;
                    }
                }
            }

            frames[minElement] = pages[i];
            timestamp[minElement] = i;
            frequency[minElement] = 1;
        }
        }
        printf("Page : %d\tFrames : ", pages[i]);
        for (int j=0; j<noFrames; j++){
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("Page Faults : %d", fault);
}