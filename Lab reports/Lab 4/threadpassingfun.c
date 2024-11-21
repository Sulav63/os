#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Global variable to store the number
int global;

// Function to calculate the square
void square() {
    global = global * global;
}

// Function to calculate the cube
void cube() {
    global = global * global * global;
}

// Thread function
void *PrintHello(void *choice) {
    int taskid = *(int *)choice; // Retrieve the choice (0 for square, 1 for cube)

    printf("Enter a number: ");
    scanf("%d", &global);

    if (taskid == 0) {
        square();
        printf("The square is %d.\n", global);
    } else if (taskid == 1) {
        cube();
        printf("The cube is %d.\n", global);
    } else {
        printf("Invalid choice.\n");
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads; // Thread identifier
    int choice;
    int rc;
    time_t t;

    // Display the current time
    time(&t);
    printf("This program was written at (date and time): %s", ctime(&t));

    // Input choice from the user
    printf("Enter a choice (0 for square, 1 for cube): ");
    scanf("%d", &choice);

    // Create a thread to perform the operation
    printf("Creating thread...\n");
    rc = pthread_create(&threads, NULL, PrintHello, &choice);
    if (rc) {
        printf("ERROR: Return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    // Wait for the thread to complete
    pthread_join(threads, NULL);

    return 0;
}


//gcc threadfunc.c -o threadfunc -pthread
