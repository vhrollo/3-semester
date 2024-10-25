#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    size_t size = 1024 * 1024; // 1 MB
    char *allocated_memory = (char *)malloc(size);
   
    //for pmap ...
    printf("Process ID: %d\n", getpid());
    
    printf("Memory is allocated, press enter to write to memory...\n");
    getchar(); //this is so you can see before writing
    
    for (size_t i = 0; i < size; i += 4096) {
        allocated_memory[i] = 'A';
    }
    
    printf("Writing is done, press enter to end thetheprogram...\n");
    getchar(); // and then this is so you can see after writing
    // and whiel the program is still alive
    
    free(allocated_memory);
    return 0;
}