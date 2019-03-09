#include <iostream>
using namespace std;

int main()
{
	int sugar;
	int cnt = 0;

	cin >> sugar;

	cnt = sugar / 5;

	if ((sugar % 5) % 3 == 0)
		cnt += (sugar % 5) / 3;
	else
	{
		if (sugar % 3 == 0)
			cnt = sugar / 3;
		else
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	
	cout << cnt << endl;

	return 0;
}