// Example demonstrating the use of stb_image_resize2.h for resizing an image
#define STB_IMAGE_RESIZE2_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int width = 4, height = 4, channels = 3;
    unsigned char input_image[4 * 4 * 3] = {
        255, 0, 0,   0, 255, 0,   0, 0, 255,   255, 255, 0,
        255, 0, 255, 0, 255, 255, 128, 128, 128, 64, 64, 64,
        255, 128, 0, 128, 255, 0,   0, 128, 255, 128, 0, 255,
        64, 64, 64, 192, 192, 192, 32, 32, 32, 224, 224, 224
    };

    int new_width = 8, new_height = 8;
    unsigned char *output_image = malloc(new_width * new_height * channels);

    if (!output_image) {
        fprintf(stderr, "Failed to allocate memory for resized image\n");
        return 1;
    }

    if (!stbir_resize_uint8_srgb(input_image, width, height, 0, output_image, new_width, new_height, 0, channels)) {
        fprintf(stderr, "Failed to resize image\n");
        free(output_image);
        return 1;
    }

    printf("Resized image from %dx%d to %dx%d\n", width, height, new_width, new_height);

    // Print the first few pixels of the resized image
    printf("First 10 pixels of resized image:\n");
    for (int i = 0; i < 10 * channels; i += channels) {
        printf("Pixel %d: %d %d %d\n", i / channels, output_image[i], output_image[i + 1], output_image[i + 2]);
    }

    free(output_image);
    return 0;
}
