#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    // Get user input
    #define N 256
    char buffer[N+1], *filename = buffer;
    char ch;
    int i = 0; // counter for how many characters read
    printf("Enter a file name: ");
    while ((ch = getchar()) != '\n') { // get one character at a time
        if (isspace(ch)) { // Ignore leading spaces
            if (i == 0) {
                continue;
            } else {
                break;
            }
        }
        filename[i++] = ch;
        if (i >= N) { // Check if the input exceeds the buffer size
            printf("Error!\n");
            return EXIT_FAILURE;
        }
    }
    if (i == 0) { // Check if no input was provided
        printf("Error!\n");
        return EXIT_FAILURE;
    }
    filename[i] = '\0'; // Null terminate the string

    // Find the last dot in the filename
    char *extension = strrchr(filename, '.');
    if (extension == NULL) { // Check if there is no dot in the filename
        printf("Error!\n");
        return EXIT_FAILURE;
    }

    // Print the extension including the dot
    printf("%s\n", extension);

    return EXIT_SUCCESS;
}