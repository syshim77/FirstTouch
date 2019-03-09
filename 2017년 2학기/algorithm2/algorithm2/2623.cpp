#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int singer, PD;
int indegree[1005];
int ord[1005];
queue<int> q;

int main()
{
	cin >> singer >> PD;

	vector <vector <int>> v(singer + 1);

	for (int i = 0; i < PD; i++)
	{
		int n, a;
		cin >> n >> a;

		
		for (int j = 0; j < n - 1; j++)
		{
			int k;
			cin >> k;
			v[a].push_back(k);
			a = k;
		}
	}

	for (int i = 1; i <= singer; i++)
	{
		int len = v[i].size();
		for (int j = 0; j < len; j++)
		{
			indegree[v[i][j]]++;
		}
	}

	for (int i = 1; i <= singer; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	while (1)
	{
		if (q.empty())
			break;

		int cur = q.front();
		ord[cnt] = cur;
		q.pop();

		int len = v[cur].size();
		for (int i = 0; i < len; i++)
		{
			indegree[v[cur][i]]--;
			
			if (!indegree[v[cur][i]])
				q.push(v[cur][i]);
		}

		cnt++;
	}

	bool check = false;
	for (int i = 1; i <= singer; i++)
	{
		if (!indegree[i])
			continue;
		else
		{
			check = true;
			break;
		}
	}

	if (check)
	{
		cout << "0" << '\n';
	}
	else
	{
		for (int i = 0; i < singer; i++)
		{
			cout << ord[i] << '\n';
		}
	}

	return 0;
}