#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rode, line, cnt, sum;
int parent[1000001];
vector<pair<int, pair<int, int>>> vec;

int find(int u)
{
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v, int n)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	parent[u] = v;
	sum += n;
	cnt++;
}

int main()
{
	cin >> rode >> line;

	for (int i = 1; i <= rode; i++)
		parent[i] = i;

	for (int i = 0; i < line; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back(make_pair(c, make_pair(a, b)));
	}
	
	sort(vec.begin(), vec.end());

	int len = vec.size();
	for (int i = 0; i < len; i++)
	{
		if (cnt == (rode - 2))
			break;

		int num = vec[i].first;
		int first = vec[i].second.first;
		int second = vec[i].second.second;
		merge(first, second, num);
	}

	cout << sum << '\n';

	return 0;
}