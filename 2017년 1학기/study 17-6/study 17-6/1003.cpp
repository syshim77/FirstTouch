#include <iostream>
using namespace std;

int cnt_0 = 0;
int cnt_1 = 0;

int fibonacci(int n) 
{
	if (n == 0) 
		cnt_0++;

	else if (n == 1) 
		cnt_1++;

	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int testcase, n;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> n;
		fibonacci(n);
		cout << cnt_0 << " " << cnt_1 << endl;
		cnt_0 = 0; cnt_1 = 0;
	}
	
	return 0;
}