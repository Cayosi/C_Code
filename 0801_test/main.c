#include <stdio.h>
int factorial(int num){
    if (num == 1) {
        return 1;

    } else{
        return num * factorial(num - 1);
    }
}

int main() {
    printf("%d\n",factorial(5));

    int a;
//    ��ӡ������
     while (scanf("%d", &a) != EOF) { // ע�� while ������ case
        // 64 λ������� printf("%lld") to
         for (int i = 0; i < a; ++i) {
             if (i == 0 || i == a - 1) {
                 for (int j = 0; j < a; ++j) {
                     printf("* ");
                 }
             } else{
                 printf("* ");
                 for (int j = 0; j < a-2 ; ++j) {
                     printf("  ");
                 }
                 printf("* ");
             }

             printf("\n");
         }

    }
    return 0;
}

