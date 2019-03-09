#include <iostream>
using namespace std;

int n;
int route[105][105];
int dfs[105][105] = { 0 };
int visit[105] = { 0 };

void DFS(int lo)
{
	for (int i = 1; i <= n; i++)
	{
		if (route[lo][i] && !visit[i])
		{
			visit[i] = 1;
			DFS(i);
		}
	}
}

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> route[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			visit[j] = 0;

		DFS(i);

		for (int j = 1; j <= n; j++)
			dfs[i][j] = visit[j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << dfs[i][j] << " ";
		cout << "\n";
	}

	return 0;
}