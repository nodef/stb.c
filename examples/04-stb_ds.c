// Example demonstrating the use of stb_ds.h for dynamic arrays and hash tables
#define STB_DS_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Dynamic array example
    int *arr = NULL;
    for (int i = 0; i < 10; ++i) {
        stbds_arrpush(arr, i * i);
    }

    printf("Dynamic array contents:\n");
    for (int i = 0; i < stbds_arrlen(arr); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // stbds_arrfree(arr);

    // Hash table example
    struct { char *key; int value; } *hash_table = NULL;
    stbds_shput(hash_table, "apple", 1);
    stbds_shput(hash_table, "banana", 2);
    stbds_shput(hash_table, "cherry", 3);

    printf("Hash table contents:\n");
    for (int i = 0; i < stbds_shlen(hash_table); ++i) {
        printf("%s: %d\n", hash_table[i].key, hash_table[i].value);
    }
    // stbds_shfree(hash_table);

    return 0;
}
