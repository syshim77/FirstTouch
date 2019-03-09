#include <iostream>
#include <queue>
using namespace std;

int c, r, cnt;
int tomato[1001][1001];
int visited[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void BFS()
{
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (tomato[nx][ny] == -1)
				continue;

			if (nx >= 0 && nx < r && ny >= 0 && ny < c && visited[nx][ny] == 0 && tomato[nx][ny] == 0)
			{
				visited[nx][ny] = visited[cx][cy] + 1;
				tomato[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

bool rip()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (tomato[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	cin >> c >> r;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	if (rip())
	{
		cout << "0" << '\n';
		return 0;
	}

	BFS();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (cnt < visited[i][j])
				cnt = visited[i][j];

			if (tomato[i][j] == 0)
			{
				cout << "-1" << '\n';
				return 0;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}