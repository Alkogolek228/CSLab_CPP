#include "pch.h"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
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

int** initialize_matrix(int** mas, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            std::cin >> mas[i][j];
        }
    }
    return mas;
}

int* create_din_array(int size)
{
    int* mas = new int[size];

    return mas;
}

void destructor_x2(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] mas[i];
    }
    delete[] mas;
}


TEST(test_create_array)
{
    int size = 1000;
    int* mas = create_din_array(size);

    ASSERT_TRUE(mas);

    delete[] mas;
}

TEST(test_create_matrix)
{
    int size1 = 200, size2 = 200;
    int** mas = create_din_matrix(size1, size2);

    ASSERT_TRUE(mas);
    SUCCEED();

    destructor_x2(mas, size1);
}