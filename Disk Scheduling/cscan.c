#include <stdio.h>

void main()
{
    int tracks, n, current_position, sum, pos;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int cscan[n];
    printf("Enter track numbers of request queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cscan[i]);
    }
    printf("Enter current position: ");
    scanf("%d", &current_position);
    printf("Enter the direction: 0=RIGHT OR 1=LEFT\n");
    scanf("%d", &pos);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cscan[j] > cscan[j + 1])
            {
                int temp = cscan[j];
                cscan[j] = cscan[j + 1];
                cscan[j + 1] = temp;
            }
        }
    }
    int s;
    for (int i = 0; i < n; i++)
    {
        if (cscan[i] > current_position)
        {
            s = i;
            break;
        }
    }
    if (pos == 0)
    {
        printf("Seek Sequence is: ");
        printf("%d\t", current_position);
        for (int i = s; i < n; i++)
        {
            printf("%d\t", cscan[i]);
        }
        printf("%d\t0\t", tracks - 1);
        for (int i = 0; i < s; i++)
        {
            printf("%d\t", cscan[i]);
        }
        sum = 2 * (tracks - 1) - current_position + cscan[s-1];
        printf("\nTotal number of track movements = %d", sum);
    }
    else if(pos == 1)
    {
        printf("Seek Sequence is: ");
        printf("%d\t", current_position);
        for (int i = s-1; i >= 0; i--)
        {
            printf("%d\t", cscan[i]);
        }
        printf("0\t%d\t", tracks - 1);
        for (int i = n-1; i >= s; i--)
        {
            printf("%d\t", cscan[i]);
        }
        sum = current_position + 2*(tracks-1)- cscan[s];
        printf("\nTotal number of track movements = %d", sum);
    }
}