#pragma once
#include "Repair.h"

int Int_Enter();
void My_getline(std::string& str);
std::string String_Enter();
Repair* File_Enter(int& size);
void Enter_Struct(Repair& mas);

void Show_Struct_One_Field(Repair& mas, int chart1);
void Show_Struct(Repair mas);
void Show_Struct_Condition(Repair mas);

void File_Recording(Repair* mas, int& size);

bool Characteristic_check(Repair mas, int charact, std::string name, std::string make, std::string date, int condition);

Repair* resize(Repair* mas, int num_structs, int& size);
Repair* resize2(Repair* mas, int start_size, int end_size);

void See_Content(Repair* mas, int& size);
void See_Content_Condition(Repair* mas, int& size);

Repair* Create_Repair(int& size);
Repair* Add_Struct(Repair* mas, int& size);
void Delete_Struct(Repair* mas, int index, int& size);
void Change_Struct(Repair& mas);

int Find_Struct(Repair* mas, bool show, int& size);


