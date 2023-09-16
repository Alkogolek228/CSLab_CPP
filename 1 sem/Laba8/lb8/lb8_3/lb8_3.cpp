#include "Menu.h"

int main()
{
	system("color 0A");
	int size = 0;
	std::fstream file; // clear file
	file.open("File.bin", std::ios::out);
	file.close();
	Menu(file, size);
}

