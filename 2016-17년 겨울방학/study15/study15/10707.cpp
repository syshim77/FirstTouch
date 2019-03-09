#include <iostream>
using namespace std;

int main()
{
	int a, b1, b2, l, use;
	int cost_a, cost_b, res;

	cin >> a >> b1 >> l >> b2 >> use;

	cost_a = a*use;

	if (l >= use)
		cost_b = b1;
	else
		cost_b = b1 + (use - l)*b2;

	res = cost_a < cost_b ? cost_a : cost_b;
	cout << res << endl;

	return 0;
}