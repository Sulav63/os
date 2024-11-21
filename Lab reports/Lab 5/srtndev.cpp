#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100 // Maximum number of processes

struct Process {
    int pid; // Process ID
    int bt;  // Burst Time
    int art; // Arrival Time
};

// Function to find the waiting time for all processes
void findWaitingTime(struct Process proc[], int n, int wt[]) {
    int rt[MAX_PROCESSES]; // Remaining times
    int complete, t, minm, shortest, finish_time, check;
    int i, j; // Declare loop variables here

    // Initialize variables
    for (i = 0; i < n; i++) {
        rt[i] = proc[i].bt;
    }
    complete = 0;
    t = 0;
    minm = INT_MAX;
    shortest = 0;
    check = 0;

    // Process until all processes are completed
    while (complete != n) {
        // Find process with minimum remaining time
        for (j = 0; j < n; j++) {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        // Reduce remaining time
        rt[shortest]--;

        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        // If a process is completed
        if (rt[shortest] == 0) {
            complete++;
            check = 0;

            // Calculate finish time and waiting time
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

// Function to calculate turnaround time
void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    int i; // Declare loop variable here
    for (i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

// Function to calculate average time
void findavgTime(struct Process proc[], int n) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;
    int i; // Declare loop variable here

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    // Print process details
    printf(" P\t\tBT\t\tAT\t\tWT\t\tTAT\n");
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].art, wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %f", (float)total_wt / n);
    printf("\nAverage turn around time = %f", (float)total_tat / n);
}

// Driver code
int main() {
    int n, i;
    struct Process proc[MAX_PROCESSES];

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Error: Number of processes exceeds maximum limit.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter Burst Time for Process %d: ", proc[i].pid);
        scanf("%d", &proc[i].bt);
        printf("Enter Arrival Time for Process %d: ", proc[i].pid);
        scanf("%d", &proc[i].art);
    }

    findavgTime(proc, n);
    return 0;
}

