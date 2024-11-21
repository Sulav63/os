#include <stdio.h>

int main() {
    int A[100][5]; // Matrix for storing Process ID, Arrival Time, Burst Time, WT, TAT
    int i, j, n, total = 0, temp;
    float avg_wt, avg_tat;

    // User input for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and arrival time
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &A[i][1]); // Arrival Time
        printf("Burst Time: ");
        scanf("%d", &A[i][2]); // Burst Time
        A[i][0] = i + 1;       // Process ID
    }

    // Sort processes based on Arrival Time and then Burst Time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i][1] > A[j][1] || (A[i][1] == A[j][1] && A[i][2] > A[j][2])) {
                // Swap Arrival Time
                temp = A[i][1];
                A[i][1] = A[j][1];
                A[j][1] = temp;

                // Swap Burst Time
                temp = A[i][2];
                A[i][2] = A[j][2];
                A[j][2] = temp;

                // Swap Process ID
                temp = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = temp;
            }
        }
    }

    // Calculate Waiting Time (WT)
    int service_time = 0; // Tracks when the CPU is free
    for (i = 0; i < n; i++) {
        if (service_time < A[i][1]) { // If CPU is idle
            service_time = A[i][1];
        }
        A[i][3] = service_time - A[i][1]; // WT = Start Time - Arrival Time
        if (A[i][3] < 0) A[i][3] = 0;     // WT cannot be negative
        service_time += A[i][2];          // Add Burst Time to service time
        total += A[i][3];
    }
    avg_wt = (float)total / n;

    // Calculate Turnaround Time (TAT)
    total = 0;
    for (i = 0; i < n; i++) {
        A[i][4] = A[i][3] + A[i][2]; // TAT = WT + Burst Time
        total += A[i][4];
    }
    avg_tat = (float)total / n;

    // Print results
    printf("\nP     AT     BT     WT     TAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d     %d      %d      %d      %d\n", A[i][0], A[i][1], A[i][2], A[i][3], A[i][4]);
    }

    printf("\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f\n", avg_tat);

    return 0;
}

