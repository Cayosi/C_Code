#include <stdio.h>

int main() {
    int a, b,c;
    while (scanf("%d %d %d", &a, &b,&c) != EOF) {
        if ((a + b > c) && (a + c > b) && (b + c > a)) {
            if (a == b || a == c || b == c) {
                if (a == b && b == c && a == c) {
                    printf("Equilateral triangle!\n");
                } else {
                    printf("Isosceles triangle!\n");
                }
            } else {
                printf("Ordinary triangle!\n");
            }
        } else {
            printf("Not a triangle!\n");
        }
    }
    return 0;
}