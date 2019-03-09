#include <iostream>
using namespace std;

int main()
{
	int s[3][2], x, y;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> s[i][j];
	}

	x = s[0][0];
	y = s[0][1];

	x = s[1][0] == x ? s[2][0] : (s[1][0] == s[2][0] ? x : s[1][0]);
	y = s[1][1] == y ? s[2][1] : (s[1][1] == s[2][1] ? y : s[1][1]);

	cout << x << " " << y;
}