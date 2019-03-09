#include <iostream>
using namespace std;

char area[105][105] = {};
int visit[105][105] = {};
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n;
int cnt = 0; int ncnt = 0;

void DFS(int x, int y)
{
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i]; int cy = y + dy[i];

		if (cx >= 0 && cx < n && cy >= 0 && cy < n)
		{
			if (area[x][y] == area[cx][cy] && !visit[cx][cy])
				DFS(cx, cy);
		}
	}
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;
	}
}

void GtoR()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (area[i][j] == 'G')
				area[i][j] = 'R';
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> area[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				DFS(i, j);
				cnt++;
			}
		}
	}

	init();
	GtoR();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				DFS(i, j);
				ncnt++;
			}
		}
	}

	cout << cnt << " " << ncnt << '\n';

	return 0;
}