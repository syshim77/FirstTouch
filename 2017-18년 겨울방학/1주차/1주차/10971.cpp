#include <iostream>
using namespace std;

int n;
int minimum = 100000000;
int cnt = 0;
int map[11][11];
int visit[11];

void dfs(int first, int a, int sum) {
	if (cnt == n && first == a) {
		if (minimum > sum)
			minimum = sum;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && map[a][i] != 0) {
			visit[i] = 1;
			sum += map[a][i];
			cnt += 1;
			dfs(first, i, sum);
			visit[i] = 0;
			sum -= map[a][i];
			cnt -= 1;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
		visit[i] = 0;
	}

	for (int i = 0; i < n; i++)
		dfs(i, i, 0);

	cout << minimum << '\n';

	return 0;
}