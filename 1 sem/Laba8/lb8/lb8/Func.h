#pragma once
#include "Tovar.h"

int NonStop();
int Enter();
int Enternum(int n);
float Enterf();

Tovar* MinusTovar(Tovar* information, int& n);

void enterstruct(Tovar*& structmas, int n);
void showTovar(Tovar* structmas, int n);
void searchinmas(Tovar* structmas, int n);
Tovar* insertSort(Tovar* a, int size);

void change(Tovar*& structmas, int n);
void AddTovar(Tovar*& structmas, int& n);

void menu(Tovar* structmas, int n);

