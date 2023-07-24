#include <stdio.h>

int main() {
    int flag;
    int cpu = 0;
    for (int i = 101; i <= 199; i++) {
        flag = 1;
        for (int j = 2; j < i - 1; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cpu += i;
            printf("%d\n", i);

        }
    }
    printf("%d\n", cpu);

    return 0;
}
