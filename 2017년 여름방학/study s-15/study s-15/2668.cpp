#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[105] = {};
int visit[105] = {};
int picked[105] = {};
int cnt = 0;

void DFS(int index)
{
	while (!visit[index])
	{
		cout << index << endl;
		int n = num[index];
		visit[index] = 1;
		index = n;
		cnt++;
	}

	int i = num[index];
	picked[cnt] = index;
	cnt++;

	while (i != index)
	{
		picked[cnt] = i;
		i = num[i];
		cnt++;
		//cout << i << endl;
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			DFS(i);
		}
	}

	sort(picked, picked + cnt);
	/*
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
	{
	cout << picked[i] << '\n';
	}
	*/

	return 0;
}