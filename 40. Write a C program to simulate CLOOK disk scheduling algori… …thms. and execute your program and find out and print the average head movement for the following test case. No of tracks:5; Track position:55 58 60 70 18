#include <stdio.h>
#define MAX 50
int disk_arm, seek_time, head, n, queue[MAX];
void sort_queue()
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}
int main()
{
    int i, j, total_head_movement = 0;
    float average_head_movement;
    printf("Enter the size of the queue:\n");
    scanf("%d", &n);
    printf("Enter the queue:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial position of the disk arm:\n");
    scanf("%d", &disk_arm);
    head = disk_arm;
    sort_queue();
    for(i = 0; i < n; i++)
    {
        if(head < queue[i])
        {
            total_head_movement += (queue[i] - head);
            head = queue[i];
        }
    }
    head = queue[n - 1];
    for(i = n - 1; i >= 0; i--)
    {
        if(head > queue[i])
        {
            total_head_movement += (head - queue[i]);
            head = queue[i];
        }
    }
    average_head_movement = (float) total_head_movement / n;
    printf("The average head movement is: %f\n", average_head_movement);
    return 0;
}
