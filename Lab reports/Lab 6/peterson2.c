#include <stdio.h>
#include <stdlib.h>
// Simulate a mutex with an integer
int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;
void producer() {
    if (mutex == 1 && empty != 0) {
        --mutex;      // Lock the mutex
        ++full;       // Increase the number of full slots
        --empty;      // Decrease the number of empty slots
        x++;          // Produce an item
        printf("\nProducer produces item %d", x);
        ++mutex;      // Release the mutex
    } else {
        printf("\nBuffer is full!");
    }
}
void consumer() {
    if (mutex == 1 && full != 0) {
        --mutex;      // Lock the mutex
        --full;       // Decrease the number of full slots
        ++empty;      // Increase the number of empty slots
        printf("\nConsumer consumes item %d", x);
        x--;          // Consume an item
        ++mutex;      // Release the mutex
    } else {
        printf("\nBuffer is empty!");
    }
}
int main() {
    int n, i;
    printf("\n1. Press 1 for Producer");
    printf("\n2. Press 2 for Consumer");
    printf("\n3. Press 3 for Exit");
    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Please enter 1, 2, or 3.");
        }
    }
    return 0;
}

