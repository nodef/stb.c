// Example rendering text from a TrueType font using stb_truetype.h
#define STB_TRUETYPE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FONT_SIZE 24
#define BITMAP_WIDTH 512
#define BITMAP_HEIGHT 512

int main() {
    // Load the font file
    FILE *fontFile = fopen("examples/Arial.ttf", "rb");
    if (!fontFile) {
        fprintf(stderr, "Failed to open font file\n");
        return 1;
    }

    fseek(fontFile, 0, SEEK_END);
    size_t fontSize = ftell(fontFile);
    fseek(fontFile, 0, SEEK_SET);

    unsigned char *fontBuffer = (unsigned char *)malloc(fontSize);
    fread(fontBuffer, 1, fontSize, fontFile);
    fclose(fontFile);

    // Initialize font
    stbtt_fontinfo font;
    if (!stbtt_InitFont(&font, fontBuffer, stbtt_GetFontOffsetForIndex(fontBuffer, 0))) {
        fprintf(stderr, "Failed to initialize font\n");
        free(fontBuffer);
        return 1;
    }

    // Create a bitmap to render the text
    unsigned char bitmap[BITMAP_WIDTH * BITMAP_HEIGHT];
    memset(bitmap, 0, sizeof(bitmap));

    // Scale the font
    float scale = stbtt_ScaleForPixelHeight(&font, FONT_SIZE);

    // Get font metrics
    int ascent, descent, lineGap;
    stbtt_GetFontVMetrics(&font, &ascent, &descent, &lineGap);
    ascent = (int)(ascent * scale);
    descent = (int)(descent * scale);

    // Render a string
    const char *text = "Hello, stb_truetype!";
    int x = 10; // Starting x position
    int y = ascent; // Starting y position

    for (const char *p = text; *p; p++) {
        int advanceWidth, leftSideBearing;
        stbtt_GetCodepointHMetrics(&font, *p, &advanceWidth, &leftSideBearing);

        int c_x1, c_y1, c_x2, c_y2;
        stbtt_GetCodepointBitmapBox(&font, *p, scale, scale, &c_x1, &c_y1, &c_x2, &c_y2);

        int byteOffset = x + (y + c_y1) * BITMAP_WIDTH;
        stbtt_MakeCodepointBitmap(&font, bitmap + byteOffset, c_x2 - c_x1, c_y2 - c_y1, BITMAP_WIDTH, scale, scale, *p);

        x += (int)(advanceWidth * scale);
        if (*(p + 1)) {
            x += (int)(stbtt_GetCodepointKernAdvance(&font, *p, *(p + 1)) * scale);
        }
    }

    // Save the bitmap as a PGM file
    FILE *output = fopen("output.pgm", "wb");
    fprintf(output, "P5\n%d %d\n255\n", BITMAP_WIDTH, BITMAP_HEIGHT);
    fwrite(bitmap, 1, sizeof(bitmap), output);
    fclose(output);

    printf("Rendered text saved to output.pgm\n");

    free(fontBuffer);
    return 0;
}
