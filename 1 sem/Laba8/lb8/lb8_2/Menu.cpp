#include "Func.h"

void Menu(Repair* mas, int& size)
{
	printf_s("-----------------------------------------------------------------------------------\n");
	printf_s("Enter\n");
	printf_s("1 to see content of array of products\n");
	printf_s("2 to add new structures to arrray of products\n");
	printf_s("3 to find structure with predetermined characteristic in array of products\n");
	printf_s("4 to delete and change structure with predetermined characteristic from array of products\n");
	printf_s("5 to show the condition\n");
	printf_s("6 to finish program\n");

	bool n = true;
	while (1)
	{
		int k = 0;
		k = Int_Enter();

		if (k == 1)
		{
			See_Content(mas, size);
			break;
		}
		if (k == 2)
		{
			mas = Add_Struct(mas, size);
			break;
		}
		if (k == 3)
		{
			Find_Struct(mas, true, size);
			break;
		}
		if (k == 4)
		{
			int k = Find_Struct(mas, false, size);
			if (k != -1)
			{
				printf_s("Choose action\n");
				printf_s("1 - to delete\n");
				printf_s("2 - to change\n");
				int c = 0;

				while (1)
				{
					c = Int_Enter();

					if (c == 1)
					{
						Delete_Struct(mas, k, size);
						break;
					}
					if (c == 2)
					{
						Change_Struct(mas[k]);
						break;
					}
					else
					{
						printf_s("Please try again\n");
					}
				}

			}
			break;
		}

		if (k == 5)
		{
			printf_s("Condition of repairing\n");
			See_Content_Condition(mas, size);
			break;
		}

		if (k == 6)
		{
			File_Recording(mas, size);
			printf_s("Program is finished\n");
			n = false;
			break;
		}
		else
		{
			printf_s("Try again\n");
		}
	}
	if (n)
	{
		Menu(mas, size);
	}
}