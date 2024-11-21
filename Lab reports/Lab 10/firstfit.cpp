#include <stdio.h>

int main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    // Initialize flags and allocation arrays
    for (i = 0; i < 10; i++) {
        flags[i] = 0;      // Block is initially unallocated
        allocation[i] = -1; // No process allocated initially
    }

    // Input the number of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);

    // Input the size of each block
    printf("\nEnter the size of each block: \n");
    for (i = 0; i < bno; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &bsize[i]);
    }

    // Input the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &pno);

    // Input the size of each process
    printf("\nEnter the size of each process: \n");
    for (i = 0; i < pno; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &psize[i]);
    }

    // First Fit Allocation Logic
    for (i = 0; i < pno; i++) { // Iterate through processes
        for (j = 0; j < bno; j++) { // Iterate through blocks
            if (flags[j] == 0 && bsize[j] >= psize[i]) { // Check if block is free and fits
                allocation[j] = i; // Allocate block to process
                flags[j] = 1;      // Mark block as allocated
                break;             // Move to the next process
            }
        }
    }

    // Display allocation details
    printf("\nBlock No.\tBlock Size\tProcess No.\tProcess Size\n");
    for (i = 0; i < bno; i++) {
        printf("%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flags[i] == 1) {
            printf("%d\t\t\t%d\n", allocation[i] + 1, psize[allocation[i]]);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}

