// Example demonstrating the use of stb_c_lexer.h for tokenizing a simple C-like language
#define STB_C_LEXER_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *source_code = "int main() { return 0; }";
    stb_lexer lexer;

    stb_c_lexer_init(&lexer, source_code, source_code + strlen(source_code), (char *)malloc(1024), 1024);
    // Check if lexer.string_storage was allocated successfully
    if (!lexer.string_storage) {
        fprintf(stderr, "Failed to allocate memory for lexer string storage\n");
        return 1;
    }

    printf("Tokenizing source code: %s\n", source_code);

    while (stb_c_lexer_get_token(&lexer)) {
        printf("Token: %s\n", lexer.string);
    }

    free(lexer.string_storage);
    return 0;
}
