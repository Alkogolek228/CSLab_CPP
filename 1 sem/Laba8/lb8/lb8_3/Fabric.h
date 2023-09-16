#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ranges>
#include <stdio.h>

typedef union Workshop
{
	int Workshop_num;
	int Ammount;
};

typedef class Company
{
public:

	Workshop tovar;
	char Name[60];
};

