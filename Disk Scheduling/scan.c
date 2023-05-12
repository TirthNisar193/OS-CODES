#include <stdio.h>
void main()
{
    int tracks, n, current_position, sum = 0, pos = 0;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int scan[n];
    printf("Enter track numbers of request queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scan[i]);
    }
    printf("Enter current position: ");
    scanf("%d", &current_position);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (scan[j] > scan[j + 1])
            {
                int temp = scan[j];
                scan[j] = scan[j + 1];
                scan[j + 1] = temp;
            }
        }
    }
    printf("Enter the direction: 0=RIGHT OR 1=LEFT\n");
    scanf("%d", &pos);
    int s;
    for (int i = 0; i < n; i++)
    {
        if (scan[i] > current_position)
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
            printf("%d\t", scan[i]);
        }
        printf("%d\t", tracks - 1);
        for (int i = s - 1; i >= 0; i--)
        {
            printf("%d\t", scan[i]);
        }
        sum = 2 * (tracks - 1) - current_position - scan[0];
        printf("Total number of track movements = %d", sum);
    }
    else if (pos == 1)
    {
        printf("Seek Sequence is: ");
        printf("%d\t", current_position);
        for (int i = s - 1; i >= 0; i--)
        {
            printf("%d\t", scan[i]);
        }
        printf("%d\t", 0);
        for (int i = s; i < n; i++)
        {
            printf("%d\t", scan[i]);
        }
        sum = current_position + scan[n - 1];
        printf("Total number of track movements = %d", sum);
    }
}