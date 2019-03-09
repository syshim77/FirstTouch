#include <iostream>
using namespace std;

int main()
{
	int mor, nig, h, day;
	int cnt = 1;

	cin >> mor >> nig >> h;

	day = mor;

	while (1)
	{
		if (day >= h)
		{
			cout << cnt;
			break;
		}
		
		day -= nig;
		day += mor;
		cnt++;
	}
	
	return 0;
}