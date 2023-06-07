#include <stdio.h>
#include <inttypes.h>

uint32_t n = 0, k = 0, x = 0, max = 0;
uint32_t mask = 0;
int i = 0;

int main() {

    scanf("%u %u", &n, &k);

    mask = (1 << k) - 1;

    for (i = 0; i < 33 - k; i++)
    {
        x = (n >> i) & mask;
        if (x > max) {
            max = x;
        }
    }

    printf("%b\n", max);
}
