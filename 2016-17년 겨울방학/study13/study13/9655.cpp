#include <iostream>
using namespace std;

int main()
{
	int n; int sum = 0;

	cin >> n;

	sum = n / 3;
	sum += n % 3;

	if (sum % 2 == 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;

	return 0;
}