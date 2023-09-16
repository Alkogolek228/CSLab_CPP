#include "Repair.h"

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

void My_getline(std::string& str)
{
	char c;
	scanf_s("%c", &c);

	while (c != '\n')
	{
		str.push_back(c);
		scanf_s("%c", &c);
	}
}

std::string String_Enter()
{
	while (1)
	{
		std::string str;
		My_getline(str);
		bool prigodno_for_enter = true;
		long long space_symbol_num = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == ' ' || str[i] == '-'))
			{
				prigodno_for_enter = false;
			}
			if (str[i] == '-' && (i == 0 || i == str.length() || (!((str[i - 1] >= 'A' && str[i - 1] <= 'Z') || (str[i - 1] >= 'a' && str[i - 1] <= 'z')) || !((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z')))))
			{
				prigodno_for_enter = false;
			}
			if (str[i] == ' ') space_symbol_num++;
		}
		if (space_symbol_num == str.length())
		{
			prigodno_for_enter = false;
		}
		if (prigodno_for_enter)
		{
			return str;
			break;
		}
		else
		{
			std::cout << "Try again\n";
		}

	}
}

Repair* File_Enter(int& size)
{
	std::ifstream StartFile;
	StartFile.open("StartFile.txt", std::ios::in);
	std::string str;
	int num_str_file = 0;
	while (!StartFile.eof())
	{
		std::getline(StartFile, str);
		if (str != "\0")
		{
			num_str_file++;
		}
	}

	StartFile.close();
	StartFile.open("StartFile.txt", std::ios::in);
	int num_of_repair = num_str_file / 4;
	Repair* ans = new Repair[num_of_repair];

	for (int i = 0; i < num_of_repair; i++)
	{
		std::getline(StartFile, ans[i].Name);
		std::getline(StartFile, ans[i].Make);
		std::getline(StartFile, ans[i].Date);
		StartFile >> ans[i].Condition;
		int l = StartFile.tellg();

		if (StartFile.peek() == ' ' || StartFile.peek() == '\0' || StartFile.peek() == '\n')
		{
			l += 1;
		}
		StartFile.seekg(l, std::ios_base::beg);
	}
	size += num_of_repair;
	StartFile.close();
	return ans;
}

void Enter_Struct(Repair& mas)
{

	printf_s("Enter name\n");
	mas.Name = String_Enter();

	printf_s("Enter make\n");
	mas.Make = String_Enter();

	printf_s("Enter date\n");
	mas.Date = String_Enter();

	printf_s("Enter condition\n");
	mas.Condition = Int_Enter();
}

void Show_Struct_One_Field(Repair& mas, int chart1)
{
	if (chart1 == 1)
	{
		printf_s("Enter name\n");
		mas.Name = String_Enter();
	}

	else
	{
		mas.Name = "PC";
	}

	if (chart1 == 2)
	{
		printf_s("Enter make\n");
		mas.Make = String_Enter();
	}
	else
	{
		mas.Make = "Lenovo";
	}
	if (chart1 == 3)
	{
		printf_s("Enter Date\n");
		mas.Date = String_Enter();
	}
	else
	{
		mas.Date = "11.11.2022";
	}
	if (chart1 == 4)
	{
		printf_s("Enter condition\n");
		mas.Condition = Int_Enter();
	}
	else
	{
		mas.Condition = 1;
	}
}

void Show_Struct(Repair mas)
{
	printf_s("Name: ");
	for (int i = 0; i < mas.Name.length(); i++)
	{
		printf_s("%c", mas.Name[i]);
	}

	printf_s("\n");

	printf_s("Make: ");
	for (int i = 0; i < mas.Make.length(); i++)
	{
		printf_s("%c", mas.Make[i]);
	}

	printf_s("\n");

	printf_s("Date: ");
	for (int i = 0; i < mas.Date.length(); i++)
	{
		printf_s("%c", mas.Date[i]);
	}

	printf_s("\n");
	printf_s("Condition: ");
	printf_s("%d", mas.Condition);
	printf_s("\n");
}

void Show_Struct_Condition(Repair mas)
{
	printf_s("Name: ");
	for (int i = 0; i < mas.Name.length(); i++)
	{
		printf_s("%c", mas.Name[i]);
	}

	printf_s("\n");

	printf_s("\n");
	printf_s("Condition: ");
	printf_s("%d", mas.Condition);
	printf_s("\n");
}

void File_Recording(Repair* mas, int& size)
{
	std::ofstream EndFile;
	EndFile.open("EndFile.txt", std::ios::out);
	for (int i = 0; i < size; i++)
	{
		EndFile << mas[i].Name << '\n';
		EndFile << mas[i].Make << '\n';
		EndFile << mas[i].Date << '\n';
		EndFile << mas[i].Condition << '\n';
		EndFile << '\n';
	}
}

bool Characteristic_check(Repair mas, int charact, std::string name, std::string make, std::string date, int condition)
{
	bool ans = false;
	if (charact == 1)
	{
		if (name != "&" && name == mas.Name)
		{
			ans = true;
		}
	}
	else
	{
		if (charact == 2)
		{
			if (make != "&" && make == mas.Make)
			{
				ans = true;
			}
		}
		else
		{
			if (charact == 3)
			{
				if (date != "&" && date == mas.Date)
				{
					ans = true;
				}
			}
			else
			{
				if (charact == 4)
				{
					if (condition != -1 && condition == mas.Condition)
					{
						ans = true;
					}
				}
			}
		}
	}

	return ans;
}

Repair* resize(Repair* mas, int num_structs, int& size)
{
	Repair* mas1 = new Repair[size];
	for (int i = 0; i < num_structs; i++)
	{
		mas1[i] = mas[i];
	}
	delete[] mas;
	return mas1;
}

Repair* resize2(Repair* mas, int start_size, int end_size)
{
	Repair* mas1 = new Repair[end_size];
	for (int i = 0; i < start_size; i++)
	{
		mas1[i] = mas[i];
	}
	delete[] mas;
	return mas1;
}

void See_Content(Repair* mas, int& size)
{
	if (size == 0)
	{
		printf_s("Sorry, but you didn't enter any product\n");
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			Show_Struct(mas[i]);
			printf_s("\n");
		}
	}
}

void See_Content_Condition(Repair* mas, int& size)
{
	if (size == 0)
	{
		printf_s("Sorry, but you didn't enter any product\n");
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			Show_Struct_Condition(mas[i]);
			printf_s("\n");
		}
	}
}

Repair* Create_Repair(int& size)
{
	int j;
	printf_s("Choose type of input\n1-Enter only 1 characteristic\n2-Enter full struct\n");
	printf_s("-----------------------------------------------------------------------------------\n");

	while (1)
	{
		j = 0;
		j = Int_Enter();
		if (j == 1)
		{
			printf_s("Choose characteristic\n");
			printf_s("Please enter:\n");
			printf_s("1 - name\n");
			printf_s("2 - make\n");
			printf_s("3 - date\n");
			printf_s("4 - condition\n");

			int chart1 = 0;
			while (chart1 > 4 || chart1 < 1)
			{
				chart1 = 0;
				chart1 = Int_Enter();
			}
			int n;
			printf_s("Choose type of input\n1-Enter preparied number of structs\n2-Dialog with user\n3-Enter until don't face predetermined struct\n");
			printf_s("-----------------------------------------------------------------------------------\n");

			while (1)
			{
				n = 0;
				n = Int_Enter();
				if (n == 1)
				{
					int k = 0;
					printf_s("Number of products \n");
					k = Int_Enter();

					Repair* mas = new Repair[k];
					//Input
					for (int i = 0; i < k; i++)
					{
						Show_Struct_One_Field(mas[i], chart1);
					}
					size += k;
					return mas;
				}
				else if (n == 2)
				{
					Repair* mas = new Repair[1];
					//Input
					int num_structs = 0;
					for (;;)
					{
						printf_s("Want to enter another repairing product?\n1-Yes\n2-No\n");
						int choice;
						choice = Int_Enter();
						if (choice == 1)
						{
							mas = resize2(mas, num_structs, num_structs + 1);
							num_structs++;
							Show_Struct_One_Field(mas[num_structs - 1], chart1);
						}
						else if (choice == 2)
						{
							break;
						}
					}
					size += num_structs;
					return mas;
				}
				else if (n == 3)
				{
					printf_s("Choose predetermined characteristic\n");
					printf_s("Please enter:\n");
					printf_s("1 - name\n");
					printf_s("2 - make\n");
					printf_s("3 - date\n");
					printf_s("4 - condition\n");

					int charact = 0;
					charact = Int_Enter();

					std::string name = "&", make = "&", date = "&";
					int condition = -1;

					while (1)
					{
						if (charact == 1)
						{
							printf_s("Enter name\n");
							name = String_Enter();
							break;
						}
						else if (charact == 2)
						{
							printf_s("Enter make\n");
							make = String_Enter();
							break;
						}
						else if (charact == 3)
						{
							printf_s("Enter date\n");
							date = Int_Enter();
							break;
						}
						else if (charact == 4)
						{
							printf_s("Enter condition\n");
							condition = Int_Enter();
							break;
						}

						else
						{
							printf_s("Try again\n");
						}
					}

					Repair* mas = new Repair[1];
					printf_s("Enter products until predetermined characteristic\n");

					//Input
					int num_structs = 0;
					Show_Struct_One_Field(mas[num_structs], chart1);

					for (num_structs = 1; !(Characteristic_check(mas[num_structs - 1], charact, name, make, date, condition)); num_structs++)
					{
						mas = resize2(mas, num_structs, num_structs + 1);
						Show_Struct_One_Field(mas[num_structs], chart1);
					}
					size += num_structs;
					return mas;
				}
				else
				{
					printf_s("No such variant\nTry again\n");
				}
			}
		}
		else
			if (j == 2)
			{
				int n;
				printf_s("Choose type of input\n1-Enter preparied number of structs\n2-Dialog with user\n3-Enter until don't face predetermined struct\n");
				printf_s("-----------------------------------------------------------------------------------\n");

				while (1)
				{
					n = 0;
					n = Int_Enter();
					if (n == 1)
					{
						int k = 0;
						printf_s("Number of products\n");
						k = Int_Enter();

						Repair* mas = new Repair[k];
						//Input
						for (int i = 0; i < k; i++)
						{
							Enter_Struct(mas[i]);
						}
						size += k;
						return mas;
					}
					else if (n == 2)
					{

						Repair* mas = new Repair[1];

						//Input
						int num_structs = 0;
						for (;;)
						{
							printf_s("Want to enter another product?\n1-Yes\n2-No\n");
							int choice;
							choice = Int_Enter();
							if (choice == 1)
							{
								mas = resize2(mas, num_structs, num_structs + 1);
								num_structs++;
								Enter_Struct(mas[num_structs - 1]);
							}
							else if (choice == 2)
							{
								break;
							}
						}

						size += num_structs;
						return mas;
					}
					else if (n == 3)
					{
						printf_s("Choose predetermined characteristic\n");
						printf_s("Please enter:\n");
						printf_s("1 - name\n");
						printf_s("2 - make\n");
						printf_s("3 - date\n");
						printf_s("4 - condition\n");

						int charact = 0;
						charact = Int_Enter();

						std::string name = "&", make = "&", date = "&";
						int condition = -1;

						while (1)
						{
							charact = Int_Enter();
							std::cin.clear();

							if (charact == 1)
							{
								printf_s("Enter name\n");
								name = String_Enter();
								break;
							}
							else if (charact == 2)
							{
								printf_s("Enter make\n");
								make = String_Enter();
								break;
							}
							else if (charact == 3)
							{
								printf_s("Enter date\n");
								date = Int_Enter();
								break;
							}
							else if (charact == 4)
							{
								printf_s("Enter condition\n");
								condition = Int_Enter();
								break;
							}

							else
							{
								printf_s("Try again\n");
							}
						}

						Repair* mas = new Repair[1];
						printf_s("Enter products until predetermined characteristic\n");

						//Input
						int num_structs = 0;
						Enter_Struct(mas[num_structs]);

						for (num_structs = 1; !(Characteristic_check(mas[num_structs - 1], charact, name, make, date, condition)); num_structs++)
						{
							mas = resize2(mas, num_structs, num_structs + 1);
							Enter_Struct(mas[num_structs]);
						}
						size += num_structs;
						return mas;
					}
					else
					{
						printf_s("No such variant\nTry again\n");
					}
				}
			}
			else
			{
				printf_s("No such variant\nTry again\n");
			}
	}
}

Repair* Add_Struct(Repair* mas, int& size)
{

	int Previous_size = size;
	Repair* mas2 = Create_Repair(size);
	mas = resize(mas, Previous_size, size);
	for (int i = Previous_size; i < size; i++)
	{
		mas[i] = mas2[i - Previous_size];
	}
	delete[] mas2;
	return mas;
}

void Delete_Struct(Repair* mas, int index, int& size)
{
	printf_s("You deleted player\n");
	Show_Struct(mas[index]);

	Repair* buffer = new Repair[size - 1];

	for (int i = index + 1; i < size; i++)
	{
		mas[i - 1] = mas[i];
	}
	size--;
}

void Change_Struct(Repair& mas)
{
	Show_Struct(mas);
	printf_s("What you want change?\n");
	printf_s("1 - name\n");
	printf_s("2 - make\n");
	printf_s("3 - date\n");
	printf_s("4 - condition\n");

	int k = 0;
	while (1)
	{
		k = Int_Enter();
		if (k == 1)
		{
			printf_s("Enter name\n");
			mas.Name = String_Enter();
			break;
		}
		else if (k == 2)
		{
			printf_s("Enter make\n");
			mas.Make = String_Enter();
			break;
		}
		else if (k == 3)
		{
			printf_s("Enter date\n");
			mas.Date = String_Enter();
			break;
		}
		else if (k == 4)
		{
			printf_s("Enter condition\n");
			mas.Condition = Int_Enter();
			break;
		}

		else
		{
			printf_s("Try again\n");
		}
	}
}

int Find_Struct(Repair* mas, bool show, int& size)
{
	printf_s("Choose characteristic in what we will seek product\n");
	printf_s("1 - name\n");
	printf_s("2 - make\n");
	printf_s("3 - date\n");
	printf_s("4 - condition\n");

	std::string name = "&", make = "&", date = "&";
	int condition = -1;
	int charact = 0;
	while (1)
	{
		charact = Int_Enter();
		std::cin.clear();

		if (charact == 1)
		{
			printf_s("Enter name\n");
			name = String_Enter();
			break;
		}
		else if (charact == 2)
		{
			printf_s("Enter make\n");
			make = String_Enter();
			break;
		}
		else if (charact == 3)
		{
			printf_s("Enter date\n");
			date = String_Enter();
			break;
		}
		else if (charact == 4)
		{
			printf_s("Enter condition\n");
			condition = Int_Enter();
			break;
		}

		else
		{
			printf_s("Try again\n");
		}

	}
	int i = 0;
	int flag_int = -1;
	bool flag = false;
	for (i = 0; i < size; i++)
	{
		if (Characteristic_check(mas[i], charact, name, make, date, condition))
		{
			if (!flag)
			{
				flag_int = i;
			}

			flag = true;

			if (show)
			{
				Show_Struct(mas[i]);
			}
		}
	}

	if (!flag)
	{
		printf_s("No such player :(\n");
	}
	return flag_int;
}