#include "Enter.h"
#include "Funcs.h"
#include "Fabric.h"

int Int_Enter()
{
	int ans = 0;
	char c;
	while (1)
	{
		scanf_s("%d", &ans);
		scanf_s("%c", &c);

		if (ans < 0)
		{
			printf_s("Try again please\n");

		}
		else if (c != '\n')
		{
			while (std::cin.get() != '\n');
			printf_s("Try again please\n");
		}
		else if (c == '\n')
		{
			break;
		}
	}

	return ans;
}

void String_Enter(char str[])
{
	std::string ans;
	while (1)
	{
		ans.clear();
		getline(std::cin, ans);
		if (ans.length() >= 60)
		{
			std::cout << "Try again\n";
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < ans.length(); i++)
	{
		str[i] = ans[i];
	}
	str[ans.length()] = '\0';

}

void Tovar_Input(Company& Tovar)
{
	system("cls");
	printf_s("Enter name of the tovar\n");
	String_Enter(Tovar.Name);
	system("cls");
	std::cout << "What amount of tovars was producted?\n";
	Tovar.tovar.Ammount = Int_Enter();
	system("cls");
	std::cout << "What number of the worshop?\n";
	Tovar.tovar.Workshop_num = Int_Enter();
}

void Tovar_Input_Only_1_Field(Company& Tovar)
{
	system("cls");
	std::cout << "Choose field:\n";
	printf_s("1 - name of the tovar\n");
	printf_s("2 - amount\n");
	printf_s("3 - by what workshop was produced\n");

	int k;
	do
	{
		k = Int_Enter();
		if (k < 1 || k > 3)
		{
			system("cls");
			std::cout << "Try again\n";
		}

	} while (k < 1 || k > 3);

	if (k == 1)
	{
		system("cls");
		printf_s("Enter name of the tovar\n");
		String_Enter(Tovar.Name);
	}
	else
	{
		Tovar.Name[0] = 'P';
		Tovar.Name[1] = 'C';
		Tovar.Name[2] = '\0';
	}
	if (k == 2)
	{
		system("cls");
		printf_s("Enter amount\n");
		Tovar.tovar.Ammount = Int_Enter();
	}
	else
	{
		Tovar.tovar.Ammount = rand() % 500 + 100;
	}
	if (k == 3)
	{
		system("cls");
		printf_s("Enter workshop\n");
		Tovar.tovar.Workshop_num = Int_Enter();
	}
	else
	{
		Tovar.tovar.Workshop_num = rand() % 11;
	}
}

// выбор режима ввода
void Enter_Tovars_1(std::fstream& file, int& size)
{
	system("cls");
	printf_s("Choose type of input\n1-Enter full struct\n2-Enter only 1 characteristic\n");
	printf_s("-----------------------------------------------------------------------------------\n");
	while (1)
	{
		int j = 0;
		j = Int_Enter();
		if (j == 1)
		{
			int k = 0;
			system("cls");
			printf_s("Number of tovars\n");
			k = Int_Enter();
			for (int i = 0; i < k; i++)
			{
				Company Tovar;
				Tovar_Input(Tovar);
				File_Enter(file, Tovar);
			}
			size += k;
			break;
		}
		else if (j == 2)
		{
			int k = 0;
			system("cls");
			printf_s("Number of tovars\n");
			k = Int_Enter();
			for (int i = 0; i < k; i++)
			{
				Company Tovar;
				Tovar_Input_Only_1_Field(Tovar);
				File_Enter(file, Tovar);
			}
			size += k;
			break;
		}
		else
		{
			system("cls");
			std::cout << "Try again\n";
		}
	}
}

void Enter_Tovars_2(std::fstream& file, int& size)
{
	system("cls");
	printf_s("Choose type of input\n1-Enter full struct\n2-Enter only 1 characteristic\n");
	printf_s("-----------------------------------------------------------------------------------\n");

	int j = 0;
	do
	{
		j = Int_Enter();
		if (j != 1 && j != 2)
		{
			system("cls");
			std::cout << "Try again\n";
		}
	} while (j != 1 && j != 2);

	if (j == 1)
	{
		while (1)
		{
			system("cls");
			std::cout << "Want to enter one more tovar?\n";
			std::cout << "1 Yes, 2 No\n";
			int ch = Int_Enter();

			if (ch == 1)
			{
				Company Tovar;
				Tovar_Input(Tovar);
				File_Enter(file, Tovar);
				size++;
			}
			
			else if (ch == 2)
			{
				break;
			}

			else if (ch != 1 || ch != 2)
			{
				system("cls");
				std::cout << "Try again\n";
			}
		}
	}

	else if (j == 2)
	{
		while (1)
		{
			system("cls");
			std::cout << "Want to enter one more tovar?\n";
			std::cout << "1 Yes, 2 No\n";
			int n = Int_Enter();
			if (n == 1)
			{
				Company Tovar;
				Tovar_Input_Only_1_Field(Tovar);
				File_Enter(file, Tovar);
				size++;
			}
			else if (n == 2)
			{
				break;
			}

			else if (n != 1 || n != 2)
			{
				system("cls");
				std::cout << "Try again\n";
			}
		}
	}
}

void Enter_Tovars_3(std::fstream& file, int& size)
{
	system("cls");
	std::cout << "Enter predetermined characteristic of tovar:\n";
	std::cout << "1 - to choose name of the tovar\n";
	std::cout << "2 - to choose amount\n";
	std::cout << "3 - to choose workshop\n";

	int index;
	do
	{
		index = Int_Enter();
		if (index < 1 || index > 3)
		{
			system("cls");
			std::cout << "Try again\n";
		}
	} while (index < 1 || index > 3);

	Company detTovar;
	{
		detTovar.Name[0] = '\0';
		detTovar.tovar.Ammount = 0;
		detTovar.tovar.Workshop_num = 0;
	}

	switch (index)
	{
	case(1):
	{
		system("cls");
		printf_s("Enter name of the tovar\n");
		String_Enter(detTovar.Name);
		break;
	}
	case(2):
	{
		system("cls");
		printf_s("Enter amount\n");
		detTovar.tovar.Ammount = Int_Enter();
		break;
	}
	case (3):
	{
		system("cls");
		printf_s("Enter workshop\n");
		detTovar.tovar.Workshop_num = Int_Enter();
		break;
	}

	}
	system("cls");
	printf_s("Choose type of input\n1-Enter full struct\n2-Enter only 1 characteristic\n");
	printf_s("-----------------------------------------------------------------------------------\n");
	while (1)
	{
		int j = 0;
		j = Int_Enter();

		if (j == 1)
		{
			Company Tovar;
			do
			{
				Tovar_Input(Tovar);
				File_Enter(file, Tovar);
				size++;
			} while (!Check_Tovar(detTovar, Tovar, index));
			break;
		}

		else if (j == 2)
		{
			Company Tovar;
			do
			{
				Tovar_Input_Only_1_Field(Tovar);
				File_Enter(file, Tovar);
				size++;
			} while (!Check_Tovar(detTovar, Tovar, index));
			break;
		}
		else
		{
			system("cls");
			std::cout << "Try again\n";
		}
	}
}

void Tovar_Show(Company Tovar)
{
	system("cls");
	printf_s("Enter name of the tovar: ");
	std::cout << Tovar.Name << '\n';

	printf_s("Enter amount: ");
	std::cout << Tovar.tovar.Ammount << '\n';

	printf_s("Enter workshop: ");
	std::cout << Tovar.tovar.Workshop_num<< '\n';
}

void File_Enter(std::fstream& file, Company Tovar)
{
	file.open("File.bin", std::ios::binary | std::ios::app);
	file.write((char*)&Tovar, sizeof(Company));
	file.close();
}
