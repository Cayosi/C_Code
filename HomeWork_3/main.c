#include <stdio.h>

void sort(){
    int a, b, c;
    int temp = 0;
    scanf("%d %d %d", &a, &b,&c);
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b < c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    printf("%d %d %d", a, b, c);
}

void threeMult(){
    for (int i = 1; i < 100; ++i) {
        if (i % 3 == 0) {
            printf("%d ", i);

        }
    }
}

int main() {
    sort();
    return 0;
}
