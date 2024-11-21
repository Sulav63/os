#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[], int quantum)
{
    int rem_bt[100]; // Array to store remaining burst times
    int t = 0;       // Current time
    int done = 0;    // Tracks if all processes are done
    int i;

    // Initialize remaining burst times
    for (i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    // Keep traversing processes in round-robin manner until all are done
    while (1)
    {
        done = 1; // Assume all processes are done

        for (i = 0; i < n; i++)
        {
            // Process only if it has arrived and burst time is remaining
            if (rem_bt[i] > 0 && t >= at[i])
            {
                done = 0; // At least one process is pending

                if (rem_bt[i] > quantum)
                {
                    t += quantum;        // Time spent on the process
                    rem_bt[i] -= quantum; // Decrease remaining burst time
                }
                else
                {
                    t += rem_bt[i]; // Include the remaining burst time
                    wt[i] = t - bt[i] - at[i]; // Waiting time = Current time - Burst time - Arrival time
                    if (wt[i] < 0) wt[i] = 0;  // Ensure no negative waiting time
                    rem_bt[i] = 0; // Mark process as completed
                }
            }
        }

        // Break loop if all processes are done
        if (done)
            break;
    }
}

// Function to calculate turnaround time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    int i;
    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i]; // Turnaround Time = Burst Time + Waiting Time
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int at[], int quantum)
{
    int wt[100], tat[100];
    int total_wt = 0, total_tat = 0;
    int i;

    // Calculate waiting time
    findWaitingTime(processes, n, bt, wt, at, quantum);

    // Calculate turnaround time
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display results
    printf("\nPN\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i], at[i], bt[i], wt[i], tat[i]);
    }

    // Print averages
    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

// Driver code
int main()
{
    int n, quantum;
    int processes[100], burst_time[100], arrival_time[100];
    int i;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival and burst times
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i + 1);
        processes[i] = i + 1; // Process IDs
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
    }

    // Input time quantum
    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);

    // Calculate and display average times
    findavgTime(processes, n, burst_time, arrival_time, quantum);

    return 0;
}

