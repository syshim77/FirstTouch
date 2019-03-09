#include <iostream>
using namespace std;

int main()
{
	int n, r;
	int cnt = 1;

	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		cnt += 6*i;
		if (cnt >= n)
		{
			r = i + 1;
			break;
		}
	}

	cout << r << endl;

	return 0;
}