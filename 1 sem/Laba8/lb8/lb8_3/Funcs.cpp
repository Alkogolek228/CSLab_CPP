#include "Funcs.h"

bool Check_Tovar(Company tovar1, Company tovar2, int index)
{
	switch (index)
	{
	case 1:
	{
		if (Array_check(tovar1.Name, tovar2.Name))
		{
			return true;

		}
		break;
	}
	
	default:
	{

		return false;
	}
	}
	return false;
}

bool Array_check(char a[], char b[])
{
	bool ans = true;
	for (int i = 0; i < 60; i++)
	{
		if (a[i] != b[i])
		{
			ans = false;
			break;
		}
		if (a[i] == '\0' && b[i] == '\0')
		{
			break;
		}
	}
	return ans;
}

void Sort(Company* arr, int length)
{
	int d = length / 2;

	while (d >= 1)
	{
		for (int i = d; i < length; i++)
		{
			int j = i;
			while ((j >= d) && (arr[j - d].tovar.Ammount > arr[j].tovar.Ammount))
			{
				std::swap(arr[j], arr[j - d]);
				j = j - d;
			}
		}
		d /= 2;
	}
}