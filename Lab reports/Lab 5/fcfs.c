#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[]) {
    int i, service_time[n];
    wt[0] = 0; // First process has no waiting time
    service_time[0] = at[0]; // Service time starts at arrival time of first process

    // Calculating waiting time for each process
    for (i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + bt[i - 1];
        wt[i] = service_time[i] - at[i];
        if (wt[i] < 0) wt[i] = 0; // Waiting time cannot be negative
    }
}

// Function to calculate turn-around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int i;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, at, wt);

    // Function to find turn-around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    printf("\nProcesses   Burst Time   Arrival Time   Waiting Time   Turn Around Time\n");
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i]);
    }

    // Calculate and display average waiting and turn-around times
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage waiting time = %f", avg_wt);
    printf("\nAverage turn around time = %f\n", avg_tat);
}

// Driver code
int main() {
    int n, i;

    // Ask user for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];

    // Input burst time and arrival time for each process
    for (i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs start from 1
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    // Function call to calculate and display average times
    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}

