#include <iostream>
using namespace std;

int main()
{
	int n, min, pr;
	int r[100];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> r[i];
	}

	for (int i = 1; i < n; i++)
	{
		min = r[i];
		pr = r[0];
		for (int j = r[i]; j > 1; j--)
		{
			if (pr % j == 0)
			{
				if (r[i] % j == 0)
				{
					pr /= j;
					r[i] /= j;
				}
			}
		}
		cout << pr << "/" << r[i] << endl;
	}

	return 0;
}