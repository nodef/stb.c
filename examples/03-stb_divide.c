// Example demonstrating the use of stb_divide.h for Euclidean division
#define STB_DIVIDE_IMPLEMENTATION
#include <stb.h>
#include <stdio.h>

int main() {
    int dividend = -17;
    int divisor = 5;

    int quotient = stb_div_floor(dividend, divisor);
    int remainder = stb_mod_floor(dividend, divisor);

    printf("Dividend: %d, Divisor: %d\n", dividend, divisor);
    printf("Quotient: %d, Remainder: %d\n", quotient, remainder);

    return 0;
}
