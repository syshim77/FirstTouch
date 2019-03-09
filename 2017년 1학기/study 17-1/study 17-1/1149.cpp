#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int p[1000][3] = { 0 };
	int price[3] = { 0 };
	int n;

	cin >> n;
	cin >> p[0][0] >> p[0][1] >> p[0][2];

	for (int i = 1; i < n; i++) 
	{
		cin >> price[0] >> price[1] >> price[2];

		p[i][0] = min(p[i - 1][1], p[i - 1][2]) + price[0];
		p[i][1] = min(p[i - 1][0], p[i - 1][2]) + price[1];
		p[i][2] = min(p[i - 1][0], p[i - 1][1]) + price[2];
	}

	cout << min(min(p[n - 1][0], p[n - 1][1]), p[n - 1][2]);

	return 0;
}