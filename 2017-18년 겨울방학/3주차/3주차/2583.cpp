#include <iostream>
#include <algorithm>
using namespace std;

bool visit[100][100];			// �湮 ����
int res[101];					// ������ ����
int row, col, cnt, num;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= row || y >= col || visit[x][y] != 0)	// ������ ����ų� �湮������
		return 0;

	visit[x][y] = 1;
	int value = 1;
	for (int i = 0; i < 4; i++)
		value += dfs(x + dx[i], y + dy[i]);	// �����¿� ��ġ���� DFS, �������� ������ value���� 1 ����
	
	return value;
}

int main() {
	cin >> row >> col >> cnt;

	for (int i = 0; i < cnt; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;	// ���� �Ʒ�: (a, b) ������ ��: (c, d)
		for (int j = b; j < d; j++)
			for (int k = a; k < c; k++)
				visit[j][k] = 1;
	}

	int p = 0;	// �и��� ������ ����
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			int ans = dfs(i, j);
			if (ans > 0)
				res[p++] = ans;
		}

	cout << p << '\n';

	sort(res, res + p);

	for (int i = 0; i < p; i++)
		cout << res[i] << " ";
	cout << '\n';

	return 0;
}