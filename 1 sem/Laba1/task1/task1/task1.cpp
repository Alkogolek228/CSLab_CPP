#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    long double a, h, t;
    cin >> h;
    a = 9.8;
    t = sqrt(2 * h / a);
    cout << setprecision(9) << t;
    return 0;
}