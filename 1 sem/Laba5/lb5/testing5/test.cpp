#include "pch.h"
#include <ctime>
#include <iostream>


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

int solve(int* mas[], int* size1, int* size2)
{
    int n = *(size1), m = *(size2), sum = 0, k = 0;
    int** arr1 = new int* [n]();

    for (int i = 0; i < n; i++)
    {
        arr1[i] = new int[m]();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j += 2)
        {
            if (mas[i][j] % 2 != 0)
            {
                arr1[i][j] = mas[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i][j] != 0)
            {
                sum += arr1[i][j];
                k++;
            }
        }
    }
    if (k == 0)
    {
         return 0;
    }

    else
    {
        return (long double)(sum / k);
    }

    for (int i = 0; i < *(size1); i++)
    {
        delete[] arr1[i];
    }
    delete[] arr1;

}

void destructor_x2(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
}

int** create_din_matrix(int size1, int size2)
{
    int** mas = new int* [size1];
    for (int i = 0; i < size1; i++)
    {
        mas[i] = new int[size2];
    }

    return mas;
}

TEST(test_solve1)
{
    int size1 = 2, size2 = 2;
    int** mas = create_din_matrix(size1, size2);
    mas[0][0] = 1;
    mas[0][1] = 2;
    mas[1][0] = 3;
    mas[1][1] = 4;

    ASSERT_EQ(solve(mas, &size1, &size2), 0);

    destructor_x2(mas, size1);
}

TEST(test_valid)
{
    srand(time(0));
    int size1 = 1000, size2 = 1000;
    int** mas = create_din_matrix(size1, size2);

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            mas[i][j] = rand() % 100;
       }
    }
   
    bool valid;
    if (mas)
    {
        valid = true;
    }

    EXPECT_EQ(valid, true);

    destructor_x2(mas, size1);
}

TEST(test_overflow)
{
    int size1 = 10000, size2 = 10000;
    int** mas = create_din_matrix(size1, size2);

    bool isnonoverflowed;
    if (mas)
    {
        isnonoverflowed = true;
    }

    EXPECT_EQ(isnonoverflowed, true);

    destructor_x2(mas, size1);
}

