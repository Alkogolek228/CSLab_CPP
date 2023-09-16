#include <utility>
#include "pch.h"
#include <limits.h>
#include "Header.h"
#include <iostream>

extern "C" __declspec(dllexport) int Enter()
{
    int x;
    while (scanf_s("%d", &x) != 1 || x < INT_MIN || x > INT_MAX || getchar() != '\n')    //проверка на ввод и ввод числа инт
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

extern "C" __declspec(dllexport) void Reference2()
{
    std::cout << "Меня зовут Данила Альховик и я выполнил задание №2\n";
    std::cout << "Суть задания: создать массив и преназначить его элементы согласно рекурсивной функции\n";
}

extern "C" __declspec(dllexport) double* Create_din_array(int size)
{
    std::cout << "Введите элементы массив\n";
    double* mas = new double[size];

    for (int i = 0; i < size; i++)
    {
        std::cin >> mas[i];
    }
    return mas;
}

extern "C" __declspec(dllexport) void Print_din_array(double mas[], int size)
{
    std::cout << "Вы ввели массив:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << " ";
    }
}

extern "C" __declspec(dllexport) double Rec(double* arr, int first, int last)
{
    if (first == last)
    {
        return arr[first] * arr[first] + std::cos(arr[first]);
    }

    int mid = (last - first) / 2 + first;

    return Rec(arr, first, mid) * Rec(arr, mid + 1, last);
}

extern "C" __declspec(dllexport) int NonStop()
{
    int a;
    std::cout << "\nПовторить?\n1. Да\n2. Нет\n\n";
    while (scanf_s("%d", &a) != 1 || a < INT_MIN || a > INT_MAX || getchar() != '\n')    //проверка на ввод и ввод числа инт
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


