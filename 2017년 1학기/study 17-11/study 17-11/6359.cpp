#include <iostream>
using namespace std;

int main()
{
	int n, testcase;
	int cnt = 0;
	int room[101];
	
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			room[j] = 0;
		}

		for (int j = 2; j <= n; j++)
		{
			for (int k = 1; k <= (n / j); k++)
			{
				if (room[j*k] == 0)
					room[j*k] = 1;
				else
					room[j*k] = 0;
			}
		}

		cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (room[j] == 0)
				cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}