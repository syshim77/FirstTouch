#include <iostream>
#include <queue>
using namespace std;

int x[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int y[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int map[55][55];
int visited[55][55];
int w, h;

void BFS(int cx, int cy)
{
	queue<pair<int, int>> q;
	visited[cx][cy] = 1;
	q.push(make_pair(cx, cy));

	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int curx = nx + x[i];
			int cury = ny + y[i];

			if (curx >= 0 && curx < h && cury >= 0 && cury < w && !visited[curx][cury] && map[curx][cury])
			{
				visited[curx][cury] = 1;
				q.push(make_pair(curx, cury));
			}
		}
	}
}

int main()
{
	while (1)
	{
		int cnt = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < 55; i++)
		{
			for (int j = 0; j < 55; j++)
			{
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && map[i][j] == 1)
				{
					BFS(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}