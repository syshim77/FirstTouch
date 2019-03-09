#include <iostream>
#include <queue>
using namespace std;

int r, c;
char lake[1505][1505] = {};
int visit[1505][1505] = {};
int water[1505][1505] = {};
int L[2][2], lcnt = 0;
int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, 1, -1, 0 };

// 배열 초기화
void init(int arr[1505][1505])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			arr[i][j] = 0;
	}
}

// 빙판이 녹는 시점 저장
int waterbfs() 
{
	int cnt = 1;
	int ret = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (lake[i][j] == '.' || lake[i][j] == 'L') 
			{
				visit[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int sz = q.size();

		for (int i = 0; i < sz; i++) 
		{
			int x = q.front().first;
			int	y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) 
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c || visit[nx][ny])
					continue;

				if (lake[nx][ny] != 'L') 
				{
					water[nx][ny] = cnt;
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		cnt++;
	}
	return cnt - 2;
}

// 0 ~ 빙판이 녹는 시점(최대) 구간에서 백조끼리 만나는지 확인
bool bfs(int limit) 
{
	queue<pair<int, int>> q;

	q.push(make_pair(L[0][0], L[0][1]));

	visit[L[0][0]][L[0][1]] = 1;

	while (!q.empty()) 
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == L[1][0] && y == L[1][1]) 
			return true;

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c || visit[nx][ny]) 
				continue;

			if (water[nx][ny] <= limit) 
			{
				q.push(make_pair(nx, ny));
				visit[nx][ny] = 1;
			}
		}
	}
	return false;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) 
	{
		for (int j = 0; j < c; j++) 
		{
			cin >> lake[i][j];

			if (lake[i][j] == 'L') 
			{
				L[lcnt][0] = i;
				L[lcnt++][1] = j;
			}
		}
	}

	int st = 0, en;

	en = waterbfs();

	while (st <= en) {
		init(visit);

		int mid = (st + en) / 2;

		if (bfs(mid)) 
			en = mid - 1;
		else 
			st = mid + 1;
	}

	cout << st << '\n';

	return 0;
}