#include <stdio.h>
#define MAX_PARTITIONS 4
#define MAX_PROCESSES 5
void worstFit(int partitions[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES] = {-1};
  
    for (int i = 0; i < n; i++) {
        int worstIndex = -1;
        for (int j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (worstIndex == -1 || partitions[j] > partitions[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
  
        if (worstIndex != -1) {
            allocation[i] = worstIndex;
  
            partitions[worstIndex] -= processes[i];
        }
    }
  
    printf("Process No.\tProcess Size\tPartition No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
    int processes[MAX_PROCESSES] = {100, 50, 30, 120, 35};

    printf("Memory Partitions:\n");
    for (int i = 0; i < MAX_PARTITIONS; i++) {
        printf("%d KB\t", partitions[i]);
    }
    printf("\n");

    printf("\nProcesses:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d KB\t", processes[i]);
    }
    printf("\n\n");

    worstFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);

    return 0;
}

