#include <stdio.h>
#include <stdlib.h>

/*
* Function: preview
* ----------------------------
*   Opens a file and prints the first n lines of the file.
*
*   filepath: The path to the file to preview.
*   n: The number of lines to print.
*
*   returns: void
*/
void preview(const char *filepath, int n) {
    FILE *file = fopen(filepath, "r"); // returns a stream set on the beginning of the file
    
    char ch;
    int i = 0;
    while (((ch = fgetc(file)) != EOF) && i < n) {
        if ( ch == '\n' ) i++;
        putchar(ch);
    }

    printf("\n");
    
    fclose(file);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filepath> <output_lines>\noutput_lines should be integer and larger than 0.", argv[0]);
        return 1;
    }
    int n = atoi(argv[2]);  // atoi() converts a string to an integer

    preview(argv[1], n);
    return 0;
}
