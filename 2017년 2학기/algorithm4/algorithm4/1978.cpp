#include <iostream>
using namespace std;

int n, cnt;
int num[101];
bool pri[1001];

void era()
{
	pri[1] = true;

	for (int i = 2; i*i <= 1000; i++)
	{
		if (!pri[i])
		{
			for (int j = i*i; j <= 1000; j += i)
				pri[j] = true;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	era();

	for (int i = 0; i < n; i++)
	{
		if (!pri[num[i]])
			cnt++;
	}

	cout << cnt << '\n';
		
	return 0;
}