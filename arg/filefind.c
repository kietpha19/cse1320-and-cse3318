// Filefind
// Find and count the occurences of an integer value in a file

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

// usage: filefind filename value
// filename is the file to open
// value is integer to find and count in the file
// file contains one integer per line

int main(int argc, char* argv[])
{
    FILE *file;
    int value;
    int temp;
    int count = 0;
    char buffer[MAX_CHARS_PER_LINE + 1];

    // Validate number of arguments
    if (argc < 3)
    {
        printf("Not enough arguments\n");
        printf("usage: filefind filename value\n");
        exit(EXIT_FAILURE);
    }

    // Store the value to find
    sscanf(argv[2], "%d", &value);
    //value = atoi(argv[2]);

    // Open file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Parse lines of the file
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s\n", buffer);
        temp = atoi(buffer);
        if (temp == value)
            count++;
    }

    // Close file
    fclose(file);

    // Print count
    printf("Found %d occucat rences of value %d\n", count, value);

    return EXIT_SUCCESS;
}
