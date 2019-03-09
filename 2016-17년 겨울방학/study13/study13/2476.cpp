#include <iostream>
using namespace std;

int main()
{
	int n, max_n; int max = 0;
	int num[1000][3];
	int cost[1000];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> num[i][j];
	}
	
	for (int i = 0; i < n; i++)
	{
		if (num[i][0] == num[i][1] && num[i][1] == num[i][2])
			cost[i] = 10000 + num[i][0] * 1000;
		else if (num[i][0] != num[i][1] && num[i][1] != num[i][2] 
			&& num[i][0] != num[i][2])
		{
			max_n = num[i][0];
			if (num[i][1] > max_n)
				max_n = num[i][1];
			if (num[i][2] > max_n)
				max_n = num[i][2];
			cost[i] = max_n * 100;
		}
		else
		{
			if (num[i][0] == num[i][1] && num[i][1] != num[i][2])
				cost[i] = 1000 + num[i][0] * 100;
			else if (num[i][0] == num[i][2] && num[i][0] != num[i][1])
				cost[i] = 1000 + num[i][0] * 100;
			else
				cost[i] = 1000 + num[i][1] * 100;
		}
		if (cost[i] > max)
			max = cost[i];
	}

	cout << max;

	return 0;
}