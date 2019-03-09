#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[1001][1001];	// 인접행렬
int degree[1001];		// 간선 정보
int n;					// n: 정점 수
vector<int> order;		// 오일러 회로 경로

void dfs(int v) {	// 갈 수 있는데까지 가고 마지막 정점을 vector에 추가
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

bool exist() {	// 오일러 회로 경로를 출력할 수 있는지 없는지 판단하는 함수
	for (int i = 1; i <= n; i++)
		degree[i] /= 2;
	for (int i = 1; i <= n; i++)
		if (degree[i] % 2)	// degree가 짝수인지 홀수인지 판별
			return false;	// 하나라도 홀수이면 오일러 회로가 존재하지 않음
	return true;			// 전부 짝수이면 오일러 회로가 존재함
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
	
	dfs(1);	// 첫번째 노드부터 DFS 진행
	reverse(order.begin(), order.end());	// 경로의 마지막 노드부터 vector에 추가하였으므로 역순으로 바꾸어줌

	for (int i = 0; i < order.size(); i++)
		cout << order[i] << " ";
	cout << '\n';
	return;
}

int main() {
	solve();
	return 0;
}