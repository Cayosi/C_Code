#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义行和列
#define ROW 9
#define	COL 9
#define	COLS COL+2
#define	ROWS  ROW+2
#define EASY_COUNT 10

// 初始化棋盘

void initBoard(char Board[ROWS][COLS], int rows, int cols, char set);



// 打印棋盘
void displayBoard(char Board[ROWS][COLS], int rows, int cols);


//布置雷
void setMine(char Board[ROWS][COLS], int row, int col);

void scouriMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
