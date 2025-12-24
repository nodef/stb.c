// Example demonstrating the use of stb_include.h for recursive #include handling
#define STB_INCLUDE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *source_code = "#include \"example_file.h\"\nvoid main() { return; }";
    const char *inject = "// Injected code\n";
    const char *path_to_includes = "example_file.h";
    char *output = stb_include_string(source_code, inject, path_to_includes, NULL, NULL);

    if (!output) {
        fprintf(stderr, "Failed to process includes\n");
        return 1;
    }

    printf("Processed source code:\n%s\n", output);
    free(output);

    return 0;
}
