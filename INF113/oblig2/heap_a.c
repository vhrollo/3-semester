#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_memory_before_malloc(void *ptr) {
    //for printing the 16 bytes in the terminal
    unsigned char *metadata_ptr = (unsigned char *)ptr - 16;

    printf("Memory 16 bytes before the malloc'd block:\n");

    for (int i = 0; i < 16; i++) {
        printf("%02x ", metadata_ptr[i]);
    }
    printf("\n");
}

int main() {
    size_t size = 1024 * 1024; // 1 MB  
    void *allocated_memory = malloc(size);

    printf("Address returned by malloc (Block 1): %p\n", allocated_memory);

    print_memory_before_malloc(allocated_memory);

    //getting pid so i can run pmap -p ...
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);
    

    getchar(); //inf loop

    free(allocated_memory);
    return 0;
}