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
            printf("�ҵ������±�Ϊ %d ��Ԫ��\n",mid);
            result = 1;
            break;
        }
        }
    if (result == 0) {
        printf("������û�и�Ԫ��\n");
    }


    return 0;
}
