#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int node, line, cnt;
int visited[1005];
vector<vector<int>> v;
stack<int> s;

void DFS(int n)
{
	bool check = false;
	visited[n] = 1;

	int i = 0;
	int len = v[n].size();
	for (i = 0; i < len; i++)
	{
		if (!visited[v[n][i]])
		{
			s.push(v[n][i]);
			DFS(v[n][i]);
		}
	}

	if (i == (len - 1))
	{
		s.pop();

		if (!s.empty())
		{
			i = s.top();
			DFS(i);
		}
	}
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
			s.push(i);
			DFS(i);
			cnt++;
		}
	}
	
	cout << cnt << '\n';

	return 0;
}