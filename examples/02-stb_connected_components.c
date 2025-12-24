// Example demonstrating the use of stb_connected_components.h to compute connected components in a grid
#define STB_CONNECTED_COMPONENTS_IMPLEMENTATION
#define STBCC_GRID_COUNT_X_LOG2 5
#define STBCC_GRID_COUNT_Y_LOG2 5
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 5
#define PADDED_WIDTH 8
#define PADDED_HEIGHT 8

int main() {
    unsigned char original_grid[HEIGHT][WIDTH] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0}
    };

    unsigned char grid[PADDED_HEIGHT][PADDED_WIDTH] = {0};

    // Initialize the original grid values
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            grid[y][x] = original_grid[y][x];
        }
    }

    stbcc_grid *g = (stbcc_grid *)malloc(stbcc_grid_sizeof());
    // Check if memory allocation for stbcc_grid succeeded
    if (!g) {
        fprintf(stderr, "Failed to allocate memory for stbcc_grid\n");
        return 1;
    }

    // Debug: Print the padded grid
    printf("Padded grid:\n");
    for (int y = 0; y < PADDED_HEIGHT; ++y) {
        for (int x = 0; x < PADDED_WIDTH; ++x) {
            printf("%2u ", grid[y][x]);
        }
        printf("\n");
    }

    // Debug: Verify grid dimensions and initialization
    printf("Grid dimensions: PADDED_WIDTH=%d, PADDED_HEIGHT=%d\n", PADDED_WIDTH, PADDED_HEIGHT);

    // Debug: Verify stbcc_grid_sizeof
    size_t grid_size = stbcc_grid_sizeof();
    printf("stbcc_grid_sizeof: %zu bytes\n", grid_size);

    // Debug: Verify stbcc_init_grid
    printf("Initializing stbcc_grid...\n");

    // Flatten the 2D grid into a 1D array
    unsigned char *flat_grid = (unsigned char *)malloc(PADDED_WIDTH * PADDED_HEIGHT);
    if (!flat_grid) {
        fprintf(stderr, "Failed to allocate memory for flat_grid\n");
        free(g);
        return 1;
    }

    for (int y = 0; y < PADDED_HEIGHT; ++y) {
        for (int x = 0; x < PADDED_WIDTH; ++x) {
            flat_grid[y * PADDED_WIDTH + x] = grid[y][x];
        }
    }

    // Debug: Verify memory allocation for stbcc_grid
    printf("Allocated stbcc_grid at address: %p\n", (void *)g);

    // Debug: Trace execution within stbcc_init_grid
    printf("Calling stbcc_init_grid...\n");

    // Debug: Verify the contents of flat_grid
    printf("Verifying flat_grid contents before passing to stbcc_init_grid...\n");
    for (int y = 0; y < PADDED_HEIGHT; ++y) {
        for (int x = 0; x < PADDED_WIDTH; ++x) {
            printf("%2u ", flat_grid[y * PADDED_WIDTH + x]);
        }
        printf("\n");
    }
    printf("flat_grid verification complete.\n");

    stbcc_init_grid(g, flat_grid, PADDED_WIDTH, PADDED_HEIGHT);
    printf("stbcc_init_grid completed successfully.\n");

    free(flat_grid);

    printf("Labeled grid:\n");
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            unsigned int id = stbcc_get_unique_id(g, x, y);
            printf("%2u ", id);
        }
        printf("\n");
    }

    // Debug: Verify stbcc_grid state after initialization
    printf("Verifying stbcc_grid state after initialization...\n");
    for (int y = 0; y < PADDED_HEIGHT; ++y) {
        for (int x = 0; x < PADDED_WIDTH; ++x) {
            if (stbcc_get_unique_id(g, x, y) == STBCC_NULL_UNIQUE_ID) {
                printf("Grid square (%d, %d) is uninitialized or invalid.\n", x, y);
            }
        }
    }
    printf("stbcc_grid verification complete.\n");

    // Debug: Verify the state of the map array
    printf("Verifying g->map state after initialization...\n");
    for (int y = 0; y < PADDED_HEIGHT; ++y) {
        for (int x = 0; x < (PADDED_WIDTH / 8); ++x) {
            printf("%02x ", g->map[y][x]);
        }
        printf("\n");
    }
    printf("g->map verification complete.\n");

    free(g);
    return 0;
}
