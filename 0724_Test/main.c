#include <stdio.h>
#include <math.h>
int main() {

    int cup = 1;
    int num;
    scanf("%d", &num);
    while ((num = num / 10) != 0) {
        cup++;
    }
    printf("%dÊÇ",num);
    printf("%dÎ»Êı\n",cup);

    int sum;
    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0) {
            sum += i;
        }

    }
    printf("sum = %d\n", sum);


    for (int i = 0; i < 11; ++i) {
        printf("%d ",i);
    }
    printf("\n");


    int j = 0;
    int n = 0;
    scanf("%d",&n);
    while (n){
        printf("%d ", n % 10);
        n = n / 10;
    }

    printf("\n");
    while (j < 11){
        printf("%d ", j);
        j++;
    }
    printf("\n");


    int test = 1;
    do {

        printf("%d ", test);
        test++;
    } while (test <= 10);


    return 0;
}
