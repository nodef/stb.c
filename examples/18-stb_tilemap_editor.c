// Example creating a tilemap editor using stb_tilemap_editor.h
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH  16
#define MAP_HEIGHT 16

int main() {
    // Initialize a simple tilemap
    unsigned char tilemap[MAP_WIDTH * MAP_HEIGHT] = {0};

    // Initialize the tilemap editor
    stbte_tilemap_editor editor;
    stbte_init(&editor, MAP_WIDTH, MAP_HEIGHT, tilemap);

    // Set up some tiles
    stbte_define_tile(&editor, 0, "Empty");
    stbte_define_tile(&editor, 1, "Grass");
    stbte_define_tile(&editor, 2, "Water");

    // Simulate editing the tilemap
    stbte_set_tile(&editor, 5, 5, 1); // Set Grass at (5, 5)
    stbte_set_tile(&editor, 6, 5, 2); // Set Water at (6, 5)

    // Print the tilemap
    printf("Tilemap:\n");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%d ", tilemap[y * MAP_WIDTH + x]);
        }
        printf("\n");
    }

    return 0;
}
