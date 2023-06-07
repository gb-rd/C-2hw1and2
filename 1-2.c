#include <stdio.h>

#define LETTERS 26

int main() {

    int n=0, a=0;

    if (scanf("%d ", &n) == 1) {

        while((a=getchar()) != '.') {

            if ((a >= 'A') && (a <= 'Z')) {

                a = a + (n % LETTERS);
                if (a > 'Z') {
                      a = a - LETTERS;
                }

                printf("%c", a);
            }

            else if ((a >= 'a') && (a <= 'z')) {

                a = a + (n % LETTERS);
                if (a > 'z') {
              	      a = a - LETTERS;
                }

                printf("%c", a);
            }

            else if (a = ' ') {

                printf("%c", a);
            }
        }

        printf(".\n");
    }
}
