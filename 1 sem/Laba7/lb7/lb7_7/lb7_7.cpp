#include <iostream>
#include <string>

bool check(std::string  A, long long k)
{
    long long rev_k = 0;
    std::string B;
    long long lenA = A.length();

    while (lenA > 0)
    {
        B = (char)(((A[lenA - 1] - 48) % 2) + 48) + B;
        rev_k++;
        for (long long i = 0; i < lenA - 1; i++)
        {
            A[i + 1] = A[i + 1] + ((A[i] - 48) % 2) * 10;
            A[i] = (A[i] - 48) / 2 + 48;
        }
        A[lenA - 1] = ((A[lenA - 1] - 48) / 2) + 48;
        while (A[0] == 48)
        {
            A.erase(0, 1);
        }
        lenA = A.length();
        if (rev_k == k)
        {
            return (B[0] == 48);
        }
    }
    return true;
}

std::string DoubleBin(std::string* A, long long a, std::string* B, long long b, long long k, long long BiNum, long long& NoA)
{
    std::string* nA = new std::string[1000];
    std::string* nB = new std::string[1000];

    long long na = 0, nb = 0;
    for (int i = 0; i < a; i++)
    {
        long long lA = A[i].length();
        if (check(A[i], k))
        {
            nA[na] = A[i];
            na++;
            if (k > lA)
            {
                A[i].insert(0, k - lA - 1, '0');
            }
            if (A[i] == "0" && k == 1)
            {
                nB[nb] = "1";

            }
            if (!(A[i] == "0" && k == 1))
            {
                nB[nb] = '1' + A[i];

            }
            NoA++;
            nb++;
            if (NoA == BiNum)
            {
                return nB[nb - 1];
            }
        }
    }
    for (int i = 0; i < b; i++)
    {
        if (k == 1)
        {
            break;
        }
        long long lB = B[i].length();
        if (check(B[i], k))
        {
            nA[na] = B[i];
            na++;
            if (B[i] == "0" && k == 1)
            {
                nB[nb] = "1";
            }
            else if (!(B[i] == "0" && k == 1))
            {
                nB[nb] = '1' + B[i];

            }
            nb++;
            NoA++;
            if (NoA == BiNum)
            {
                return nB[nb - 1];
            }
        }
    }
    return DoubleBin(nA, na, nB, nb, k + 1, BiNum, NoA);
}

int main() // O(n) + const
{
    long long NoA = 0;
    std::string* NumA = new std::string[1];
    NumA[0] = "0";
    std::string* NumB = new std::string[1];
    NumB[0] = "";
    long long BiNum;
    std::cin >> BiNum;
    std::cout << DoubleBin(NumA, 1, NumB, 1, 1, BiNum, NoA);
    return 0;
}
