#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
        printf("************************\n");
        printf("******  1. play  *******\n");
        printf("******  0. exit  *******\n");
        printf("************************\n");

}
void menu2() {
    printf("**************************\n");
    printf("******  1. normal  *******\n");
    printf("******  2. hard    *******\n");
    printf("**************************\n");

}
void game(){
    int result = rand() % 100 + 1;
    int guess;
    int grade;
    int times;
    do {
        menu2();
        scanf("%d", &grade);
        switch (grade) {
            case 1:
                times = 10;
                break;
            case 2:
                times = 5;
                break;
            default:
                printf("非法输入，请重新输入\n");
                break;
        }
        //选择好等级就可以开始游戏了
        if (grade == 1 || grade == 2) {
            break;
        }
    } while (1);

    printf("您共有 %d 次机会\n", times);

    while(1){
        if(times ==0){
            printf("次数用光游戏失败！！\n");
            break;
        }
        printf("请输入要猜的数字>：");
        scanf("%d", &guess);

        if(guess > result){
            times--;//每猜一次次数就减一
            printf("猜大了\n");
            printf("您还有 %d 次机会\n", times);
        } else if (guess < result) {
            times--;//每猜一次次数就减一
            printf("猜小了\n");
            printf("您还有 %d 次机会\n", times);
        } else {
            printf("恭喜你猜对了！！！\n");
            break;
        }
    }

}
int main() {
    int input;
    srand((unsigned int)time(NULL));
    do {
        menu();
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                break;
            default:
                printf("非法输入，请重新输入！\n");
        }
    } while (input);

        return 0;
}
