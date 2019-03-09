#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int node, line, n, cnt, cnt2;
int visit[1005];
int order[1005];
int order2[1005];
vector<vector<int>> vec;
queue<int> q;

void DFS(int v)
{
	visit[v] = 1;

	int len = vec[v].size();
	for (int i = 0; i < len; i++)
	{
		if (!visit[vec[v][i]])
		{
			order[cnt] = vec[v][i];
			visit[vec[v][i]] = 1;
			cnt++;
			DFS(vec[v][i]);
		}
	}
}

void init()
{
	for (int i = 1; i <= node; i++)
		visit[i] = 0;
}

void BFS()
{
	int cur = q.front();
	q.pop();
	visit[cur] = 1;
	
	int len = vec[cur].size();
	for (int i = 0; i < len; i++)
	{
		if (!visit[vec[cur][i]])
		{
			q.push(vec[cur][i]);
			visit[vec[cur][i]] = 1;
			order2[cnt2] = vec[cur][i];
			cnt2++;
		}
	}
}

int main()
{
	cin >> node >> line >> n;

	vec.resize(node + 1);
	for (int i = 0; i < line; i++)
	{
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	for (int i = 1; i <= node; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	order[cnt] = n;
	cnt++;
	DFS(n);

	for (int i = 0; i < cnt; i++)
		cout << order[i] << " ";
	cout << '\n';

	init();

	q.push(n);
	order2[cnt2] = n;
	cnt2++;
	while (!q.empty())
		BFS();

	for (int i = 0; i < cnt2; i++)
		cout << order2[i] << " ";
	cout << '\n';

	return 0;
}