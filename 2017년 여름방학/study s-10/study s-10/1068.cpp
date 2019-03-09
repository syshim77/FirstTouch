#include <iostream>
#include <queue>
using namespace std;

int n, root;
int tree[55][55];
int visit[55];
int remov;
int res = 0;
queue<int> q;

void BFS()
{
	bool check = false;
	int cnt = 0;
	q.push(root);
	visit[root] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (tree[cur][i] && !visit[i])
			{
				q.push(i);
				visit[i] = 1;
				cnt++;
			}
		}

		if (!cnt)
			res++;

		if (cur == remov)
		{
			check = true;

			if (cnt > 0)
				res -= cnt;
			else
				res--;
		}
	}

	if (check && !res)
		res++;
}

int main()
{
	int val;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val;

		if (val == -1)
		{
			root = i;
			continue;
		}

		tree[val][i] = 1;
		tree[i][val] = 1;
	}

	cin >> remov;

	BFS();

	if (remov == root)
		cout << "0" << '\n';
	else
		cout << res << '\n';

	return 0;
}