#include <stdio.h>

#define DISK_SIZE 16
#define INODE_BLOCKS 8
#define AVAILABLE_BLOCKS (DISK_SIZE - INODE_BLOCKS)
#define MIN_FILE_SIZE 1

int isContiguousFree(int disk[], int startBlock, int numBlocks) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (disk[i] != -1) {
            return 0; 
        }
    }

    return 1; 
}

void allocateBlocks(int disk[], int startBlock, int numBlocks, int fileNumber) {
    printf("Allocating blocks %d to %d for File %d\n", startBlock, startBlock + numBlocks - 1, fileNumber);
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        disk[i] = fileNumber;
    }
}

void printDiskState(int disk[]) {
    printf("Disk State:\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (i < INODE_BLOCKS) {
            printf("iNode %d\n", i);
        } else if (disk[i] == -1) {
            printf("Free Block %d\n", i);
        } else {
            printf("File %d Block %d\n", disk[i], i);
        }
    }
    printf("\n");
}

int main() {
    int disk[DISK_SIZE];
    for (int i = 0; i < DISK_SIZE; i++) {
        disk[i] = -1;
    }

    printDiskState(disk);

    int fileCount;
    printf("Enter the number of files to create: ");
    scanf("%d", &fileCount);

    for (int fileNumber = 1; fileNumber <= fileCount; fileNumber++) {
        int fileSize;
        printf("\nFile %d\n", fileNumber);
        printf("Enter the file size in KB: ");
        scanf("%d", &fileSize);

        if (fileSize < MIN_FILE_SIZE) {
            printf("Minimum file size is 1 KB.\n");
            continue;
        }

        if (fileSize > AVAILABLE_BLOCKS) {
            printf("Not enough contiguous blocks available for the file. Exiting.\n");
            return 0;
        }

        int startBlock = -1;
        int numBlocks = 0;

        for (int i = INODE_BLOCKS; i < DISK_SIZE; i++) {
            if (disk[i] == -1) {
                if (startBlock == -1) {
                    startBlock = i;
                }
                numBlocks++;

                if (numBlocks == fileSize) {
                    break;
                }
            } else {
                startBlock = -1;
                numBlocks = 0;
            }
        }

        if (numBlocks == fileSize) {
            allocateBlocks(disk, startBlock, numBlocks, fileNumber);
        } else {
            printf("Not enough contiguous blocks available for the file. Exiting.\n");
            return 0;
        }
    }

    printf("\nFinal Disk State:\n");
    printDiskState(disk);

    return 0;
}

