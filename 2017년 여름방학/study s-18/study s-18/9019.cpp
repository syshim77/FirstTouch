#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int n1, n2, t;

	cin >> t;
	while (t--)
	{
		int visit[10000] = {};
		queue<pair<int, string>> q;

		cin >> n1 >> n2;
		q.push(make_pair(n1, ""));
		visit[n1] = 1;

		while (!q.empty())
		{
			int n = q.front().first;
			string s = q.front().second;
			q.pop();

			if (n == n2)
			{
				cout << s << '\n';
				break;
			}

			// D老锭
			int dn = (2 * n) % 10000;
			string ds = s;
			if (!visit[dn])
			{
				visit[dn] = 1;
				ds.append("D");
				q.push(make_pair(dn, ds));
			}

			// S老锭
			int sn;
			string ss = s;
			if ((sn = n - 1) < 0)
				sn = 9999;
			if (!visit[sn])
			{
				visit[sn] = 1;
				ss.append("S");
				q.push(make_pair(sn, ss));
			}

			// L老锭
			int ln1 = n / 1000;
			int ln = (n % 1000) * 10 + ln1;
			string ls = s;
			if (!visit[ln])
			{
				visit[ln] = 1;
				ls.append("L");
				q.push(make_pair(ln, ls));
			}

			// R老锭
			int rn4 = n % 10;
			int rn = (rn4 * 1000) + (n / 10);
			string rs = s;
			if (!visit[rn])
			{
				visit[rn] = 1;
				rs.append("R");
				q.push(make_pair(rn, rs));
			}
		}
	}

	return 0;
}