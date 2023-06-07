#include <stdio.h>
#include <inttypes.h>

uint32_t n = 0, k = 0;

int main() {
    scanf("%u %u", &n, &k);
    printf("%u\n", ((n >> k)|(n << (32 - k))));
}

