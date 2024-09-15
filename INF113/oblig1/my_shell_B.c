#include <stdio.h>     // getline
#include <stdlib.h>    // exit 
#include <string.h>    // strtok
#include <unistd.h>    // execvp
#include <sys/types.h> // wait
#include <sys/wait.h>  // wait
#include <string.h>    // strcmp 

#define MAX_ARGS 256

char *line = NULL;
size_t n = 0;
char *args[MAX_ARGS];

/*
    Reads one line from the standard input and
    splits it into tokens. The resulting tokens
    are stored args, terminated by a NULL pointer.
*/
void parse_command_from_user() 
{
    int rc = getline(&line, &n, stdin);
    if (rc < 0) // Close the shell at end-of-input
        exit(0);


    int i = 0;
    args[i++] = strtok(line, " \n"); //means that it splits on spaces and newlines

    while (i< MAX_ARGS && args[i-1] != NULL) {
        args[i++] = strtok(NULL, " \n"); // same here, and when inputed with NULL, it continues to parse the same string
        // it gives back NULL as a parameter when empty
    }
}


int main()
{

    while (1) {
        

        printf("> ");

        parse_command_from_user(); 

        if (args[0] && !strcmp(args[0], "exit")) {
            exit(0);
        }

        if (args[0] != NULL) { // so it don't unnecessarily fork
            int fork_id = fork();

            if (fork_id == 0) {
                execvp(args[0], args);
                exit(0); //had to include this, execvp didn't always terminate
            } else {
                wait(NULL);
            }
        }
    } 

    return 0;
}
