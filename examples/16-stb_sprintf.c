// Example demonstrating fast string formatting using stb_sprintf.h
#define STB_SPRINTF_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[256];

    // Format a string with integers and floats
    int age = 25;
    float height = 5.9;
    stbsp_sprintf(buffer, "I am %d years old and %.1f feet tall.", age, height);
    printf("%s\n", buffer);

    // Format a string with hexadecimal and binary values
    int value = 255;
    stbsp_sprintf(buffer, "Value in hex: 0x%X, in binary: 0b%b", value, value);
    printf("%s\n", buffer);

    // Format a string with a large number
    long long big_number = 123456789012345LL;
    stbsp_sprintf(buffer, "Large number: %lld", big_number);
    printf("%s\n", buffer);

    return 0;
}
