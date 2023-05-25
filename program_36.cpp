#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int absDiff(int a, int b) {
    return abs(a - b);
}

int findClosestTrack(int tracks[], int n, int headPos, bool visited[]) {
    int minDiff = INT_MAX;
    int closestTrack = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && absDiff(tracks[i], headPos) < minDiff) {
            minDiff = absDiff(tracks[i], headPos);
            closestTrack = i;
        }
    }

    return closestTrack;
}

void sstf(int tracks[], int n, int headPos) {
    int totalHeadMovement = 0;
    bool visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int currentTrack = 0;

    printf("Sequence of track accesses:\n");
    for (int i = 0; i < n; i++) {
        int nextTrack = findClosestTrack(tracks, n, headPos, visited);
        visited[nextTrack] = true;

        printf("%d -> ", tracks[nextTrack]);

        totalHeadMovement += absDiff(tracks[currentTrack], tracks[nextTrack]);
        currentTrack = nextTrack;
    }

    printf("END\n");

    float avgHeadMovement = (float)totalHeadMovement / n;
    printf("\nAverage head movement: %.2f\n", avgHeadMovement);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int headPos;

    printf("Enter the head position: ");
    scanf("%d", &headPos);

    sstf(tracks, n, headPos);

    return 0;
}

