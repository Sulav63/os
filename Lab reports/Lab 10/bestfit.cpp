#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int nb, nf, i, j, temp, lowest;

    printf("\n\tMemory Management Scheme - Best Fit\n");

    // Input number of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    // Input number of files
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input block sizes
    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    // Input file sizes
    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // Best Fit Allocation Logic
    for (i = 0; i < nf; i++) {
        lowest = 10000; // Reset lowest for each file
        for (j = 0; j < nb; j++) {
            if (!bf[j]) { // Check if block is not already allocated
                temp = b[j] - f[i];
                if (temp >= 0 && temp < lowest) { // Best fit condition
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        if (lowest != 10000) { // If a suitable block was found
            frag[i] = lowest;
            bf[ff[i]] = 1; // Mark block as allocated
        } else { // If no suitable block was found
            frag[i] = -1;
        }
    }

    // Display the allocation table
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (frag[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, f[i]);
        }
    }

    return 0;
}

