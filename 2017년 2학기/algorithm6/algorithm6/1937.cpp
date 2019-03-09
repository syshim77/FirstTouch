#include <iostream>
using namespace std;

int panda[505][505];
int visit[505][505];
int n, m;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };

void map(int cx, int cy) {
	int nx, ny;
	int val = 0;

	for (int i = 0; i < 4; i++) {
		nx = cx + x[i];
		ny = cy + y[i];

		if (nx >= n || nx < 0 || ny >= n || ny < 0)
			continue;

		if (panda[nx][ny] < panda[cx][cy]) {
			if (visit[nx][ny] == 0)
				map(nx, ny);

			if (val < visit[nx][ny])
				val = visit[nx][ny];
		}
	}
	visit[cx][cy] = val + 1;

	if (m < visit[cx][cy])
		m = visit[cx][cy];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> panda[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0)
				map(i, j);
		}
	}

	cout << m << '\n';

	return 0;
}