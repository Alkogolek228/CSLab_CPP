#include "Menu.h"

int main()
{
	system("color 0A");
	int size = 0;
	Repair* mas = File_Enter(size);
	Menu(mas, size);
}
