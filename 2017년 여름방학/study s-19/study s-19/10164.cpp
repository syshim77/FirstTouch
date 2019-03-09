#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	int cnt[16][16] = {};
	int arr[16][16] = {};

	cin >> n >> m >> k;

	int kn = 0;
	int km = 0;

	cnt[1][1] = 1;

	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1)
					continue;

				cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
			}
		}

		cout << cnt[n][m] << '\n';
	}

	else
	{
		int index = 1;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				arr[i][j] = index;

				if (index == k)
				{
					kn = i;
					km = j;
				}

				index++;
			}
		}

		for (int i = 1; i <= kn; i++)
		{
			for (int j = 1; j <= km; j++)
			{
				if (i == 1 && j == 1)
					continue;

				cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
			}
		}

		int cnt1 = cnt[kn][km];

		cnt[kn][km] = 1;

		for (int i = kn; i <= n; i++)
		{
			for (int j = km; j <= m; j++)
			{
				if (i == kn && j == km)
					continue;

				cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
			}
		}

		int cnt2 = cnt[n][m];

		cout << cnt1*cnt2 << '\n';
	}

	return 0;
}