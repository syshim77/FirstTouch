#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	char table[1000][1000];
	int h, w, val;
	int ans = 1;

	cin >> h >> w;
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> table[i][j];

			if (table[i][j] == '\n')
				j--;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			val = sqrt(ans);

			while (i + val < h || j + val < w)
			{
				if (table[i][j] == table[i + val][j + val] &&
					table[i][j] == table[i + val][j] &&
					table[i][j] == table[i][j + val]) 
					ans = (val + 1) * (val + 1);

				val++;
			}
		}
	}

	cout << ans;

	return 0;
}