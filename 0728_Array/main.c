#include <stdio.h>

int GetMaxValOfArray(int arr[],int num){
    int max = arr[0];
    for (int i = 0; i < num; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int GetMinValOfArray(int arr[],int num){
    int min=arr[0];
    for (int i = 0; i < num; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
void PrintArray(int arr[],int num){
    printf("数组所有的元素依次是：");
    for (int i = 0; i < num; ++i) {
        printf("%d", arr[i]);
        if (i == (num - 1)) {
            break;
        }
        printf(", ");

    }
}


int main() {
    int test[] = {1, 2, 3, 4, 514, 234};
    PrintArray(test,6);
    printf("\ntest中的最大值是：%d ",GetMaxValOfArray(test, 6));
    printf("\ntest中的最小值是：%d ",GetMinValOfArray(test, 6));
    return 0;
}
