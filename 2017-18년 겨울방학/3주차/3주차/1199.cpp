#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[1001][1001];	// �������
int degree[1001];		// ���� ����
int n;					// n: ���� ��
vector<int> order;		// ���Ϸ� ȸ�� ���

void dfs(int v) {	// �� �� �ִµ����� ���� ������ ������ vector�� �߰�
	for (int i = 1; i <= n; i++) {
		while (map[v][i] > 0) {
			map[v][i]--;
			map[i][v]--;
			dfs(i);
		}
	}
	order.push_back(v);
	return;
}

bool exist() {	// ���Ϸ� ȸ�� ��θ� ����� �� �ִ��� ������ �Ǵ��ϴ� �Լ�
	for (int i = 1; i <= n; i++)
		degree[i] /= 2;
	for (int i = 1; i <= n; i++)
		if (degree[i] % 2)	// degree�� ¦������ Ȧ������ �Ǻ�
			return false;	// �ϳ��� Ȧ���̸� ���Ϸ� ȸ�ΰ� �������� ����
	return true;			// ���� ¦���̸� ���Ϸ� ȸ�ΰ� ������
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			degree[i] += map[i][j];
			degree[j] += map[i][j];
		}

	if (!exist()) {
		cout << "-1" << '\n';
		return;
	}
	
	dfs(1);	// ù��° ������ DFS ����
	reverse(order.begin(), order.end());	// ����� ������ ������ vector�� �߰��Ͽ����Ƿ� �������� �ٲپ���

	for (int i = 0; i < order.size(); i++)
		cout << order[i] << " ";
	cout << '\n';
	return;
}

int main() {
	solve();
	return 0;
}