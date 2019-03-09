#include <iostream>
using namespace std;

int main()
{
	int n;
	int cnt = 0;
	int range[246920] = { 0 };

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i = 2; i <= 2*n; i++)
			range[i] = i;

		for (int i = 2; i <= 2*n; i++)
		{
			if (range[i] == 0)
				continue;

			for (int j = i + i; j <= 2*n; j += i)
				range[j] = 0;
		}

		for (int i = n + 1; i <= 2*n; i++)
		{
			if (range[i] != 0)
				cnt++;
		}

		cout << cnt << endl;

		range[246920] = { 0 };
		cnt = 0;
	}

	return 0;
}