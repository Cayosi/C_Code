#include <stdio.h>
#include <string.h>

//每个程序只能有一个main方法，main方法是每个程序的入口
int main() {
    char arr2[] = {'a', 'b', 'c'};
//    字符串后面默认会有一个 "\0"
    char arr1[] = "abc";
    printf("%s\n",arr1);

    printf(arr2);
    return 0;
}
//int main(){
//    int i = 32;
//    printf("%d\n",i);
//    printf("%c\n",'t');
//    printf("%f\n",2.1);
//}
