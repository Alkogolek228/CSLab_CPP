#include <iostream>
#include <Windows.h>

int main()
{
    HINSTANCE load;
    load = LoadLibrary(L"dinlib.dll");

    typedef void (*reference) ();
    reference Reference2 = (reference)GetProcAddress(load, "Reference2");

    typedef int (*enter) ();
    enter Enter;
    Enter = (enter)GetProcAddress(load, "Enter");

    typedef double* (*create_din_array) (int);
    create_din_array Create_din_array;
    Create_din_array = (create_din_array)GetProcAddress(load, "Create_din_array");

    typedef void (*print_din_array) (double*, int);
    print_din_array Print_din_array;
    Print_din_array = (print_din_array)GetProcAddress(load, "Print_din_array");

    typedef int (*rec) (double*, int, int);
    rec Rec;
    Rec = (rec)GetProcAddress(load, "Rec");

    typedef int (*nonstop) ();
    nonstop NonStop;
    NonStop = (nonstop)GetProcAddress(load, "NonStop");

    setlocale(LC_ALL, "Russian");

    Reference2();

    int count =  1;

    while(count)
    {
        int size;
        std::cout << "Введите размерность массива\n";
        size = Enter();

        double* mas = Create_din_array(size);
        Print_din_array(mas, size);

        std::cout << "\n" << Rec(mas, 0, size - 1);

        delete[] mas;

        count = NonStop();

        FreeLibrary(load);
    }
}
