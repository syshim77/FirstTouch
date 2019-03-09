#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <functional>
using namespace std;

#define INF 100000000

int n;
double loc[105][2];
double walk = 5.0;
double t = 2.0;
double shoot = 50.0;
double tim[105];

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	cin >> loc[0][0] >> loc[0][1] >> loc[1][0] >> loc[1][1];
	cin >> n;

	for (int i = 2; i < n + 2; i++) 
		cin >> loc[i][0] >> loc[i][1];

	vector<vector<pair<int, double>>> v(n + 2);

	v[0].push_back(make_pair(1, distance(loc[0][0], loc[0][1], loc[1][0], loc[1][1]) / walk));
	for (int i = 2; i < n + 2; i++) {
		v[0].push_back(make_pair(i, distance(loc[0][0], loc[0][1], loc[i][0], loc[i][1]) / walk));
		v[i].push_back(make_pair(1, t + fabs(distance(loc[1][0], loc[1][1], loc[i][0], loc[i][1]) - shoot) / walk));

		for (int j = 2; j < n + 2; j++) {
			v[i].push_back(make_pair(j, t + fabs(distance(loc[i][0], loc[i][1], loc[j][0], loc[j][1]) - shoot) / walk));
			v[j].push_back(make_pair(i, t + fabs(distance(loc[i][0], loc[i][1], loc[j][0], loc[j][1]) - shoot) / walk));
		}
	}

	for (int i = 0; i < n + 2; i++)
		tim[i] = INF;

	tim[0] = 0.0;

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;

	q.push(make_pair(0.0, 0));

	while (!q.empty()) {
		int cur_loc = q.top().second;
		q.pop();

		int len = v[cur_loc].size();
		for (int i = 0; i < len; i++) {
			if (tim[v[cur_loc][i].first] > tim[cur_loc] + v[cur_loc][i].second) {
				tim[v[cur_loc][i].first] = tim[cur_loc] + v[cur_loc][i].second;
				q.push(make_pair(tim[v[cur_loc][i].first], v[cur_loc][i].first));
			}
		}
	}

	cout << tim[1] << '\n';

	return 0;
}