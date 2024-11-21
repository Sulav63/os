#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int value = 1; // Global variable

void *sleep_a(void *u) {
    printf("New boy\n");
    value = value + 5;
    printf("\nI am going to sleep for %d seconds: ", value);
    sleep(value);
    printf("\nI slept for %d seconds: \n", value);
    return NULL;
}

void *sleep_b(void *u) {
    printf("Old boy\n");
    value = value + 2;
    printf("\nI am going to sleep for %d seconds: ", value);
    sleep(value);
    printf("\nI slept for %d seconds: \n", value);
    return NULL;
}

int main() {
    pthread_t tid, tid2;
    time_t t;
    time(&t);

    printf("\nThis program was written at (date and time): %s", ctime(&t));

    pthread_create(&tid, NULL, sleep_a, NULL);
    pthread_create(&tid2, NULL, sleep_b, NULL);

    printf("Main thread\n");

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

//gcc try2.c -o try2 -pthread

