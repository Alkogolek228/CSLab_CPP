#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double a, v0, t, s;
    cin >> a >> t >> v0;
    s = v0 * t + (a * t * t / 2.);
    cout << setprecision(20) << s;
    return 0;
}