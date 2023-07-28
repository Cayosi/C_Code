#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = sz -1;
    int key = 0;
    int result = 0;
    int mid = 0;
    scanf("%d",&key);
    while (left <= right) {
         mid = (left + right) / 2;
        if (arr[mid] > key) {
            right = mid - 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else if (arr[mid] == key){
            printf("找到了是下标为 %d 的元素\n",mid);
            result = 1;
            break;
        }
        }
    if (result == 0) {
        printf("数组中没有该元素\n");
    }


    return 0;
}
