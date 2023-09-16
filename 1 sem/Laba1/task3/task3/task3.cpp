#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double b1, q, s;
    cin >> b1;
    q = 1.0 / 1001.0;
    s = b1 / (1 - q);
    cout << setprecision(8) << s;
    return 0;
}