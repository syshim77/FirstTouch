#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int time[1000];
	int min[1000] = { 0 };
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> time[i];
	}

	sort(time, time + n);

	min[0] = time[0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			min[i] = min[j] + time[i];
		}
		sum += min[i];
	}

	cout << sum << endl;

	return 0;
}