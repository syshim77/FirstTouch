#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int n;
int house[30][30] = {};
int visit[30][30] = {};
int dan[400] = {};
int cnt = 0;

void DFS(int x, int y)
{
	int dx[4] = { -1, 0, 1, 0 }; int dy[4] = { 0, 1, 0, -1 };
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i]; int cy = y + dy[i];

		if (cx < 0 || cx >= n || cy < 0 || cy >= n)
			continue;

		if (!visit[cx][cy] && house[cx][cy])
		{
			dan[cnt]++;
			DFS(cx, cy);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%1d", &house[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (house[i][j] && !visit[i][j])
			{
				dan[cnt]++;
				DFS(i, j);
				cnt++;
			}
		}
	}

	sort(dan, dan + cnt);
	
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << dan[i] << '\n';

	return 0;
}