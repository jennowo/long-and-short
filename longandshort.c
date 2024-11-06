#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    
    // Check for 3 arguments
    if(argc < 4) {
        printf("Must include 3 command line arguments.");
        exit(1);
    }

    // Get file names
    char *name1 = argv[1];
    char *name2 = argv[2];
    char *name3 = argv[3];

    // Open and check the files
    FILE *file1 = fopen(name1, "r");
    FILE *file2 = fopen(name2, "w");
    FILE *file3 = fopen(name3, "w");

    if (file1 == NULL || file2 == NULL || file3 == NULL) {
        printf("One or more of the files could not be opened.");
        exit(1);
    }

    // Read from source file line by line
    char line[255];
    int length;
    int count2 = 0;
    int count3 = 0;
    
    while(fgets(line, 255, file1) != NULL) {
        length = strlen(line);
        
        // If length of line < 20 characters, convert to uppercase and write to first destination file
        if(length < 20) {
            for (int i = 0; i < length; i++) {
                line[i] = toupper(line[i]);
            } 
            fprintf(file2, "%s", line);
            count2++;
        }
        // Otherwise, convert the line to lowercase and write it to the second destination file
        else {
            for (int i = 0; i < length; i++) {
                line[i] = tolower(line[i]);
            } 
            fprintf(file3, "%s", line);
            count3++;
        }

    }

    // Close the files 
    fclose(file1);
    fclose(file2);
    fclose(file3);

    // Display the number of lines written to each of the destination files
    printf("%d lines written to %s\n", count2, name2);
    printf("%d lines written to %s\n", count3, name3);

    return 0;
}