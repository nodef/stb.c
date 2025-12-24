// Example demonstrating the use of stb_perlin.h for generating Perlin noise
#define STB_PERLIN_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>

int main() {
    int width = 10, height = 10;
    float scale = 0.1f;

    printf("Perlin noise values:\n");
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float value = stb_perlin_noise3(x * scale, y * scale, 0.0f, 0, 0, 0);
            printf("%0.2f ", value);
        }
        printf("\n");
    }

    return 0;
}
