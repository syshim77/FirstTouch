#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int rode, line, cnt;
char gender[1001];
int parent[1001];
int visited[1001];
vector<pair<int, pair<int, int>>> v;

int find(int n)
{
	if (n == parent[n])
		return n;

	return parent[n] = find(parent[n]);
}

void merge(int x, int y, int z)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	parent[x] = y;
	visited[x] = 1;
	visited[y] = 1;
	cnt += z;
}

int main()
{
	cin >> rode >> line;

	for (int i = 1; i <= rode; i++)
		cin >> gender[i];

	for (int i = 1; i <= rode; i++)
		parent[i] = i;

	for (int i = 0; i < line; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(v.begin(), v.end());

	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		int first = v[i].second.first;
		int second = v[i].second.second;
		int s = v[i].first;

		if (gender[first] != gender[second])
			merge(first, second, s);
	}

	bool check = false;
	for (int i = 1; i <= rode; i++)
	{
		if (visited[i] == 1)
			check = true;
		else
		{
			check = false;
			break;
		}
	}

	if (check)
		cout << cnt << '\n';
	else
		cout << "-1" << '\n';

	return 0;
}