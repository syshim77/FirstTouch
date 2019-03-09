#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];

int binary(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (mid == 8388)
			return mid;
		else if (arr[mid] < 8388)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

int main()
{
	for (int i = 0; i < 100; i++)
		cin >> arr[i];

	sort(arr, arr + 100);

	cout << binary(0, 99) << '\n';

	return 0;
}