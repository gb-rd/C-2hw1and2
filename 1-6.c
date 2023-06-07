#include <stdio.h>
#include <inttypes.h>

uint32_t n = 0, x = 0;
int i = 0;

int main() {

    scanf("%u", &n);

    for (i = 1; i < 33; i++)
    {
        if ((n >> i) & 1) x++;
    }

    printf("%u\n", x);
}
