#include <iostream>
#include <cmath> // For abs()

using namespace std;

int calculateLOOK(int requests[], int numRequests, int initialHead) {
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

    // Move to the nearest end of requests based on direction
    bool directionUp = head < sortedRequests[0];

    if (directionUp) {
        for (int i = 0; i < numRequests; ++i) {
            if (sortedRequests[i] >= head) {
                totalMovement += abs(sortedRequests[i] - head);
                head = sortedRequests[i];
            }
        }
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
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int numRequests = sizeof(requests) / sizeof(requests[0]);

    int totalMovement = calculateLOOK(requests, numRequests, initialHead);
    cout << "Total head movement using LOOK: " << totalMovement << " tracks\n";

    return 0;
}

