#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int h, w, r;
	int candy[100][100];
	int res[100][100] = { 0 };

	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cin >> candy[i][j];
	}
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			r = 0;
			r = max(res[i - 1][j - 1], max(res[i - 1][j], res[i][j - 1]));
			res[i][j] = r + candy[i][j];
		}
	}

	cout << res[h - 1][w - 1];

	return 0;
}