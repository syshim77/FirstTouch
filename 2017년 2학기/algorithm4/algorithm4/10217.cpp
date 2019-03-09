#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

typedef struct info
{
	int pos;
	int cur_c;
	int cur_t;
}in;

int main()
{
	std::ios::sync_with_stdio(false);

	int tc, airport, cost, ticket;

	cin >> tc;

	while (tc--)
	{
		cin >> airport >> cost >> ticket;

		vector<in> v[105];
		
		in inf;
		int com[105][1005] = {};

		for (int i = 0; i < ticket; i++)
		{
			int st;
			cin >> st >> inf.pos >> inf.cur_c >> inf.cur_t;
			v[st].push_back(inf);
		}

		for (int i = 1; i <= airport; i++)
		{
			for (int j = 0; j <= cost; j++)
				com[i][j] = -1;
		}

		queue<in> q;
		
		inf.pos = 1;
		inf.cur_c = 0;
		inf.cur_t = 0;
		q.push(inf);

		com[1][0] = 0;

		while (!q.empty())
		{
			in cur = q.front();
			q.pop();

			if (cur.cur_t > com[cur.pos][cur.cur_c] || cur.cur_c > cost)
				continue;

			int len = v[cur.pos].size();
			for (int i = 0; i < len; i++)
			{
				int vloc = v[cur.pos][i].pos;
				int vcost = v[cur.pos][i].cur_c;
				int vtime = v[cur.pos][i].cur_t;
				if ((com[vloc][vcost + cur.cur_c] == -1 || com[vloc][vcost + cur.cur_c] > cur.cur_t + vtime) && cur.cur_c + vcost <= cost)
				{
					com[vloc][vcost + cur.cur_c] = cur.cur_t + vtime;
					inf.pos = vloc;
					inf.cur_c = vcost + cur.cur_c;
					inf.cur_t = vtime + cur.cur_t;
					q.push(inf);
				}
			}
		}

		int m = INF;
		for (int i = 0; i <= cost; i++)
		{
			if (com[airport][i] != -1 && m > com[airport][i])
				m = com[airport][i];
		}

		if (m == INF)
			cout << "Poor KCM" << '\n';
		else
			cout << m << '\n';
	}

	return 0;
}