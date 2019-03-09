#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int test, city, rule, num;
	
	cin >> test;

	while (test--)
	{
		int delay[1005] = {};
		int indegree[1005] = {};

		cin >> city >> rule;

		for (int i = 1; i <= city; i++)
			cin >> delay[i];

		vector<vector<int>> v(city + 1);
		for (int i = 0; i < rule; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		cin >> num;

		for (int i = 1; i <= city; i++)
		{
			int len = v[i].size();
			for (int j = 0; j < len; j++)
				indegree[v[i][j]]++;
		}

		queue<int> q;
		for (int i = 1; i <= city; i++)
		{
			if (!indegree[i])
				q.push(i);
		}

		int next[1005] = {};
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			int len = v[cur].size();
			for (int i = 0; i < len; i++)
			{
				next[v[cur][i]] = max(delay[cur] + next[cur], next[v[cur][i]]);
				
				indegree[v[cur][i]]--;

				if (!indegree[v[cur][i]])
					q.push(v[cur][i]);
			}	
		}
		cout << delay[num] + next[num] << '\n';
	}

	return 0;
}