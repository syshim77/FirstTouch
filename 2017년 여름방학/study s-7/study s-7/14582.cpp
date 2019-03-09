#include <iostream>
using namespace std;

int main()
{
	int w[10];
	int s[10];
	int sum_w, sum_s;
	bool check = false;

	for (int i = 0; i < 9; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < 9; i++)
	{
		cin >> s[i];
	}

	sum_w = w[0];
	sum_s = s[0];

	for (int i = 1; i <= 9; i++)
	{
		if (sum_w > sum_s) 
		{
			cout << "Yes" << '\n';
			check = true;
			break;
		}
		sum_w += w[i];
		sum_s += s[i];
	}

	if (!check)
		cout << "No" << '\n';

	return 0;
}