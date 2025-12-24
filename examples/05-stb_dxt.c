// Example demonstrating the use of stb_dxt.h to compress an image into DXT format
#define STB_DXT_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Example image: 4x4 block of RGBA pixels
    unsigned char image[16 * 4] = {
        255, 0, 0, 255,   0, 255, 0, 255,   0, 0, 255, 255,   255, 255, 0, 255,
        255, 0, 255, 255, 0, 255, 255, 255, 128, 128, 128, 255, 64, 64, 64, 255,
        255, 128, 0, 255, 128, 255, 0, 255, 0, 128, 255, 255, 128, 0, 255, 255,
        64, 64, 64, 255, 192, 192, 192, 255, 32, 32, 32, 255, 224, 224, 224, 255
    };

    unsigned char compressed[8]; // DXT1 compresses 4x4 blocks into 8 bytes

    stb_compress_dxt_block(compressed, image, 0, STB_DXT_NORMAL);

    printf("Compressed DXT1 block:\n");
    for (int i = 0; i < 8; ++i) {
        printf("%02X ", compressed[i]);
    }
    printf("\n");

    return 0;
}
