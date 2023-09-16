#include <iostream> 
#include <cmath> 
#include <iomanip> 
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    double x1, y1, x2, y2, x3, y3, a, b, c, h1, h2, h3, A, B, C, s1, s2, s3, p, P, m1, m2, m3, bis1, bis2, bis3, r, R, Sr, SR, Cr, CR;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (a >= b + c || b >= a + c || c >= a + b) {
        cout << "Такой треугольник невозможен";
        return 0;
    }
    cout << setprecision(5);
    cout << a << endl << b << endl << c << endl;
    P = a + b + c;
    p = P / 2;
    s1 = sqrt(p * (p - a) * (p - b) * (p - c));
    h1 = 2 * s1 / a;
    h2 = 2 * s1 / b;
    h3 = 2 * s1 / c;
    s2 = h1 * a / 2;
    cout << h1 << endl << h2 << endl << h3 << endl;
    m1 = sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2)) / 2;
    m2 = sqrt(2 * pow(a, 2) + 2 * pow(c, 2) - pow(b, 2)) / 2;
    m3 = sqrt(2 * pow(a, 2) + 2 * pow(b, 2) - pow(c, 2)) / 2;
    cout << m1 << endl << m2 << endl << m3 << endl;
    A = acos((a * a + b * b - c * c) / (2 * a * b));
    B = acos((c * c + b * b - a * a) / (2 * b * c));
    C = acos((a * a + c * c - b * b) / (2 * a * c));
    s3 = a * b / 2 * sin(A);
    bis1 = sqrt((b * c) * (b + c - a) * (a + b + c)) / (b + c);
    bis2 = sqrt((a * c) * (a + c - b) * (a + b + c)) / (a + c);
    bis3 = sqrt((a * b) * (a + b - c) * (a + b + c)) / (a + b);
    R = a * b * c / (4 * s1);
    r = s1 / p;
    Sr = 3.14159265 * r * r;
    SR = 3.14159265 * R * R;
    Cr = 2 * 3.14159265 * r;
    CR = 2 * 3.14159265 * R;
    cout << bis1 << endl << bis2 << endl << bis3 << endl;
    cout << C << " " << C * 180 / 3.14159265 << endl;
    cout << A << " " << A * 180 / 3.14159265 << endl;
    cout << B << " " << B * 180 / 3.14159265 << endl;
    cout << R << endl << r << endl << Cr << endl << Sr << endl << CR << endl << SR << endl;
    cout << "Square of triangle = " << s1 << " or " << s2 << " or " << s3 << endl << P;
    return 0;
}