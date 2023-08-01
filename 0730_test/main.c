#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void mulTable(){
    int result;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            result = i * j;
            printf("%d * %d = %d ",i,j,result);
        }
        printf("\n");
    }
}
void findMax(){
    int num[10];
    int max = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 10; ++i) {
        if (max < num[i]) {
            max = num[i];
        }

    }
    printf("输入的十个数中的最大值是：%d\n", max);
}
void test(){
    float result = 0;
    bool flag = true;
    for (int i = 1; i <= 100; i++) {
        if(flag){
            result += (1.0 / i);
            flag = !flag;
        } else{
            result -= (1.0 / i);
            flag = !flag;
        }
    }
    printf("%f\n", result);
}
void nine(){
    int count = 0;
    printf("1到100带9的数字有：");
    for (int i = 1; i < 100; ++i) {
        if (i % 10 == 9 || i / 10 == 9) {
            printf("%d ", i);
        }
        if (i % 10 == 9) {
            count++;
        }
        if (i / 10 == 9) {
            count++;
        }
    }
    printf("\n数字9出现的次数是：%d\n", count);
}
//素数判断
int isPrime(int a) {
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) {
            return 0;
        } else if (a == i) {//确保能从2一直判断到a
            return 1;
        }
    }
}
void printPrime(int a,int b){//素数打印
    for (int i = a; i <= b; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}
int main() {
    printPrime(100, 200);
    int arr[10] = {0};
    return 0;
}
