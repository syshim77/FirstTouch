#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node, line, cnt;
int visited[1005];
vector<vector<int>> v;
queue<int> q;

void BFS()
{
	int cur = q.front();
	q.pop();
	visited[cur] = 1;

	int len = v[cur].size();
	for (int i = 0; i < len; i++)
	{
		if (!visited[v[cur][i]])
			q.push(v[cur][i]);
	}

	if (!q.empty())
		BFS();
}

int main()
{
	cin >> node >> line;

	v.resize(node + 1);

	for (int i = 0; i < line; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= node; i++)
	{
		if (!visited[i])
		{
			q.push(i);
			BFS();
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}