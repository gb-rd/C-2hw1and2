#include <stdio.h>
#include <inttypes.h>

uint32_t n = 0, k = 0;

int main() {
    scanf("%u %u", &n, &k);
    n = n << (32 - k);
    n = n >> (32 - k);
    printf("%u\n", n);
}

