#include <iostream>
using namespace std;

int n;
int num[105] = {};
int visit[105] = {};

int DFS(int start, int cur, int count) 
{
	if (visit[cur])
		return 0;

	visit[cur] = 1;

	if (start == cur) 
	{
		for (int i = 1; i <= n; i++) 
		{
			if (visit[i] == 1) 
				visit[i] = 2;
		}

		return count + 1;
	}

	return DFS(start, num[cur], count + 1);
}

int main() {

	int cnt = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (visit[j] == 1) 
				visit[j] = 0;
		}

		cnt += DFS(i, num[i], 0);
	}

	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 2)
			cout << i << '\n';
	}

	return 0;
}