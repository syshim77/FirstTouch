#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	int p, m, n, pp, pm, pn;
	int cnt_p = 0;
	int cnt_m = 0;
	int cnt_n = 0;

	cin >> a >> b >> c >> d;
	cin >> p >> m >> n;

	pp = p; pm = m; pn = n;
	pp /= (a + b);
	if (pp*(a + b) < p && p <= pp*(a + b) + a)
		cnt_p++;
	pm /= (a + b);
	if (pm*(a + b) < m && m <= pm*(a + b) + a)
		cnt_m++;
	pn /= (a + b);
	if (pn*(a + b) < n && n <= pn*(a + b) + a)
		cnt_n++;

	pp = p; pm = m; pn = n;
	pp /= (c + d);
	if (pp*(c + d) < p && p <= pp*(c + d) + c)
		cnt_p++;
	pm /= (c + d);
	if (pm*(c + d) < m && m <= pm*(c + d) + c)
		cnt_m++;
	pn /= (c + d);
	if (pn*(c + d) < n && n <= pn*(c + d) + c)
		cnt_n++;

	cout << cnt_p << endl;
	cout << cnt_m << endl;
	cout << cnt_n << endl;

	return 0;
}