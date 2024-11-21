#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, nb, nf, temp;

    printf("\n\tMemory Management Scheme - Worst Fit\n");
    
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
    
    // Worst Fit Allocation Logic
    for (i = 0; i < nf; i++) {
        int worstIndex = -1; // Initialize worst-fit block index
        
        for (j = 0; j < nb; j++) {
            if (!bf[j]) { // Block not allocated
                temp = b[j] - f[i];
                if (temp >= 0 && (worstIndex == -1 || temp > frag[i])) {
                    worstIndex = j;
                    frag[i] = temp; // Keep track of fragmentation
                }
            }
        }
        
        if (worstIndex != -1) {
            ff[i] = worstIndex + 1; // Store block index (1-based for output)
            bf[worstIndex] = 1;    // Mark block as allocated
        } else {
            frag[i] = -1; // No suitable block found
        }
    }

    // Display the allocation table
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (ff[i]) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i], b[ff[i] - 1], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t-\t\t-\n", i + 1, f[i]);
        }
    }

    return 0;
}

