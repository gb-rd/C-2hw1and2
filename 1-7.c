#include <stdio.h>
#include <inttypes.h>

uint32_t n = 0, mask = 0;

int main() {

    scanf("%u", &n);

    mask = ((1 << 8) - 1) << 24;

    printf("%u\n", (n ^ mask));
}
