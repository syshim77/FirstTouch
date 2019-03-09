#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int stu, comp;
	int *indegree;
	int *order;
	queue<int> q;

	cin >> stu >> comp;

	indegree = new int[stu + 1];
	vector<vector<int>> v(stu + 1);

	for (int i = 0; i <= stu; i++)
		indegree[i] = 0;

	for (int i = 0; i < comp; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= stu; i++)
	{
		int len = v[i].size();
		for (int j = 0; j < len; j++)
			indegree[v[i][j]]++;
	}

	for (int i = 1; i <= stu; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	order = new int[stu];

	while (1)
	{
		if (q.empty())
			break;

		int cur = q.front();
		order[cnt] = cur;
		q.pop();

		int len = v[cur].size();
		for (int i = 0; i < len; i++)
		{
			indegree[v[cur][i]]--;

			if (indegree[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}

		cnt++;
	}

	for (int i = 0; i < cnt; i++)
		cout << order[i] << " ";
	cout << '\n';

	delete[] indegree;
	delete[] order;

	return 0;
}