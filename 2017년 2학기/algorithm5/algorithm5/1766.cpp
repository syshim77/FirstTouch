#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int indegree[32005];
int order[32005];
vector<vector<int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int ques, info;

int main() {
	cin >> ques >> info;
	v.resize(ques + 1);

	for (int i = 0; i < info; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= ques; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.top();
		q.pop();

		int len = v[cur].size();
		for (int i = 0; i < len; i++) {
			indegree[v[cur][i]]--;

			if (indegree[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}

		order[cnt] = cur;
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		cout << order[i] << " ";
	}
	cout << '\n';

	return 0;
}