#include "Menu.h"

void Menu(std::fstream& file, int& size)
{
	printf_s("-----------------------------------------------------------------------------------\n");
	printf_s("Enter\n");
	printf_s("1 to see content of array of tovars\n");
	printf_s("2 to add new tovars to array\n");
	printf_s("3 to find tovar with predetermined characteristics in company\n");
	printf_s("4 to change information about tovar\n");
	printf_s("5 to delete information about tovar\n");
	printf_s("6 to show all tovars in descending order\n");
	printf_s("7 to finish program\n");

	bool n = true;
	while (1)
	{
		int k = 0;
		k = Int_Enter();

		if (k == 1)
		{
			See_Content(file, size);
			break;
		}
		if (k == 2)
		{
			Add_New_Tovars(file, size);
			break;
		}
		if (k == 3)
		{
			Find_Tovar(file, size);
			break;
		}
		if (k == 4)
		{
			int otstup = Find_Tovar(file, size);
			Change_Tovar(file, otstup);
			break;
		}
		if (k == 5)
		{

			int otstup = Find_Tovar(file, size);
			if (otstup == -1)
			{

			}
			else
			{
				Delete_Tovar(file, otstup, size);
			}
			break;
		}
		if (k == 6)
		{
			Search_Workshop_Amount(file, size);
			break;
		}
		if (k == 7)
		{
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
		Menu(file, size);
	}

}
void Add_New_Tovars(std::fstream& file, int& size)
{
	while (1)
	{
		system("cls");
		printf_s("Choose type of input\n1-Enter preparied number of tovars\n2-Dialog with user\n3-Enter until don't face predetermined tovar\n");
		printf_s("-----------------------------------------------------------------------------------\n");
		int k;
		k = Int_Enter();
		if (k == 1)
		{
			Enter_Tovars_1(file, size);
			break;
		}
		else if (k == 2)
		{
			Enter_Tovars_2(file, size);
			break;
		}
		else if (k == 3)
		{
			Enter_Tovars_3(file, size);
			break;
		}
		else
		{
			std::cout << "Try again\n";
		}

	}

}
void See_Content(std::fstream& file, int& size)
{
	if (size == 0)
	{
		system("cls");
		printf_s("Sorry, but you didn't enter any tovar\n");

	}
	else 
	{
		file.open("File.bin", std::ios_base::binary | std::ios_base::in);
		for (int i = 0; i < size; i++)
		{
			Company Tovar;
			file.read((char*)&Tovar, sizeof(Tovar));
			Tovar_Show(Tovar);
			std::cout << '\n';
		}
		file.close();
	}
}

int Find_Tovar(std::fstream& file, int& size)
{
	system("cls");
	std::cout << "Enter predetermined characteristic of book\nTo find it\n";
	std::cout << "1 - to choose name of tovar\n";
	std::cout << "2 - to choose amount\n";
	std::cout << "3 - to choose workshop\n";

	int index;
	do
	{
		index = Int_Enter();
		if (index < 1 || index > 3)
		{
			std::cout << "Try again\n";
		}
	} while (index < 1 || index > 3);

	Company Tovar;
	{
		Tovar.Name[0] = '\0';

		Tovar.tovar.Ammount = 0;
		Tovar.tovar.Workshop_num = 0;
	}

	switch (index)
	{
	case(1):
	{
		system("cls");
		printf_s("Enter name of the tovar\n");
		String_Enter(Tovar.Name);
		break;
	}
	case(2):
	{
		system("cls");
		printf_s("Enter amount\n");
		Tovar.tovar.Ammount = Int_Enter();
		break;
	}
	case (3):
	{
		system("cls");
		printf_s("Enter workshop\n");
		Tovar.tovar.Workshop_num;
		break;
	}
	
	}

	bool ans;
	file.open("File.bin", std::ios_base::binary | std::ios_base::in);
	Company Product;
	int ret = 0;
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&Product, sizeof(Product));
		ans = Check_Tovar(Product, Tovar, index);

		if (ans)
		{
			break;
		}
		ret++;
	}

	file.close();

	if (ans == false)
	{
		system("cls");
		std::cout << "No such tovar\n";
		return -1;
	}

	else if (ans)
	{
		system("cls");
		Tovar_Show(Product);
		std::cout << "\n";
		return ret;
	}
}
void Change_Tovar(std::fstream& file, int otstup)
{
	system("cls");
	std::cout << "Enter predetermined characteristic of tovar to change it\n";
	std::cout << "1 - to choose name of tovar\n";
	std::cout << "2 - to choose amount\n";
	std::cout << "3 - to choose workshop\n";

	int index;
	do
	{
		index = Int_Enter();
		if (index < 1 || index > 3)
		{
			std::cout << "Try again\n";
		}
	} while (index < 1 || index > 3);

	Company Tovar;
	file.open("File.bin", std::ios_base::binary | std::ios_base::in);
	file.seekg(otstup * sizeof(Company), std::ios::beg);
	file.read((char*)&Tovar, sizeof(Tovar));
	file.close();

	if (index == 1)
	{
		system("cls");
		char a[60];
		printf_s("Enter name of the tovar\n");
		String_Enter(Tovar.Name);
	}
	if (index == 2)
	{
		system("cls");
		printf_s("Enter amount\n");
		Tovar.tovar.Ammount = Int_Enter();
	}
	if (index == 3)
	{
		system("cls");
		printf_s("Enter workshop\n");
		Tovar.tovar.Workshop_num = Int_Enter();
	}
	
	FILE* file2;
	fopen_s(&file2, "File.bin", "rb+");
	fseek(file2, sizeof(Company) * otstup, 0);
	fwrite((char*)&Tovar, sizeof(Company), 1, file2);
	fclose(file2);
}

void Delete_Tovar(std::fstream& file, int otstup, int& size)
{
	FILE* file2;
	fopen_s(&file2, "File.bin", "rb+");
	Company Buffer;
	for (int i = otstup; i < size - 1; i++)
	{
		fseek(file2, (i + 1) * sizeof(Company), 0);
		fread(&Buffer, sizeof(Company), 1, file2);
		fseek(file2, i * sizeof(Company), 0);
		fwrite(&Buffer, sizeof(Company), 1, file2);
	}
	size--;
	fclose(file2);
}

void Search_Workshop_Amount(std::fstream& file, int& size)
{
	file.open("File.bin", std::ios::binary | std::ios::in);
	Company* mas = new Company[size];
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&mas[i], sizeof(Company));
	}
	file.close();

	Sort(mas, size);
	int num;
	system("cls");
	std::cout << "Please enter the num of workshop\n";
	num = Int_Enter();
	int kostil = 0;
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		if (mas[i].tovar.Workshop_num = num)
		{
			kostil++;
			Tovar_Show(mas[i]);
			std::cout << '\n';
		}
	}
	delete[] mas;
	if (kostil == 0)
	{
		system("cls");
		std::cout << "No such tovars\n";
	}
}