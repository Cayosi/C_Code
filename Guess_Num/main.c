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
        printf("������Ҫ�µ�����>��");
        scanf("%d", &guess);
        if(guess > result){
            printf("�´���\n");
        } else if (guess < result) {
            printf("��С��\n");
        } else{
            printf("��ϲ��¶��ˣ�����\n");
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
                printf("�Ƿ����룬����������\n");
        }
    } while (input);

        return 0;
}
