#include <stdio.h>
#include <inttypes.h>

int main() {

    uint32_t a=0, n=0, x=0;

    scanf("%u", &n);

    for(int i=0; i<n; i++) {

        scanf("%u", &a);
        x = (a ^ x);
    }

    printf("%u\n", x);
}
