#include <stdio.h>

int main() {

    int a=0, n=0;
    int max_num=0, count_max_num=0;

    {
        for(int cur = 1;;)
        {
            max_num = cur;
            cur = (cur<<1) + 1;
            if (cur <= max_num) break;
        }
        max_num++;
    }

    while (n <= 0) {

        //printf("Введите размер последовательности (N > 0)\n");
        scanf("%d", &n);

        for(int i=0; i<n; i++) {

            //printf("Введите число: \n");
            scanf(" %d", &a);

            if (a > max_num) {
                max_num = a;
                count_max_num = 1;
            }
            else if (a == max_num) {
                count_max_num++;
            }
        }
    }

    //printf("max num = %d  max num count = %d\n", max_num, count_max_num);
    printf("%d\n", count_max_num);

}
