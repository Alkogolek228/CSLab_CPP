#pragma once
#include "Fabric.h"
#include "Enter.h"
#include "Funcs.h"

void Menu(std::fstream& file, int& size);
void See_Content(std::fstream& file, int& size);
void Add_New_Tovars(std::fstream& file, int& size);
int Find_Tovar(std::fstream& file, int& size);
void Change_Tovar(std::fstream& file, int otstup);
void Delete_Tovar(std::fstream& file, int otstup, int& size);
void Search_Workshop_Amount(std::fstream& file, int& size);