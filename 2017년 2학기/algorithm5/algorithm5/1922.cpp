#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1005];
bool check;
int sum;

typedef struct k {
	int a;
	int b;
	int cost;
}kru;

vector<kru> v;

bool com(kru a, kru b)
{
	return a.cost < b.cost;
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

int main() {
	kru krus;
	int comp, line;

	cin >> comp >> line;

	for (int i = 0; i < line; i++) {
		cin >> krus.a >> krus.b >> krus.cost;
		v.push_back(krus);
	}

	for (int i = 1; i <= comp; i++)
		parent[i] = i;

	sort(v.begin(), v.end(), com);

	for (int i = 0; i < line; i++) {
		merge(v[i].a, v[i].b);

		if (check)
			sum += v[i].cost;
	}

	cout << sum << '\n';

	return 0;
}