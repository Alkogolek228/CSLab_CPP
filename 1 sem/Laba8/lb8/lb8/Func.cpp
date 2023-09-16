#include "Func.h"

int NonStop()
{
    int a;
    std::cout << "\nПовторить?\n1. Да\n2. Нет\n\n";
    while (scanf_s("%d", &a) != 1 || getchar() != '\n' || a != 1 && a != 2)     //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }

    if (a == 2)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

int Enter()
{
    int x;
    while (scanf_s("%d", &x) != 1 || x < 0 || x > INT_MAX || getchar() != '\n')    //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

int Enternum(int n)
{
    int x;
    while (scanf_s("%d", &x) != 1 || x < 0 || x > n || getchar() != '\n')    //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

float Enterf()
{
    float x;
    while (scanf_s("%f", &x) != 1 || x < 0 || x > INT_MAX || getchar() != '\n')    //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

Tovar* MinusTovar(Tovar* information, int& n)
{
    //удаляем неугодных и перезаписываем память
    if (n == 0)
    {
        printf_s("\nструктура пуста, удалять нечего.\n");
        return information;
    }

    printf_s("\nВведите номер который хотите убрать:");

    int ignore;

    while (!(scanf_s("%d", &ignore)) || ignore < 0 || ignore > n)
    {
        printf_s("\nЭрор, попробуйте снова, нельзя удалить из структуру то, чего нет\n");
        while (getchar() != '\n');
        {
            std::rewind(stdin);
            printf_s("\nВведите номер который хотите убрать:");
        }
    }

    Tovar* safe_tovar = new Tovar[n - 1];
    int save_from_error = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != ignore - 1 && i < n)
        {
            safe_tovar[i + save_from_error] = information[i];
        }
        else
        {
            save_from_error = -1;
        }

    }
    std::cin.ignore(32334, '\n');

    n--;
    information = new Tovar[n];

    for (int i = 0l; i < n; i++)
    {
        information[i] = safe_tovar[i];
    }

    return information;
}

void enterstruct(Tovar*& structmas, int n)
{
    for (int i = 0; i < n; i++)
    {
        system("cls");
        printf("Введите название товара\n");
        scanf("%s", &structmas[i].Name);
        printf("Введите производителя товара\n");
        scanf("%s", &structmas[i].Make);
        printf("Введите количество товара\n");
        structmas[i].Amount = Enter();
        printf("Введите цену товара\n");
        structmas[i].Price = Enterf();
        printf("Введите дату производства товара\n");
        scanf("%s", &structmas[i].Date);
        structmas[i].sum = structmas[i].Amount * structmas[i].Price;
    }
    printf_s("Товар добавлен--------------------\n\n");
    printf_s("Нажмите любую клавишу, чтобы продолжить\n");
    _getch();
    system("cls");
}

void showTovar(Tovar* structmas, int n)
{
    if (n == 0)
    {
        printf("Товаров нет\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf_s("Название товара: %s\n", structmas[i].Name);
            printf_s("Производитель товара: %s\n", structmas[i].Make);
            printf_s("Количество товара: %d\n", structmas[i].Amount);
            printf_s("Цена товара: %f\n", structmas[i].Price);
            printf_s("Дата производства товара: %s\n", structmas[i].Date);
            printf_s("Общая цена товара: %f\n", structmas[i].sum);
            printf_s("-------------------------------------------------------\n");
        }
    }

    printf_s("Нажмите любую клавишу, чтобы продолжить\n");
    _getch();
    system("cls");
}

void searchinmas(Tovar* structmas, int n)
{
    double userPrice = 100.134;
    for (int i = 0; i < n; i++)
    {
        if (structmas[i].Price > userPrice)
        {
            printf_s("Название товара: %s\n", structmas[i].Name);
            printf_s("Производитель товара: %s\n", structmas[i].Make);
            printf_s("Количество товара: %d\n", structmas[i].Amount);
            printf_s("Цена товара: %f\n", structmas[i].Price);
            printf_s("Дата производства товара: %s\n", structmas[i].Date);
            printf_s("Общая цена товара: %f\n", structmas[i].sum);
            printf_s("-------------------------------------------------------\n");
        }
    }
    printf_s("Нажмите любую клавишу, чтобы продолжить\n");
    _getch();
    system("cls");
}

Tovar* insertSort(Tovar* a, int size)
{
    int i, j;
    Tovar tmp;
    for (i = 1; i < size; ++i)
    {
        for (j = i; (j > 0) && (a[j].Amount > a[j - 1].Amount); --j)
        {
            tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
        }
    }
    return a;
}

void change(Tovar*& structmas, int n)
{
    printf_s("Введите номер структуры, который хотите изменить\n");
    int num = Enternum(n);
    system("cls");
    printf_s("Введите поле структуры, которое хотите изменить\n1 - название товара\n2 - производитель товара\n3 - количество товара\n4 - цена товара\n5 - дата поступления товара\n0 - в меню");

    for (;;)
    {
        switch (_getch())
        {

        case 48:
        {
            system("cls");
            printf("Возврат в меню\n");
            return;
        }

        case 49:
        {
            system("cls");
            printf("Введите название товара\n");
            scanf("%s", &structmas[num].Name);
            printf_s("Для выхода в меню нажмите 0\n");
            break;
        }

        case 50:
        {
            system("cls");
            printf("Введите производителя товара\n");
            scanf("%s", &structmas[num].Make);
            printf_s("Для выхода в меню нажмите 0\n");
            break;
        }

        case 51:
        {
            system("cls");
            printf("Введите количество товара\n");
            structmas[num].Amount = Enter();
            printf_s("Для выхода в меню нажмите 0\n");
            break;
        }

        case 52:
        {
            system("cls");
            printf("Введите цену товара\n");
            structmas[num].Price = Enterf();
            printf_s("Для выхода в меню нажмите 0\n");
            break;
        }

        case 53:
        {
            system("cls");
            printf("Введите дату поступления товара\n");
            scanf("%s", &structmas[num].Date);
            printf_s("Для выхода в меню нажмите 0\n");
            break;
        }

        default:
        {
            system("cls");
            printf("Такой команды нет, попробуйте еще раз!\n\n\n");
            break;
        }
        }
    }
}

void AddTovar(Tovar*& structmas, int& n)
{
    int add = Enter();

    Tovar* safe_tovar = new Tovar[n + add];
    for (int i = 0; i < n + add; i++)
    {
        if (i >= n)
        {
            system("cls");
            printf("Введите название товара\n");
            scanf("%s", &safe_tovar[i].Name);
            printf("Введите производителя товара\n");
            scanf("%s", &safe_tovar[i].Make);
            printf("Введите количество товара\n");
            safe_tovar[i].Amount = Enter();
            printf("Введите цену товара\n");
            safe_tovar[i].Price = Enterf();
            printf("Введите дату производства товара\n");
            scanf("%s", &safe_tovar[i].Date);
            safe_tovar[i].sum = safe_tovar[i].Amount * safe_tovar[i].Price;
        }
        else
            safe_tovar[i] = structmas[i];
    }
    n += add;
    structmas = safe_tovar;
}

void menu(Tovar* structmas, int n)
{
    bool flag = false;
    for (;;)
    {
        printf("1 - создать склад\n2 - добавить новый товар\n3 - удалить товары\n4 - показать товары\n5 - поиск товаров по стоимости выше 100.341 рублей\n6 - сортировать товары\n7 - изменить поле\n0 - выход\n");
        switch (_getch())
        {
        case 48:
        {
            system("cls");
            printf("Система завершает работу, всего хорошего!\n");
            return;
        }

        case 49:
        {
            system("cls");
            enterstruct(structmas, n);
            flag = true;
            break;
        }

        case 50:
        {
            if (!flag)
            {
                system("cls");
                printf_s("Сначала создайте склад!!!\n");
                break;
            }
            else
            {
                system("cls");
                printf_s("Введите сколько элементов структуры вы хотите добавить:");
                AddTovar(structmas, n);
                break;
            }
        }

        case 51:
        {
            if (!flag)
            {
                system("cls");
                printf_s("Сначала создайте склад!!!\n");
                break;
            }
            else
            {
                system("cls");
                MinusTovar(structmas, n);
                printf_s("Количество товаров изменено\n");
                break;
            }
        }

        case 52:
        {
            if (!flag)
            {
                system("cls");
                printf_s("Сначала создайте склад!!!\n");
                break;
            }
            else
            {
                system("cls");
                showTovar(structmas, n);
                break;
            }
        }
        case 53:
        {
            if (!flag)
            {
                system("cls");
                printf_s("Сначала создайте склад!!!\n");
                break;
            }
            else
            {
                system("cls");
                searchinmas(structmas, n);
                break;
            }
        }

        case 54:
        {
            if (!flag)
            {
                system("cls");
                printf_s("Сначала создайте склад!!!\n");
                break;
            }
            else
            {
                system("cls");
                structmas = insertSort(structmas, n);
                printf_s("Массив отсортирован\n");
                break;
            }
        }

        case 55:
        {
            if (!flag)
            {
                system("cls");
                printf_s("Сначала создайте склад!!!\n");
                break;
            }
            else
            {
                system("cls");
                change(structmas, n);
                break;
            }
        }

        default:
        {
            system("cls");
            printf("Такой команды нет, попробуйте еще раз!\n\n\n");
            break;
        }
        }
    }
}