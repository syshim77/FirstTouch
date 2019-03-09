#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int num, know;
int rel[105][105];
int arrow[105];
int cnt[105];
int c = 0;
#define MAX 100000000

void inimax()
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
			rel[i][j] = (i == j) ? 0 : MAX;
	}
}

void floyd()
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			for (int k = 1; k <= num; k++)
				rel[j][k] = min(rel[j][k], rel[j][i] + rel[i][k]);
		}
	}
}

void repres(int arr[105], int len)
{
	int mini = arrow[arr[0]];
	cnt[c] = arr[0];

	for (int i = 1; i < len; i++)
	{
		if (mini > arrow[arr[i]])
		{
			mini = arrow[arr[i]];
			cnt[c] = arr[i];
		}
	}
	c++;
}

void group()
{
	queue<int> q;
	int visited[105] = {};

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			if (!visited[j] && rel[i][j] != MAX)
			{
				q.push(j);
				visited[j] = 1;
			}
		}

		if (!q.empty())
		{
			int arr[105] = {};
			int len = q.size();

			for (int i = 0; i < len; i++)
			{
				arr[i] = q.front();
				q.pop();
			}

			repres(arr, len);
		}
	}
}

void numofarrow()
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			if (rel[i][j] < MAX)
				arrow[i] = max(arrow[i], rel[i][j]);
		}
	}
}

void print()
{
	cout << c << '\n';
	for (int i = 0; i < c; i++)
		cout << cnt[i] << '\n';
}

int main()
{
	cin >> num >> know;

	inimax();

	for (int i = 1; i <= know; i++)
	{
		int a, b;
		cin >> a >> b;

		rel[a][b] = 1;
		rel[b][a] = 1;
	}

	floyd();
	numofarrow();
	group();

	sort(cnt, cnt + c);
	print();

	return 0;
}