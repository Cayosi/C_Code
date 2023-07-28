
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 0;
    int find = 0;
    scanf("%d", &key);
    int sz = sizeof(arr) / arr[0];
    for (int i = 0; i <= sz; i++) {
        if (key == arr[i]) {
            printf("找到了是下标为 %d 的元素\n", i);
            find = 1;
            break;
        }

    }
    if (find == 0) {
        printf("数组中没有该元素");
    }
    return 0;
}
