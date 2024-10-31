#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bonkinator() {
    //without writing to memory
    size_t allocation_size = 100 * 1024 * 1024; // hehe
    size_t total_allocated = 0;
    char *ptr;

    //loop until virtual memory exhaution 
    while ((ptr = malloc(allocation_size)) != NULL) {
        total_allocated += allocation_size;

        printf("Allocated: %.2f GiB\n", total_allocated / (1024.0 * 1024.0 * 1024.0));
    }

    printf("Allocation failed. Total allocated memory: %.2f GiB\n", 
           total_allocated / (1024.0 * 1024.0 * 1024.0));
}


void bonkinator2() {
    //writing to memory
    size_t allocation_size = 100 * 1024 * 1024; // hehe
    size_t total_allocated = 0;
    char *ptr;

    //loop until segmentation failure
    while ((ptr = malloc(allocation_size)) != NULL) {
        total_allocated += allocation_size;

        //writing to this chunk
        memset(ptr, 0, allocation_size);

        printf("Allocated: %.2f GiB\n", total_allocated / (1024.0 * 1024.0 * 1024.0));
    }

    printf("Allocation failed. Total allocated memory: %.2f GiB\n", 
           total_allocated / (1024.0 * 1024.0 * 1024.0));
}


int main() {
    size_t allocation_size = 100 * 1024 * 1024; // Start with 100 MB increments
    char *ptr = NULL;

    //loop until malloc fails
    while ((ptr = malloc(allocation_size)) != NULL) {

        //freeing the memory so that 
        //we find the biggest size of allocation
        //which will cause an failure
        free(ptr);
        allocation_size += 1024 * 1024;
    }

    printf("malloc failed at size: %zu bytes (%.2f MiB)\n", allocation_size, allocation_size / (1024.0 * 1024.0));
    return 0;
}
