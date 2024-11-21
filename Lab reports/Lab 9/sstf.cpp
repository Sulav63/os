#include <iostream>
#include <cmath> // For abs()

using namespace std;

int calculateSSTF(int requests[], int numRequests, int initialHead) {
    int head = initialHead;
    int totalMovement = 0;
    bool served[numRequests] = {0};

    for (int count = 0; count < numRequests; ++count) {
        int minDistance = 1e9;
        int closestIndex = -1;

        for (int i = 0; i < numRequests; ++i) {
            if (!served[i]) {
                int distance = abs(requests[i] - head);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }
        }

        totalMovement += minDistance;
        head = requests[closestIndex];
        served[closestIndex] = true;
    }
    return totalMovement;
}

int main() {
    int initialHead = 143;
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int numRequests = sizeof(requests) / sizeof(requests[0]);

    int totalMovement = calculateSSTF(requests, numRequests, initialHead);
    cout << "Total head movement using SSTF: " << totalMovement << " tracks\n";

    return 0;
}

