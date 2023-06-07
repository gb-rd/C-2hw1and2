#include <stdio.h>
#include <inttypes.h>

uint32_t num=1, rest=1, count=0, weight = 1;
uint32_t ext_pos=0, pos_sum=0; 

int main() {

    scanf("%u", &num);

    if ((num >= 0) && (num < 1000000001)) {

    pos_sum = num;

        while((num != 0) | (ext_pos == 1)) {

            rest = num % 3;
            num  = num / 3;

            if (rest == 0) {
                if (ext_pos == 1) {
                    count++;
                    ext_pos = 0;
                    pos_sum = pos_sum + weight;
                }
            }

            else if (rest == 1) {
                count++;
                pos_sum = pos_sum + weight;
            }

            else if (rest == 2) {
                if (ext_pos == 0) {
                    count++;
                    pos_sum = pos_sum + weight;
                    ext_pos = 1;
                }
            }

            weight = weight * 3;
        }

        if (((pos_sum) / 2) <= 1000000) {
            printf("%u\n", count);
        }
        else {
           printf("%d\n", -1);
        }
    }
    else {
        printf("%d\n", -1);
    }
}
