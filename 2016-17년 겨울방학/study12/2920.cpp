#include <iostream>
using namespace std;

int main()
{
	int n[8] = { 0 };
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		cin >> n[i];
		if (n[i - 1] < n[i])
			cnt++;
	}
	
	if (cnt == 8)
		cout << "ascending" << endl;
	else if (cnt == 1)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

	return 0;
}