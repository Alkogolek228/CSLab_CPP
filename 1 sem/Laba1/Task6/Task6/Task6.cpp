#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x, b, p, e, n, y, z, m, h, d, k, A, D, S, K, B, C, Q, Y, N, P, T;
	int option;
	cin >> option;
	switch (option)
	{
	case 1:

		cout << "Enter x" << endl;
		cin >> x;
		cout << "Enter D" << endl;
		cin >> D;
		b = x + D;
		A = D * x / b;
		S = (pow(A, 2) + b * cos(x)) / (pow(D, 3) + (A + D - b));
		cout << S << endl;
		break;

	case 2:

		cout << "Enter e, p, x, K, D, C..  " << endl;
		cin >> e >> p >> x >> K >> D >> C;
		A = x + sin(p);
		B = pow(e, K);
		Y = 1 + pow(K, 2) / (2 * A * B) - B + D * C;
		cout << Y << endl;
		break;

	case 3:

		cout << "Enter x, p, n, K, D, B, C.." << endl;
		cin >> x >> p >> n >> K >> D >> B >> C;
		N = B * C;
		B = cos(x);
		C = p - n;
		Q = pow(B, 2) / (K * D) + pow(N, 3);
		cout << Q << endl;
		break;

	case 4:

		cout << "Enter x, y, z, K, C, D.." << endl;
		cin >> x >> y >> z >> K >> C >> D;
		A = x - y;
		B = sqrt(z);
		T = cos(x) + pow(A, 2) / (K - C * D) - B;
		cout << T << endl;
		break;

	case 5:

		cout << "Enter n, m, x, K.." << endl;
		cin >> n >> m >> x >> K;
		A = fabs(n + m);
		D = tan(x);
		Y = 1.29 + K / A + pow(D, 2);
		cout << Y << endl;
		break;

	case 6:

		cout << "Enter x, y, C, A, K" << endl;
		cin >> x >> y >> C >> A >> K;
		A = x + y;
		D = fabs(C - A);
		S = 10.1 + A / C + D / pow(K, 2);
		cout << S << endl;
		break;

	case 7:

		cout << "Enter x, p, h, K, C, D.." << endl;
		cin >> x >> p >> h >> K >> C >> D;
		A = x - p;
		B = log(h);
		Y = 0.78 * B + pow(A, 3) / (K * C * D);
		cout << Y << endl;
		break;

	case 8:

		cout << "Enter x, e, d, C, K" << endl;
		cin >> x >> e >> d >> C >> K;
		A = log10(x);
		B = x + pow(e, d);
		Y = (A + B) - pow(C, 2) / K;
		cout << Y << endl;
		break;

	case 9:

		cout << "Enter x, z, p, K, C, D" << endl;
		cin >> x >> z >> p >> K >> C >> D;
		A = sin(x) - z;
		B = fabs(p - x);
		P = (A + B);
		Y = pow(P, 2) - K / (C * D);
		cout << Y << endl;
		break;

	case 10:

		cout << "Enter x, k, z, D, C" << endl;
		cin >> x >> k >> z >> D >> C;
		A = log(x) - k;
		B = sqrt(z);
		Y = pow(D, 2) + pow(C, 2) / (0.75 * A) + B;
		cout << Y << endl;
		break;

	}

	return 0;

}

