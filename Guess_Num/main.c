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
                printf("�Ƿ����룬����������\n");
                break;
        }
        //ѡ��õȼ��Ϳ��Կ�ʼ��Ϸ��
        if (grade == 1 || grade == 2) {
            break;
        }
    } while (1);

    printf("������ %d �λ���\n", times);

    while(1){
        if(times ==0){
            printf("�����ù���Ϸʧ�ܣ���\n");
            break;
        }
        printf("������Ҫ�µ�����>��");
        scanf("%d", &guess);

        if(guess > result){
            times--;//ÿ��һ�δ����ͼ�һ
            printf("�´���\n");
            printf("������ %d �λ���\n", times);
        } else if (guess < result) {
            times--;//ÿ��һ�δ����ͼ�һ
            printf("��С��\n");
            printf("������ %d �λ���\n", times);
        } else {
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
                printf("�Ƿ����룬���������룡\n");
        }
    } while (input);

        return 0;
}
