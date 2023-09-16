#include <iostream>

int** create_din_matrix(int size);
int** initialize_matrix1(int** mas, int size);
int** initialize_matrix2(int** mas, int size);
void print_matrixsum(int** mas, int size);
int NonStop();
int enter();
void reference1();

int main()
{
    setlocale(LC_ALL, "Russian");
    reference1();

    int count = 1;

    while (count)
    {
        int size;
        std::cout << "Введите размерность массива\n";
        size = enter();

        int** mas1 = create_din_matrix(size);
        int** mas2 = create_din_matrix(size);

        mas1 = initialize_matrix1(mas1, size);
        mas2 = initialize_matrix2(mas2, size);

        print_matrixsum(mas1, size);
        print_matrixsum(mas2, size);

        free(mas1);
        free(mas2);

        count = NonStop();
    }
}
