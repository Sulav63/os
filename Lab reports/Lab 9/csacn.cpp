#include <iostream>
#include <cmath> // For abs()

using namespace std;

int calculateCSCAN(int requests[], int numRequests, int initialHead, int diskSize) {
    int sortedRequests[20];
    for (int i = 0; i < numRequests; ++i) {
        sortedRequests[i] = requests[i];
    }

    for (int i = 0; i < numRequests - 1; ++i) {
        for (int j = i + 1; j < numRequests; ++j) {
            if (sortedRequests[i] > sortedRequests[j]) {
                int temp = sortedRequests[i];
                sortedRequests[i] = sortedRequests[j];
                sortedRequests[j] = temp;
            }
        }
    }

    int head = initialHead;
    int totalMovement = 0;

    // Move right
    for (int i = 0; i < numRequests; ++i) {
        if (sortedRequests[i] >= head) {
            totalMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    }

    // Jump to the beginning of the disk
    if (head < diskSize - 1) {
        totalMovement += (diskSize - 1 - head);
        head = 0;
    }

    // Continue moving from the start
    for (int i = 0; i < numRequests; ++i) {
        if (sortedRequests[i] < head) {
            totalMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    }

    return totalMovement;
}

int main() {
    int initialHead = 143;
    int diskSize = 200;
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int numRequests = sizeof(requests) / sizeof(requests[0]);

    int totalMovement = calculateCSCAN(requests, numRequests, initialHead, diskSize);
    cout << "Total head movement using C-SCAN: " << totalMovement << " tracks\n";

    return 0;
}

