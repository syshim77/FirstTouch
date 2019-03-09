#include <iostream>
using namespace std;

int main()
{
	int testcase;
	int n;
	int point[10000];
	int cnt = 0;

	cin >> testcase;
	
	for (int i = 0; i < testcase; i++)
	{
		cin >> n;
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> point[j];
		}

		for (int j = 0; j < n; j++)
		{
			cnt++;
			if (point[j] == n)
				break;
			if (cnt == n)
				cnt = 0;
		}

		cout << cnt << endl;
	}

	return 0;
}