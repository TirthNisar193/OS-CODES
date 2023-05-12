#include <stdio.h>

void main()
{
    int tracks, n, current_position, sum, pos;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int clook[n];
    printf("Enter track numbers of request queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &clook[i]);
    }
    printf("Enter current position: ");
    scanf("%d", &current_position);
    printf("Enter the direction: 0=RIGHT OR 1=LEFT\n");
    scanf("%d", &pos);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (clook[j] > clook[j + 1])
            {
                int temp = clook[j];
                clook[j] = clook[j + 1];
                clook[j + 1] = temp;
            }
        }
    }
    int min = 0;
    int s;
    for (int i = 0; i < n; i++)
    {
        if (clook[i] > current_position)
        {
            min = clook[i - 1];
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
            printf("%d\t", clook[i]);
        }
        for (int i = 0; i < s; i++)
        {
            printf("%d\t", clook[i]);
        }
        sum = (2 * clook[n - 1]) - current_position - (2 * clook[0]) + clook[s - 1];
        printf("\nTotal number of track movements = %d", sum);
    }
    if (pos == 1)
    {
        printf("Seek Sequence is: ");
        printf("%d\t", current_position);
        for (int i = s - 1; i >= 0; i--)
        {
            printf("%d\t", clook[i]);
        }
        for (int i = n - 1; i >= s; i--)
        {
            printf("%d\t", clook[i]);
        }
        sum = (2 * clook[n - 1]) + current_position - (2 * clook[0]) - clook[s];

        printf("\nTotal number of track movements = %d", sum);
    }
}