#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �����к���
#define ROW 9
#define	COL 9
#define	COLS COL+2
#define	ROWS  ROW+2
#define EASY_COUNT 10

// ��ʼ������

void initBoard(char Board[ROWS][COLS], int rows, int cols, char set);



// ��ӡ����
void displayBoard(char Board[ROWS][COLS], int rows, int cols);


//������
void setMine(char Board[ROWS][COLS], int row, int col);

void scouriMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
