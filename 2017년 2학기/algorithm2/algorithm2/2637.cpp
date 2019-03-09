#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num, rel;
int indegree[105];
int cnt[105];
queue<int> q;

int main()
{
	cin >> num >> rel;
	
	vector<vector<pair<int, int>>> v(num + 1);

	for (int i = 0; i < rel; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}

	int c = 0;
	for (int i = 1; i <= num; i++)
	{
		if (v[i].size() == 0)
		{
			cnt[c++] = i;
		}
	}

	for (int i = 1; i <= num; i++)
	{
		int len = v[i].size();
		for (int j = 0; j < len; j++)
		{
			indegree[v[i][j].first]++;
		}
	}
	// q: 7 6 3 4 5 1 2
	for (int i = 1; i <= num; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (1)
	{
		if (q.empty())
			break;

		int cur = q.front();
		q.pop();

		int len = v[cur].size();
		for (int i = 0; i < len; i++)
		{
			indegree[v[cur][i].first]--;
		}

		for (int i = 1; i <= num; i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}

		int next = q.front();
		q.pop();

		int mul = 0;
		for (int i = 0; i < len; i++)
		{
			if (v[cur][i].first == next)
			{
				mul = v[cur][i].second;
			}
			else
				continue;
		}

		len = v[next].size();
		for (int i = 0; i < len; i++)
		{
			v[next][i].second *= mul;
		}
	}



	return 0;
}