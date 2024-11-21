#include<stdio.h>
#include<string.h>

int main() {
    int nf = 0, i = 0, j = 0, ch;
    char mdname[10], fname[10][10], name[10];

    // Input the directory name
    printf("Enter the directory name: ");
    scanf("%s", mdname);

    // User decides how many files they want to create
    printf("Enter the number of files to create initially: ");
    scanf("%d", &nf);

    // File creation loop
    do {
        // Input the name of the file to be created
        printf("Enter file name to be created: ");
        scanf("%s", name);

        // Check if the file already exists
        for(i = 0; i < j; i++) {
            if(!strcmp(name, fname[i])) {
                printf("There is already a file named %s\n", name);
                break;
            }
        }

        // If the file doesn't already exist, add it
        if(i == j && j < 10) {  // Check if there is space for new files
            strcpy(fname[j++], name);
        } else if(j >= 10) {
            printf("Directory is full, cannot create more files.\n");
        }

        // Ask user if they want to add another file
        printf("Do you want to enter another file (yes - 1 or no - 0): ");
        scanf("%d", &ch);

    } while(ch == 1);

    // Output the directory and files
    printf("\nDirectory name is: %s\n", mdname);
    printf("Files in the directory:");
    for(i = 0; i < j; i++) {
        printf("\n%s", fname[i]);
    }

    return 0;
}

