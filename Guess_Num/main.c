#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
        printf("************************\n");
        printf("******  1. play  *******\n");
        printf("******  0. exit  *******\n");
        printf("************************\n");

}
void game(){
    int result = rand() % 100 + 1;
    int guess;
    while(1){
        printf("请输入要猜的数字>：");
        scanf("%d", &guess);
        if(guess > result){
            printf("猜大了\n");
        } else if (guess < result) {
            printf("猜小了\n");
        } else{
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
                printf("非法输入，请重新输入\n");
        }
    } while (input);

        return 0;
}
