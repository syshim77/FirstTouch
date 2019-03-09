#include <iostream>
using namespace std;

int n, remov;
int parent[55];
int child[55];
int rem[55];

int del(int num)
{
	if (num == -1)
		return 0;
	if (rem[num] == 1)
		return 1;

	return rem[num] = del(parent[num]);
}

int lifcount(int remov)
{
	int cnt = 0;

	rem[remov] = 1;
	child[parent[remov]]--;

	for (int i = 0; i < n; i++)
	{
		if (child[i] == 0)
		{
			if (del(i) == 0)
				cnt++;
		}
	}

	return cnt;
}

int main()
{
	int val;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		parent[i] = val;

		if (val != -1)
			child[val]++;
	}

	cin >> remov;

	cout << lifcount(remov) << '\n';

	return 0;
}