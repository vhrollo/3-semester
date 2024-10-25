#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <unistd.h> // sbrk

// Global variables
int global_uninitialized;
int global_var = 42;

void function() {
    // To show where program code is 
}

// Recursive function to observe stack growth
void f(int i) {
    if (i == 0)
        return;

    int val = 42;
    printf("Recursive level: %d, addr to rec val is %p\n", i, (void *)&val);

    f(i - 1);
}

// Function to generate addresses.txt file
void generate_txt(void* addr1, void* addr2, void* addr3, void* heap_start) {
    char buffer[512];
    snprintf(buffer, sizeof(buffer), 
        "=========\n"
        "%p  program code\n"
        "---------\n"
        "%p  heap start\n"
        "%p  heap allocated\n"
        "---------\n"
        "ikke brukt\n"
        "---------\n"
        "%p  stack\n"
        "=========\n",
        addr1, heap_start, addr2, addr3);

    FILE *fp = fopen("addresses.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%s", buffer);
        fclose(fp);
    }
}


//Explanation:

//Program code:
//This is the first address is the location of a function in the program code, which shows where the executable code is stored in memory.
//Then the initialized global variables comes as we can see in the print out
//Then the unitialized global variables seems to be written

//Heap:
//The Heap allocated start is the second block in addresses.txt, which shows where the heap will start/be in the beginning in the program
//Then the heap allocated will show where the heap ends after allocating 1 MB

//Empty Space:
//marked as ikke brukt i addresses.txt

//Stack:
//The final address shows where the local variable is located on the stack, and when calling the recursive function we notice how it will grow downward ( high to low addresses )

int main() {
    // Local variable (stack)
    int local_var = 405;

    // Get the start of the heap
    void *heap_start = sbrk(0);

    // Dynamic allocated memory (heap)
    int *heap_var = (int *)malloc(1024 * 1024);  // 1MB allocation
    *heap_var = 100;

    // Print addresses
    printf("function address ( program code ): %p\n", (void *)&function);
    printf("Global var address ( init global variable ): %p\n", (void *)&global_var);
    printf("Global uninit var address ( uninit global variable ): %p\n", (void *)&global_uninitialized);
    printf("Heap start address: %p\n", heap_start);
    printf("Heap allocated address: %p\n", (void *)heap_var);
    printf("Local var address ( stack ): %p\n", (void *)&local_var);

    // Observe how the stack grows
    f(5);

    // Generate addresses.txt
    generate_txt((void *)&function, (void *)heap_var, (void *)&local_var, heap_start);

    // Free memory
    free(heap_var);

    return 0;
}
