#include <iostream>
#include <pthread.h>
#include <unistd.h>  // for usleep
using namespace std;
const int NUM_THREADS = 2;
volatile bool flag[NUM_THREADS] = {false, false};
volatile int turn = 0;
void *criticalSection(void *threadId) {
    int id = *(int *)threadId;
    int other = 1 - id;
    for (int i = 0; i < 5; ++i) {
        // Lock
        flag[id] = true;
        turn = other;
        while (flag[other] && turn == other) {
            // Busy-wait
        }
        // Critical Section
        cout << "Thread " << id << " is in critical section." << endl;
        usleep(100000);  // Sleep for 100 milliseconds
        // Unlock
        flag[id] = false;
        // Sleep to simulate work outside critical section
        usleep(50000);  // Sleep for 50 milliseconds
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS] = {0, 1};
    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, criticalSection, (void *)&threadIds[i]);
    }
    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

