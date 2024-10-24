// oppgave 1
// fillip lampe


#include <stdio.h>  //printf
#include <stdlib.h> //malloc

//globale vars
int global_var = 42;
int global_unitialized;

void function() {
    // to show where programcode is 
}

// recursive function from task
void f(int i) {

    if (i == 0)

        return;

    int val = 42;

    printf("Recursive level: %d, addr to rec val is %p\n", i, (void *)&val);

    f(i - 1);

}

void generate_txt(void* addr1, void* addr2, void* addr3) {

    //writes into a string buffer as a more clean approach
    char buffer[512];
    snprintf(buffer, sizeof(buffer), 
        "=========\n"
        "%p  program code\n"
        "---------\n"
        "%p  heap\n"
        "---------\n"
        "Ikke brukt\n"
        "---------\n"
        "%p  stack\n"
        "=========\n",
        addr1, addr2, addr3);

    //write to the file
    FILE *fp = fopen("addresses.txt", "w");
    fprintf(fp, "%s", buffer);
    fclose(fp);
}

//Explanaiton:
//The first address is the location of a function in the program code, which shows where the executable code is stored in memory.
//The second address shows the starting point of the allocated 1 MB in the heap
//This represents the empty space in vt
//The final address shows where the local variable is located on the stack, and when calling the recursive function we notice how it will grow downward ( high to low addresses )


int main() {
    //lcoal vars (stack)
    int local_var = 405;
    
    //dynamic allocated memory (heap)
    int *heap_var = (int *)malloc(1024 * 1024); // allocating 1MB on the heap
    *heap_var = 100;

    //addresses (added void* for clarity)
    printf("function address ( program code ): %p\n", (void *)&function);
    printf("Global var address ( global variable ): %p\n", (void *)&global_var);
    printf("Heap var address ( heap ): %p\n", (void *)heap_var);
    printf("Local var address ( stack ): %p\n", (void *)&local_var);

    //checking how the stack develops
    f(5);
    generate_txt((void *)&function, (void *)&local_var, (void *)&heap_var);

    free(heap_var);


    return 0;
}
