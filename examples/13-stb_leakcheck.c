// Example demonstrating the use of stb_leakcheck.h for detecting memory leaks
#define STB_LEAKCHECK_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory without freeing it to simulate a memory leak
    int *leaked_memory = (int *)malloc(10 * sizeof(int));
    if (!leaked_memory) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    // Allocate and free memory properly
    int *proper_memory = (int *)malloc(5 * sizeof(int));
    if (!proper_memory) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }
    free(proper_memory);

    printf("Check the output for memory leaks\n");
    return 0;
}
