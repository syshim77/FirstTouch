#include <iostream>
using namespace std;

int main()
{
	int n, pn;
	int cnt = 0;
	int range[123460] = { 0 };

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		pn = n + 1;
		for (int i = 2; i <= n + 1; i++)
		{
			range[i] = pn;
			pn++;
		}

		for (int i = 2; i <= n + 1; i++)
		{
			if (range[i] == 0)
				continue;

			for (int j = i + i; j <= n + 1; j += i)
				range[j] = 0;
		}

		for (int i = 2; i <= n + 1; i++)
		{
			if (range[i] != 0)
				cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}