#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dan[30][30];
int visited[30][30];
int siz[700];

void BFS(int x, int y)
{
	visited[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	siz[cnt]++;

	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int cx = nx + dx[i];
			int cy = ny + dy[i];

			if (cx >= 0 && cx < n && cy >= 0 && cy < n && !visited[cx][cy] && dan[cx][cy] != 0)
			{
				q.push(make_pair(cx, cy));
				visited[cx][cy] = 1;
				siz[cnt]++;
			}
		}

		q.pop();
	}

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &dan[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dan[i][j] != 0 && !visited[i][j])
			{
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	sort(siz, siz + cnt);

	for (int i = 0; i < cnt; i++)
		cout << siz[i] << '\n';

	return 0;
}