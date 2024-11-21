#include <iostream>
#include <cmath> // For abs()

using namespace std;

int calculateSCAN(int requests[], int numRequests, int initialHead, int diskSize) {
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

    bool directionUp = head < sortedRequests[0];

    if (directionUp) {
        for (int i = 0; i < numRequests; ++i) {
            if (sortedRequests[i] >= head) {
                totalMovement += abs(sortedRequests[i] - head);
                head = sortedRequests[i];
            }
        }
        totalMovement += abs(diskSize - 1 - head);
        head = diskSize - 1;

        for (int i = numRequests - 1; i >= 0; --i) {
            if (sortedRequests[i] < head) {
                totalMovement += abs(sortedRequests[i] - head);
                head = sortedRequests[i];
            }
        }
    } else {
        for (int i = numRequests - 1; i >= 0; --i) {
            if (sortedRequests[i] <= head) {
                totalMovement += abs(sortedRequests[i] - head);
                head = sortedRequests[i];
            }
        }
        totalMovement += head;
        head = 0;

        for (int i = 0; i < numRequests; ++i) {
            if (sortedRequests[i] > head) {
                totalMovement += abs(sortedRequests[i] - head);
                head = sortedRequests[i];
            }
        }
    }

    return totalMovement;
}

int main() {
    int initialHead = 143;
    int diskSize = 200;
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int numRequests = sizeof(requests) / sizeof(requests[0]);

    int totalMovement = calculateSCAN(requests, numRequests, initialHead, diskSize);
    cout << "Total head movement using SCAN: " << totalMovement << " tracks\n";

    return 0;
}

