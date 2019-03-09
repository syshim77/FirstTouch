#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int r, c;
	int cnt = 0;

	cin >> r >> c;

	if (r == 1)
		cnt = 1;
	else if (r == 2)
	{
		if (c < 7)
			cnt = (c + 1) / 2;
		else
			cnt = 4;
	}
	else
	{
		if (c < 4)
			cnt = c;
		else if (c >= 4 && c <= 6)
			cnt = 4;
		else
			cnt = c - 2;
	}

	/*if (r == 1)
		cnt = 1;
	else if (r == 2)
		cnt = min(4, (c + 1) / 2);
	else
	{
		if (c < 7)
			cnt = min(c, 4);
		else
			cnt = c - 2;
	}*/

	cout << cnt << '\n';

	return 0;
}