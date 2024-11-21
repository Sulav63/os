#include <iostream>
#include <cmath> // For abs()

using namespace std;

int calculateFCFS(int requests[], int numRequests, int initialHead) {
    int head = initialHead;
    int totalMovement = 0;

    for (int i = 0; i < numRequests; ++i) {
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }
    return totalMovement;
}

int main() {
    int initialHead = 143;
    int requests[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int numRequests = sizeof(requests) / sizeof(requests[0]);

    int totalMovement = calculateFCFS(requests, numRequests, initialHead);
    cout << "Total head movement using FCFS: " << totalMovement << " tracks\n";

    return 0;
}

