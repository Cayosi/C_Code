#include <iostream>


//short num1 =0; // 全局变量
//int main() {
//    short num2 = 3; // 局部变量
//    short num1 = 2;
//    printf("%d\n",num1);
//    printf("%d\n",num2);
//    return 0;
//}

//int main() {
//    int a;
//    int b;
//    b = 3 - 2;
//    a = 6 + 7;
//    printf("%d\n", a);
//    printf("%d\n", b);
//    b = a * 2;
//    printf("%d\n", b);
//    return 0;
//
//}
//int main(){
//    float a;
//    float b;
//    b = 3.0 / 2;
//    a = 3 / 2.0;
//    printf("%f\n", a);//结果是1.500000
//    printf("%f\n", b);//结果是1.500000
//
//}
//int main(){
//    short a;
//    a = 2 / 3;
//    printf("%d\n", a);
//    a = 3 / 2;
//    printf("%d\n", a);
//    return 0;
//}
//int main(){
//    printf("%d\n", -5 % 3); //-2
//    printf("%d\n", 5 % -3); //2
//    return 0;
//}
//int main(){
//    int a = 1;
//    int b = 2;
//    b = ++a;
//    printf("%d\n",a);//2
//    printf("%d\n",b);//2
//    return 0;
//}
//int main(){
//    int a = 1;
//    int b = 2;
//    b = a++;
//    printf("%d\n",a);//2
//    printf("%d\n",b);//1
//    return 0;
//}
//int main(){
//    int a;
//    a =(int ) 4.1;
//    printf("%d\n",a); //4
//    return 0;
//}

int main() {
    int num;
    while (scanf("%d",&num) != EOF) {
        for (; num >0; num--) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}