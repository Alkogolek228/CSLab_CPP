#pragma once
#include "Fabric.h"

int Int_Enter();
void String_Enter(char str[]);

void Tovar_Input(Company& Tovar);
void Tovar_Input_Only_1_Field(Company& Tovar);

void Enter_Tovars_1(std::fstream& file, int& size);
void Enter_Tovars_2(std::fstream& file, int& size);
void Enter_Tovars_3(std::fstream& file, int& size);

void Tovar_Show(Company Tovar);

void File_Enter(std::fstream& file, Company Tovar);
