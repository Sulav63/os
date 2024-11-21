#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 2
#define COUNT 10
int shared_variable = 0;
pthread_mutex_t mutex;
void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    for (int i = 0; i < COUNT; ++i) {
        pthread_mutex_lock(&mutex);  // Lock mutex
        // Critical section
        printf("Thread %d in critical section (iteration %d)\n", thread_id, i + 1);
        shared_variable++;
        printf("Shared variable value after increment: %d\n", shared_variable);
        pthread_mutex_unlock(&mutex);  // Unlock mutex
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1};
    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("pthread_mutex_init");
        return 1;
    }
    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result != 0) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, result);
            return 1;
        }
    }
    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    // Destroy mutex
    pthread_mutex_destroy(&mutex);
    return 0;
}

