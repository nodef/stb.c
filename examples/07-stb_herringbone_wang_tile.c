// Example demonstrating the use of stb_herringbone_wang_tile.h to generate a herringbone Wang tile map
#define STB_HERRINGBONE_WANG_TILE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    stbhw_tile tiles[16];
    stbhw_tileset ts = {0}; // Initialize tileset
    unsigned char output[256]; // Placeholder output buffer
    printf("Building herringbone Wang tiles...\n");
    int num_tiles = stbhw_generate_image(&ts, NULL, output, 0, 16, 16);

    printf("Generated %d herringbone Wang tiles:\n", num_tiles);
    for (int i = 0; i < num_tiles; ++i) {
        printf("Tile %d: edges = [N/A]\n", i); // Placeholder for valid members
    }

    return 0;
}
