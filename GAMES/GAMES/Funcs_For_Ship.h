#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int player, int shots);
void placeShips();
void placeComputerShips();
void attack(int x, int y, int player);
void battleship();
int Entership();
