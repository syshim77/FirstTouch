//꿍의 피보나치 수열
#include <iostream>
using namespace std;

int main()
{
	long long int koong[68] = { 0 };
	int testcase, n;

	cin >> testcase;

	koong[0] = 1;
	koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;
	
	for (int i = 4; i < 68; i++)
	{
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	}

	while (testcase != 0)
	{
		cin >> n;
		cout << koong[n] << endl;
		testcase--;
	}

	return 0;
}