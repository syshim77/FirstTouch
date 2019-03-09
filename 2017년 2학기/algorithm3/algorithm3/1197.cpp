#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[10005];
bool check;

typedef struct krus
{
	int st;
	int en;
	int n;
}ks;

vector<ks> g;

bool comp(ks a, ks b)
{
	return a.n < b.n;
}

int find(int v)
{
	if (v == parent[v])
		return v;

	return parent[v] = find(parent[v]);
}

void merge(int u, int v)
{
	check = false;
	u = find(u);
	v = find(v);

	if (v == u)
		return;

	parent[u] = v;
	check = true;
}

int main()
{
	int node, line;
	int sum = 0;
	ks k;
	
	cin >> node >> line;

	for (int i = 1; i <= node; i++) 
		parent[i] = i;

	for (int i = 0; i < line; i++)
	{
		cin >> k.st >> k.en >> k.n;
		g.push_back(k);
	}

	sort(g.begin(), g.end(), comp);

	for (int i = 0; i < line; i++)
	{
		merge(g[i].st, g[i].en);

		if (check)
			sum += g[i].n;
	}

	cout << sum << '\n';

	return 0;
}