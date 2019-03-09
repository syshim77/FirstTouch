#include <iostream>
using namespace std;

int main()
{
	int n, cluster, disc;
	int *file;

	cin >> n;
	file = new int[n];

	for (int i = 0; i < n; i++)
		cin >> file[i];
	cin >> cluster;

	disc = 0;
	for (int i = 0; i < n; i++)
	{
		if (file[i] <= cluster)
			disc += cluster;
		else
		{
			disc += (file[i] / cluster + 1)*cluster;
		}
	}

	cout << disc;

	return 0;
}