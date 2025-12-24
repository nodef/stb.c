// Example demonstrating the use of stb_image_write.h for saving an image to disk
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int width = 4, height = 4, channels = 3;
    unsigned char image[4 * 4 * 3] = {
        255, 0, 0,   0, 255, 0,   0, 0, 255,   255, 255, 0,
        255, 0, 255, 0, 255, 255, 128, 128, 128, 64, 64, 64,
        255, 128, 0, 128, 255, 0,   0, 128, 255, 128, 0, 255,
        64, 64, 64, 192, 192, 192, 32, 32, 32, 224, 224, 224
    };

    const char *filename = "output.png";
    if (stbi_write_png(filename, width, height, channels, image, width * channels)) {
        printf("Image saved successfully to %s\n", filename);
    } else {
        fprintf(stderr, "Failed to save image to %s\n", filename);
        return 1;
    }

    return 0;
}
