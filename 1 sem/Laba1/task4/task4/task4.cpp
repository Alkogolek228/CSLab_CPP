#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a1, a100, sum;
    int diff;
    cin >> a1;
    cin >> a100;
    double n1 = 100;
    double n2 = 70;
    diff = (a100 - a1) / (n1 - 1);
    sum = ((2 * a1 + diff * (n2 - 1)) / 2 * n2);
    cout << setprecision(10);
    cout << diff << endl;
    cout << setprecision(10);
    cout << sum;
    return 0;
}