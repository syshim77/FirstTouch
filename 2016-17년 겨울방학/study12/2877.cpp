#include <iostream>
using namespace std;

int main()
{
	int k;

	cin >> k;

	if (k % 2 == 0)
	{
		for (int i = k / 2; i > 0; i--)
			cout << 7;
	}
	else
	{
		for (int i = k / 2 + 1; i > 0; i--)
			cout << 4;
	}

	return 0;
}