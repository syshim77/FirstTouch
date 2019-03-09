#include <iostream>
#include <queue>
using namespace std;

int inputmap[100][100];
int map[100][100];
int bridge[100][100];
int n;
int islandcnt;
int mn = 10000;
queue<pair<int, int> > que;

void init()
{
	while (!que.empty())
		que.pop();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			bridge[i][j] = 0;
	}
}

void dfs(int y, int x, int cnt)
{
	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };
	int nexty, nextx;

	while (!que.empty())
		que.pop();

	que.push(make_pair(y, x));
	map[y][x] = cnt;

	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			nexty = y + dy[i];
			nextx = x + dx[i];

			if (nexty < n && nexty >= 0 && nextx < n && nextx >= 0)
			{
				if (inputmap[nexty][nextx] && !map[nexty][nextx])
				{
					que.push(make_pair(nexty, nextx));
					map[nexty][nextx] = cnt;
				}
			}
		}
	}
}

void bfs(int num)
{
	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };
	int nexty, nextx;

	init();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == num)
			{
				for (int k = 0; k < 4; k++)
				{
					nexty = i + dy[k];
					nextx = j + dx[k];

					if (nexty < n && nexty >= 0 && nextx < n && nextx >= 0)
					{
						if (!map[nexty][nextx])
						{
							bridge[nexty][nextx] = 1;
							que.push(make_pair(nexty, nextx));
						}
					}
				}
			}
		}
	}

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int k = 0; k < 4; k++)
		{
			nexty = y + dy[k];
			nextx = x + dx[k];

			if (nexty < n && nexty >= 0 && nextx < n && nextx >= 0)
			{
				if (map[nexty][nextx] && map[nexty][nextx] != num)
				{
					if (bridge[y][x] < mn)
						mn = bridge[y][x];
					return;
				}

				if (!map[nexty][nextx] && !bridge[nexty][nextx])
				{
					bridge[nexty][nextx] = bridge[y][x] + 1;
					que.push(make_pair(nexty, nextx));
				}
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> inputmap[i][j];
	}

	islandcnt = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (inputmap[i][j] && !map[i][j])
				dfs(i, j, islandcnt++);
		}
	}

	for (int i = 1; i < islandcnt; i++)
		bfs(i);

	cout << mn << '\n';

	return 0;
}