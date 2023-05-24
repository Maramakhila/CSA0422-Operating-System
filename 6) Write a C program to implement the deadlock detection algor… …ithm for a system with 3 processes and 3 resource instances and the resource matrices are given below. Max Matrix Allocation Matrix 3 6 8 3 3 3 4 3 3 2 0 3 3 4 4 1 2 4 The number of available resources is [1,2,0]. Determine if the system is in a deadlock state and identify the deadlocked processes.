#include <stdio.h>
#define NUM_PROCESSES 3
#define NUM_RESOURCES 3
int max[NUM_PROCESSES][NUM_RESOURCES] = { {3, 6, 8},
                                           {4, 3, 3},
                                           {3, 4, 4}};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = { {3, 3, 3},
                                                 {2, 0, 3},
                                                 {1, 2, 4} };

int available[NUM_RESOURCES] = {1, 2, 0};
int work[NUM_RESOURCES],i,j;
int finish[NUM_PROCESSES];
int need[NUM_PROCESSES][NUM_RESOURCES];
int deadlock_detection()
{
    for (i = 0; i < NUM_PROCESSES; i++)
    {
        finish[i] = 0;
    }
	for (i = 0; i < NUM_RESOURCES; i++)
    {
        work[i] = available[i];
    }
	for (i = 0; i < NUM_PROCESSES; i++)
    {
        for (j = 0; j < NUM_RESOURCES; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
	int count = 0;
    while (count < NUM_PROCESSES)
    {
        int found = 0;
        for (i = 0; i < NUM_PROCESSES; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;
                for (j = 0; j < NUM_RESOURCES; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
				if (flag == 1)
                {
                    for (j = 0; j < NUM_RESOURCES; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }
		if (found == 0)
        {
            printf("The system is in deadlock state\n");
            printf("The deadlocked processes are: ");
            for (i = 0; i < NUM_PROCESSES; i++)
            {
                if (finish[i] == 0)
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
            return 1;
        }
		count++;
    }
    printf("The system is not in deadlock state\n");
    return 0;
}
int main()
{
    deadlock_detection();
    return 0;
}
