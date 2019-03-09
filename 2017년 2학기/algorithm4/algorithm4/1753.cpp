#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 100000000

int main()
{
	int v, e, start;
	vector<vector<pair<int, int>>> vec;
	queue<pair<int, int>> q;
	int arr[20001] = {};

	cin >> v >> e >> start;
	vec.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= v; i++)
		arr[i] = INF;

	arr[start] = 0;
	q.push(make_pair(0, start));

	while (!q.empty())
	{
		int cur = q.front().second;
		q.pop();

		int len = vec[cur].size();
		for (int i = 0; i < len; i++)
		{
			if (vec[cur][i].second + arr[cur] < arr[vec[cur][i].first])
			{
				arr[vec[cur][i].first] = vec[cur][i].second + arr[cur];
				q.push(make_pair(arr[vec[cur][i].first], vec[cur][i].first));
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (arr[i] == INF)
			cout << "INF" << '\n';
		else
			cout << arr[i] << '\n';
	}
	

	return 0;
}