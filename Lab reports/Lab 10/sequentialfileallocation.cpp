#include <stdio.h>

int main() {
    int f[50], i, st, len, j, c, k, count = 0;
    for(i = 0; i < 50; i++)
        f[i] = 0; // Initialize all blocks as free

    printf("Files Allocated are : \n");

    while(1) {
        printf("\nEnter the starting block and length of file: ");
        scanf("%d%d", &st, &len);

        // Boundary check for valid starting block and length
        if (st + len > 50) {
            printf("Invalid starting block or length. Try again.\n");
            continue;
        }

        count = 0;  // Reset count for each allocation
        // Check if enough contiguous blocks are free
        for(k = st; k < st + len; k++) {
            if(f[k] == 0)
                count++;
        }

        // If enough free blocks, allocate the file
        if(len == count) {
            for(j = st; j < st + len; j++) {
                if(f[j] == 0) {
                    f[j] = 1;
                    printf("Block %d allocated\n", j);
                }
            }
            printf("The file is allocated to disk.\n");
        } else {
            printf("The file cannot be allocated.\n");
        }

        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
        if(c == 0) {
            break;  // Exit the loop if user chooses No
        }
    }

    return 0;
}

