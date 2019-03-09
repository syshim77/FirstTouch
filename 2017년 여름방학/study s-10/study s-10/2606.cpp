#include <iostream>
#include <queue>
using namespace std;

int comp, net;
int matrix[105][105];
int visit[105];
queue<int> q;
int cnt = 0;

void BFS()
{
	q.push(0);
	visit[0] = 1;

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < comp; i++)
		{
			if (matrix[cur][i] && !visit[i])
			{
				q.push(i);
				visit[i] = 1;
				cnt++;
			}
		}
	}
}

int main()
{
	int a, b;

	cin >> comp >> net;

	for (int i = 0; i < net; i++)
	{
		cin >> a >> b;

		matrix[a - 1][b - 1] = 1;
		matrix[b - 1][a - 1] = 1;
	}

	BFS();
	cout << cnt << '\n';

	return 0;
}