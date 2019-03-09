#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, len;
	char key[105][20];
	bool check = false;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		char reverse[20] = {};

		cin >> key[i];
		len = strlen(key[i]);

		for (int j = len - 1; j >= 0; j--)
		{
			reverse[cnt] = key[i][j];
			cnt++;
		}

		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k < strlen(key[j]); k++)
			{
				if (reverse[k] == key[j][k])
					check = true;
				else
				{
					check = false;
					break;
				}
			}
			if (check)
			{
				cout << strlen(key[j]) << " " << key[j][strlen(key[j]) / 2] << '\n';
				break;
			}
		}
	}

	return 0;
}