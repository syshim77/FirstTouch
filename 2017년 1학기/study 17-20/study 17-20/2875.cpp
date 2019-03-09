#include <iostream>
using namespace std;

int count(int n1, int n2)
{
	if (n1 / 2 < n2)
		return n1 / 2;
	else
		return n2;
}

int main()
{
	int w, m, k;
	int max = 0;

	cin >> w >> m >> k;

	for (int i = k; i >= 0; i--)
	{
		if (m + i - k == 0)
			break;
		if (w - i < 0)
			continue;

		if (max < count(w - i, m + i - k))
			max = count(w - i, m + i - k);
	}

	cout << max << '\n';

	return 0;
}