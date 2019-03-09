#include <iostream>
using namespace std;

int main()
{
	int n;
	int x1, x2, y1, y2, r1, r2;
	int d, r, pr;

	cin >> n;

	while (n != 0)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d = x1*x1 + x2*x2 + y1*y1 + y2*y2 - 2*(x1*x2 + y1*y2);
		r = r1*r1 + 2 * r1*r2 + r2*r2;
		pr = r1*r1 - 2 * r1*r2 + r2*r2;

		if (x1 != x2 || y1 != y2)
		{
			if (d < r && d > pr)
				cout << "2" << '\n';
			else if (d == r)
				cout << "1" << '\n';
			else if (d == pr)
				cout << "1" << '\n';
			else if (d < pr)
				cout << "0" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1" << '\n';
		else
			cout << "0" << '\n';

		n--;
	}

	return 0;
}