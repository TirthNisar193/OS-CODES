#include <stdio.h>
void main()
{
    int np, nb;
    printf("Enter number of processes\n");
    scanf("%d", &np);
    printf("Enter number of blocks\n");
    scanf("%d", &nb);
    int b[nb], p[np], allocated[np];
    for (int i = 0; i < np; i++)
        allocated[i] = -1;
    printf("Enter the block sizes\n");
    for (int i = 0; i < nb; i++)
        scanf("%d", &b[i]);
    printf("Enter the process sizes\n");
    for (int i = 0; i < np; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < np; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++)
        {
            if (b[j] >= p[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (b[bestIdx] > b[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocated[i] = bestIdx;
            b[bestIdx] -= p[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\tRemaining Space\n");
    for (int i = 0; i < np; i++)
    {
        printf("%d\t\t%d", i + 1, p[i]);
        if (allocated[i] != -1){
            printf("\t\t%d", allocated[i] + 1);
            printf("\t\t%d", b[allocated[i]]);}
        else
            printf("\t\tNot Allocated");
        printf("\n");
    }
}