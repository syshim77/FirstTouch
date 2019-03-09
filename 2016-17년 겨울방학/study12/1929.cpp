#include <iostream>
using namespace std;

int main()
{
	int min, max;
	int arr[1000000];

	cin >> min >> max;

	for (int i = 2; i <= max; i++)
		arr[i] = i;

	for (int i = 2; i <= max; i++)
	{
		if (arr[i] == 0)
			continue;

		for (int j = i + i; j <= max; j += i)
			arr[j] = 0;
	}

	for (int i = min; i <= max; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << endl;
	}

	return 0;
}