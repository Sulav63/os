#include <iostream>
#include <cmath> // For abs()

using namespace std;

int calculateCLOOK(int requests[], int numRequests, int initialHead) {
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

    // Move to the nearest end, then jump and continue
    for (int i = 0; i < numRequests; ++i) {
        if (sortedRequests[i] >= head) {
            totalMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    }

    // Wrap around and continue
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
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int numRequests = sizeof(requests) / sizeof(requests[0]);

    int totalMovement = calculateCLOOK(requests, numRequests, initialHead);
    cout << "Total head movement using C-LOOK: " << totalMovement << " tracks\n";

    return 0;
}

