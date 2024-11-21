#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// Thread function
void *show(void *u) {
    printf("OLD BOY\n");
    printf("This is a thread, its PID is: %d\n", getpid());
    return NULL;
}

int main() {
    int pid;
    pthread_t tid;
    time_t t;

    time(&t);
    printf("This program was written at (date and time): %s", ctime(&t));

    // Create a thread
    if (pthread_create(&tid, NULL, &show, NULL) != 0) {
        perror("Failed to create thread");
        exit(1);
    }
    pthread_join(tid, NULL); // Wait for the thread to complete

    printf("Main thread\n");
    printf("The PID of the main thread is: %d\n", getpid());
    printf("The PPID (Parent PID) of the main thread is: %d\n", getppid());

    // Create a child process
    pid = fork();

    if (pid == 0) {
        // Child process
        printf("This is the child process.\n");
        printf("The PID of the child is: %d\n", getpid());
        printf("The PPID of the child is: %d\n", getppid());
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("This is the parent process.\n");
    } else {
        // Fork failed
        perror("Fork failed");
        exit(1);
    }

    return 0;
}

// gcc try.c -o try -pthread
