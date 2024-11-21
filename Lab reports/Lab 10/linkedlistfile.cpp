#include<stdio.h>
#include<stdlib.h>
int main() {
    int f[50], p, i, st, len, j, c, k, a;

    // Initialize the block allocation array (all free initially)
    for(i = 0; i < 50; i++)
        f[i] = 0;
    // Input the number of already allocated blocks
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    // Mark the already allocated blocks
    printf("Enter the block numbers already allocated: ");
    for(i = 0; i < p; i++) {
        scanf("%d", &a);
        if(a >= 0 && a < 50) // Ensure the block number is within valid range
            f[a] = 1;
        else
            printf("Invalid block number %d. Must be between 0 and 49.\n", a);
    }
    // Main allocation loop
    do {
        // Input the starting block and the length of the file
        printf("Enter starting block and length of file: ");
        scanf("%d%d", &st, &len);

        // Check if the starting block is free
        if(st >= 0 && st + len <= 50) { // Ensure allocation stays within bounds
            if(f[st] == 0) {
                int allocated = 1;
                // Try allocating the requested length
                for(j = st; j < (st + len); j++) {
                    if(f[j] == 0) {
                        f[j] = 1; // Mark the block as allocated
                        printf("Block %d is allocated.\n", j);
                    } else {
                        printf("Block %d is already allocated.\n", j);
                        allocated = 0;  // Mark the file as partially allocated
                    }
                }

                if(allocated) {
                    printf("The file has been successfully allocated.\n");
                } else {
                    printf("The file could not be fully allocated due to some blocks already being taken.\n");
                }
            } else {
                printf("Starting block %d is already allocated.\n", st);
            }
        } else {
            printf("Invalid allocation range. Please ensure the file fits within the available blocks (0 to 49).\n");
        }

        // Ask the user if they want to allocate another file
        printf("Do you want to allocate another file? (Yes - 1 / No - 0): ");
        scanf("%d", &c);

    } while(c == 1);

    return 0;
}


