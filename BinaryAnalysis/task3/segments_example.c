#include <stdio.h> // For printf
#include <stdlib.h> // For malloc

// Initialized global variable (goes in .data)
int global_initialized_var = 123;

// Uninitialized global variable (goes in .bss)
int global_uninitialized_var;

// Constant string literal (goes in .rodata)
const char *my_constant_string = "Hello, Segments!";

int main() {
    // Local variable (on the stack)
    int local_var = 45;

    // Dynamically allocated memory (on the heap)
    int *heap_var = (int *)malloc(sizeof(int));
    if (heap_var == NULL) {
        perror("malloc failed");
        return 1;
    }
    *heap_var = 67;

    printf("Global Initialized: %d\n", global_initialized_var);
    printf("Global Uninitialized: %d\n", global_uninitialized_var);
    printf("Local Variable: %d\n", local_var);
    printf("Heap Variable: %d\n", *heap_var);
    printf("Constant String: %s\n", my_constant_string);

    free(heap_var); // Don't forget to free dynamic memory
    return 0;
}
