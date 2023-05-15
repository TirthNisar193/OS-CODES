#include<stdio.h>
int main() {
    int frames[10], pages[30];
    int num_frames, num_pages;
    int i, j, k, pf=0,pp=0;//pp is page pointer
    int flag=0; // To check if page is already present in frames
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter page reference string: ");
    for(i=0; i<num_pages; i++) {
        scanf("%d", &pages[i]);
    } 
    // Initialize frames with -1 to indicate empty
    for(i=0; i<num_frames; i++) {
        frames[i] = -1;
    }
    // Loop through pages and implement FIFO
    for(i=0; i<num_pages; i++) {
        flag = 0;
        for(j=0; j<num_frames; j++) {
            if(frames[j] == pages[i]) { // Page already present in frame
                flag = 1;
                break;
            }
        }
        if(flag == 0) { // Page not present in frame, add to frame
            frames[pp % num_frames] = pages[i];
            pf++;
            pp++;
        }
        // Print current state of frames after page reference
        printf("\n");
        for(k=0; k<num_frames; k++) {
            printf("%d\t", frames[k]);
        }
    }
    printf("\n\nTotal Page Faults = %d", pf);
    printf("\nTotal number of hits = %d", num_pages - pf);
    printf("\nHit ratio = %d/%d", num_pages - pf, num_pages); 
    return 0;
}