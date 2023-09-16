#include "Func.h"

int NonStop()
{
    int a;
    std::cout << "\n���������?\n1. ��\n2. ���\n\n";
    while (scanf_s("%d", &a) != 1 || getchar() != '\n' || a != 1 && a != 2)     //�������� �� ���� � ���� ����� ���
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
    while (scanf_s("%d", &x) != 1 || x < 0 || x > INT_MAX || getchar() != '\n')    //�������� �� ���� � ���� ����� ���
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

int Enternum(int n)
{
    int x;
    while (scanf_s("%d", &x) != 1 || x < 0 || x > n || getchar() != '\n')    //�������� �� ���� � ���� ����� ���
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

float Enterf()
{
    float x;
    while (scanf_s("%f", &x) != 1 || x < 0 || x > INT_MAX || getchar() != '\n')    //�������� �� ���� � ���� ����� ���
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

Tovar* MinusTovar(Tovar* information, int& n)
{
    //������� ��������� � �������������� ������
    if (n == 0)
    {
        printf_s("\n��������� �����, ������� ������.\n");
        return information;
    }

    printf_s("\n������� ����� ������� ������ ������:");

    int ignore;

    while (!(scanf_s("%d", &ignore)) || ignore < 0 || ignore > n)
    {
        printf_s("\n����, ���������� �����, ������ ������� �� ��������� ��, ���� ���\n");
        while (getchar() != '\n');
        {
            std::rewind(stdin);
            printf_s("\n������� ����� ������� ������ ������:");
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
        printf("������� �������� ������\n");
        scanf("%s", &structmas[i].Name);
        printf("������� ������������� ������\n");
        scanf("%s", &structmas[i].Make);
        printf("������� ���������� ������\n");
        structmas[i].Amount = Enter();
        printf("������� ���� ������\n");
        structmas[i].Price = Enterf();
        printf("������� ���� ������������ ������\n");
        scanf("%s", &structmas[i].Date);
        structmas[i].sum = structmas[i].Amount * structmas[i].Price;
    }
    printf_s("����� ��������--------------------\n\n");
    printf_s("������� ����� �������, ����� ����������\n");
    _getch();
    system("cls");
}

void showTovar(Tovar* structmas, int n)
{
    if (n == 0)
    {
        printf("������� ���\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf_s("�������� ������: %s\n", structmas[i].Name);
            printf_s("������������� ������: %s\n", structmas[i].Make);
            printf_s("���������� ������: %d\n", structmas[i].Amount);
            printf_s("���� ������: %f\n", structmas[i].Price);
            printf_s("���� ������������ ������: %s\n", structmas[i].Date);
            printf_s("����� ���� ������: %f\n", structmas[i].sum);
            printf_s("-------------------------------------------------------\n");
        }
    }

    printf_s("������� ����� �������, ����� ����������\n");
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
            printf_s("�������� ������: %s\n", structmas[i].Name);
            printf_s("������������� ������: %s\n", structmas[i].Make);
            printf_s("���������� ������: %d\n", structmas[i].Amount);
            printf_s("���� ������: %f\n", structmas[i].Price);
            printf_s("���� ������������ ������: %s\n", structmas[i].Date);
            printf_s("����� ���� ������: %f\n", structmas[i].sum);
            printf_s("-------------------------------------------------------\n");
        }
    }
    printf_s("������� ����� �������, ����� ����������\n");
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
    printf_s("������� ����� ���������, ������� ������ ��������\n");
    int num = Enternum(n);
    system("cls");
    printf_s("������� ���� ���������, ������� ������ ��������\n1 - �������� ������\n2 - ������������� ������\n3 - ���������� ������\n4 - ���� ������\n5 - ���� ����������� ������\n0 - � ����");

    for (;;)
    {
        switch (_getch())
        {

        case 48:
        {
            system("cls");
            printf("������� � ����\n");
            return;
        }

        case 49:
        {
            system("cls");
            printf("������� �������� ������\n");
            scanf("%s", &structmas[num].Name);
            printf_s("��� ������ � ���� ������� 0\n");
            break;
        }

        case 50:
        {
            system("cls");
            printf("������� ������������� ������\n");
            scanf("%s", &structmas[num].Make);
            printf_s("��� ������ � ���� ������� 0\n");
            break;
        }

        case 51:
        {
            system("cls");
            printf("������� ���������� ������\n");
            structmas[num].Amount = Enter();
            printf_s("��� ������ � ���� ������� 0\n");
            break;
        }

        case 52:
        {
            system("cls");
            printf("������� ���� ������\n");
            structmas[num].Price = Enterf();
            printf_s("��� ������ � ���� ������� 0\n");
            break;
        }

        case 53:
        {
            system("cls");
            printf("������� ���� ����������� ������\n");
            scanf("%s", &structmas[num].Date);
            printf_s("��� ������ � ���� ������� 0\n");
            break;
        }

        default:
        {
            system("cls");
            printf("����� ������� ���, ���������� ��� ���!\n\n\n");
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
            printf("������� �������� ������\n");
            scanf("%s", &safe_tovar[i].Name);
            printf("������� ������������� ������\n");
            scanf("%s", &safe_tovar[i].Make);
            printf("������� ���������� ������\n");
            safe_tovar[i].Amount = Enter();
            printf("������� ���� ������\n");
            safe_tovar[i].Price = Enterf();
            printf("������� ���� ������������ ������\n");
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
        printf("1 - ������� �����\n2 - �������� ����� �����\n3 - ������� ������\n4 - �������� ������\n5 - ����� ������� �� ��������� ���� 100.341 ������\n6 - ����������� ������\n7 - �������� ����\n0 - �����\n");
        switch (_getch())
        {
        case 48:
        {
            system("cls");
            printf("������� ��������� ������, ����� ��������!\n");
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
                printf_s("������� �������� �����!!!\n");
                break;
            }
            else
            {
                system("cls");
                printf_s("������� ������� ��������� ��������� �� ������ ��������:");
                AddTovar(structmas, n);
                break;
            }
        }

        case 51:
        {
            if (!flag)
            {
                system("cls");
                printf_s("������� �������� �����!!!\n");
                break;
            }
            else
            {
                system("cls");
                MinusTovar(structmas, n);
                printf_s("���������� ������� ��������\n");
                break;
            }
        }

        case 52:
        {
            if (!flag)
            {
                system("cls");
                printf_s("������� �������� �����!!!\n");
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
                printf_s("������� �������� �����!!!\n");
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
                printf_s("������� �������� �����!!!\n");
                break;
            }
            else
            {
                system("cls");
                structmas = insertSort(structmas, n);
                printf_s("������ ������������\n");
                break;
            }
        }

        case 55:
        {
            if (!flag)
            {
                system("cls");
                printf_s("������� �������� �����!!!\n");
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
            printf("����� ������� ���, ���������� ��� ���!\n\n\n");
            break;
        }
        }
    }
}