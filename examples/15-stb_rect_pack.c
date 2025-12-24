// Example demonstrating rectangle packing using stb_rect_pack.h
#define STB_RECT_PACK_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>

#define MAX_RECTS 10
#define BIN_WIDTH  256
#define BIN_HEIGHT 256

int main() {
    // Define rectangles to pack
    stbrp_rect rects[MAX_RECTS];
    for (int i = 0; i < MAX_RECTS; i++) {
        rects[i].id = i;
        rects[i].w = (i + 1) * 10; // Width increases with index
        rects[i].h = (i + 1) * 5;  // Height increases with index
        rects[i].was_packed = 0;
    }

    // Initialize the packing context
    stbrp_context context;
    stbrp_node nodes[BIN_WIDTH];
    stbrp_init_target(&context, BIN_WIDTH, BIN_HEIGHT, nodes, BIN_WIDTH);

    // Pack the rectangles
    stbrp_pack_rects(&context, rects, MAX_RECTS);

    // Print the results
    printf("Packing results:\n");
    for (int i = 0; i < MAX_RECTS; i++) {
        if (rects[i].was_packed) {
            printf("Rect %d packed at (%d, %d)\n", rects[i].id, rects[i].x, rects[i].y);
        } else {
            printf("Rect %d could not be packed\n", rects[i].id);
        }
    }

    return 0;
}
