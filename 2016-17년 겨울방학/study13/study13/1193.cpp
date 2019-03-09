#include <iostream>
using namespace std;

int main()
{
	int n;
	int u = 1; int d = 1; int i = 0; int t = 1;

	cin >> n;

	while (1)
	{
		if (t > n)
			break;
		i++;
		t += i;
	}
	
	t -= i;
	if (i % 2 == 0)
	{
		u += (n - t);
		d = i - (n - t);
		cout << u << "/" << d;
	}
	else
	{
		u = i - (n - t);
		d += (n - t);
		cout << u << "/" << d;
	}
	
	return 0;
}