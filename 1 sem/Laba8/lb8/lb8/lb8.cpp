#include "Func.h"

std::regex toDate{ R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20)\d\d)" };

int main()
{
    setlocale(LC_CTYPE, "Russian");
    system("color 0A");
    int count = 1;
    while (count)
    {
        printf("\n\n\n\n\n\n\t\t\t------------------------Добро пожаловать!------------------------\n");
        printf("\t\tВас приветствует система учета товаров версия 0.1. Нажмите любую клавишу чтобы продолжить...\n");
        _getch();
        system("cls");

        printf("Введите количество видов товаров\n");
        int n = Enter();
        Tovar* structmas = new Tovar[n];

        menu(structmas, n);

        count = NonStop();
    }
    return 0;
}