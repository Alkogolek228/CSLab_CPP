#include "pch.h"
#include <iostream>

TEST(TestCaseName, TestName)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

void destructor_x2(long double** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
}

int solve1(long double* mas[], int* size1, int* size2)
{
    long double sum = 0, k = 0, counter = 0;

    for (int i = 0; i < *size1; i++)
    {
        for (int j = 0; j < *size2; j++)
        {
            if (mas[i][j] == 0)
            {
                counter++;
            }
        }
    }

    return counter;

}

long double** create_din_matrix(int size1, int size2)
{
    long double** mas = new long double* [size1];
    for (int i = 0; i < size1; i++)
    {
        mas[i] = new long double[size2];
    }

    return mas;
}

TEST(test_counter1)
{
    int size1 = 2, size2 = 2;
    long double** mas = create_din_matrix(size1, size2);

    mas[0][0] = 0;
    mas[0][1] = 1;
    mas[1][0] = 2;
    mas[1][1] = 3;

    ASSERT_EQ(solve1(mas, &size1, &size2), 1);

    destructor_x2(mas, size1);
}

TEST(test_counter2)
{
    int size1 = 2, size2 = 2;
    long double** mas = create_din_matrix(size1, size2);

    mas[0][0] = 0;
    mas[0][1] = 0;
    mas[1][0] = 0;
    mas[1][1] = 0;


    ASSERT_TRUE(solve1(mas, &size1, &size2) == 4);

    destructor_x2(mas, size1);
}

TEST(test_counter3)
{
    int size1 = 2, size2 = 2;
    long double** mas = create_din_matrix(size1, size2);

    mas[0][0] = 1;
    mas[0][1] = 0;
    mas[1][0] = 3;
    mas[1][1] = 0;

    if (solve1(mas, &size1, &size2) != 2)
        FAIL();

    destructor_x2(mas, size1);
}
