#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int tri[500][500] = { 0 };
	int res[500] = { 0 };
	int n, sum;
	int k = 0;
	int cnt = 1;

	cin >> n >> tri[0][0];
	res[0] = tri[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= cnt; j++)
		{
			cin >> tri[i][j];
		}
		cnt++;

		if (cnt == n)
			break;
	}
	
	sum = res[0];
	for (int i = 1; i < n; i++)
	{
		if (tri[i][k] < tri[i][k + 1])
		{
			res[i] = tri[i][k + 1];
			k++;
		}
		else
			res[i] = tri[i][k];
		
		sum += res[i];
	}

	cout << sum;

	return 0;
}