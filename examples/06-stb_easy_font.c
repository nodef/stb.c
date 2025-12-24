// Example demonstrating the use of stb_easy_font.h for bitmap font rendering
#define STB_EASY_FONT_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *text = "Hello, stb_easy_font!";
    float x = 10.0f, y = 10.0f;
    char buffer[9999];

    int num_quads = stb_easy_font_print(x, y, (char*) text, NULL, buffer, sizeof(buffer));

    printf("Text: %s\n", text);
    printf("Number of quads: %d\n", num_quads);

    printf("Vertex data:\n");
    for (int i = 0; i < num_quads * 4 * 4; i += 4) {
        printf("Vertex: (%f, %f)\n", ((float *)buffer)[i], ((float *)buffer)[i + 1]);
    }

    return 0;
}
