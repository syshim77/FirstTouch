#include <iostream>
#include <queue>
using namespace std;

int n, cntn, cnty;
char rgb[105][105];
int visited[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFSn(int x, int y)
{
	queue<pair<int, int>> q;
	visited[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && rgb[cx][cy] == rgb[nx][ny])
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
		q.pop();
	}
}

void BFSy(int x, int y)
{
	queue<pair<int, int>> q;
	visited[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
			{
				if (rgb[cx][cy] == 'B')
				{
					if (rgb[nx][ny] == 'B')
					{
						q.push(make_pair(nx, ny));
						visited[nx][ny] = 1;
					}
				}
				else
				{
					if (rgb[nx][ny] != 'B')
					{
						q.push(make_pair(nx, ny));
						visited[nx][ny] = 1;
					}
				}
			}
		}
		q.pop();
	}
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
	}
}

int main()
{
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf_s("%1c", &rgb[i][j]);
		cin.ignore();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				BFSn(i, j);
				cntn++;
			}
		}
	}

	init();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				BFSy(i, j);
				cnty++;
			}
		}
	}

	cout << cntn << " " << cnty << '\n';

	return 0;
}