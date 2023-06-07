#include <stdio.h>
#include <inttypes.h>

int extractExp(float value) {
    union {
        uint32_t i;
        float f;
    } x;

    x.f = value;
    uint32_t bits = x.i;
    uint32_t exponentWithBias = (bits >> 23) & 0xff;

    return exponentWithBias;
}

void main(void) {
    float input;
    scanf("%f", &input);
    printf("%u\n", extractExp(input));
}
