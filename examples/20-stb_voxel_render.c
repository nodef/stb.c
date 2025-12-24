// Example rendering a voxel scene using stb_voxel_render.h
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

#define VOXEL_SIZE 16

int main() {
    // Define a simple voxel scene
    unsigned char voxels[VOXEL_SIZE][VOXEL_SIZE][VOXEL_SIZE] = {0};

    // Create a simple cube in the scene
    for (int x = 4; x < 12; x++) {
        for (int y = 4; y < 12; y++) {
            for (int z = 4; z < 12; z++) {
                voxels[x][y][z] = 1; // Solid voxel
            }
        }
    }

    // Render the voxel scene
    unsigned char *output = (unsigned char *)malloc(VOXEL_SIZE * VOXEL_SIZE * 4);
    if (!output) {
        fprintf(stderr, "Failed to allocate memory for output\n");
        return 1;
    }

    stbvox_init();
    stbvox_set_scene(voxels, VOXEL_SIZE, VOXEL_SIZE, VOXEL_SIZE);
    stbvox_render(output, VOXEL_SIZE, VOXEL_SIZE);

    // Save the rendered scene as a PPM image
    FILE *file = fopen("voxel_scene.ppm", "wb");
    if (!file) {
        fprintf(stderr, "Failed to open output file\n");
        free(output);
        return 1;
    }

    fprintf(file, "P6\n%d %d\n255\n", VOXEL_SIZE, VOXEL_SIZE);
    fwrite(output, 1, VOXEL_SIZE * VOXEL_SIZE * 4, file);
    fclose(file);

    printf("Voxel scene saved to voxel_scene.ppm\n");

    free(output);
    return 0;
}
