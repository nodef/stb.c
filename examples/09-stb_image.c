// Example demonstrating the use of stb_image.h for loading and displaying an image
#define STB_IMAGE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "examples/butterfly.jpg";
    int width, height, channels;

    unsigned char *image = stbi_load(filename, &width, &height, &channels, 0);
    if (!image) {
        fprintf(stderr, "Failed to load image: %s\n", filename);
        return 1;
    }

    printf("Loaded image: %s\n", filename);
    printf("Dimensions: %dx%d\n", width, height);
    printf("Channels: %d\n", channels);

    // Display the first few pixel values
    printf("First 10 pixels:\n");
    for (int i = 0; i < 10 * channels; i += channels) {
        printf("Pixel %d: ", i / channels);
        for (int c = 0; c < channels; ++c) {
            printf("%d ", image[i + c]);
        }
        printf("\n");
    }

    stbi_image_free(image);
    return 0;
}
