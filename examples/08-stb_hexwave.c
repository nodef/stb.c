// Example demonstrating the use of stb_hexwave.h for synthesizing audio waveforms
#define STB_HEXWAVE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    stb_hw_synth synth;
    stb_hw_init(&synth, 44100); // Initialize synthesizer with 44.1 kHz sample rate

    stb_hw_add_wave(&synth, STB_HW_SINE, 440.0f, 0.5f); // Add a sine wave at 440 Hz (A4)
    stb_hw_add_wave(&synth, STB_HW_SQUARE, 220.0f, 0.3f); // Add a square wave at 220 Hz (A3)

    short buffer[44100]; // Buffer for 1 second of audio
    stb_hw_generate(&synth, buffer, 44100);

    printf("Generated 1 second of audio:\n");
    for (int i = 0; i < 100; ++i) { // Print the first 100 samples
        printf("%d\n", buffer[i]);
    }

    stb_hw_free(&synth);
    return 0;
}
