#include <iostream>
using namespace std;

int main()
{
	int n, out;
	int a[5001];
	int i, j, k;

	cin >> n >> out;

	for (i = 0; i < n; i++)
		a[i] = i + 1;
		
	cout << "<";
	for (i = -1, j = n; j; j--)
	{
		i = (i + out) % j;
		if (j != 1)
			cout << a[i] << ", ";
		else 
			cout << a[i];
		for (k = i; k < j; k++)
			a[k] = a[k + 1];
		i--;
	}
	cout << ">";
	
	return 0;
}