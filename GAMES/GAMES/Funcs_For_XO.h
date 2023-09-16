#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ROWS 3
#define COLS 3
#define TO_WIN 3

void printBoard(char board[ROWS][COLS]);
int checkVictory(char board[ROWS][COLS]);
int checkDraw(char board[ROWS][COLS]);
void XOgame();