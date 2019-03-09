#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int st[305];
	int dp[305];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> st[i];

	dp[0] = st[0];
	dp[1] = st[0] + st[1];
	dp[2] = max(dp[0] + st[2], st[1] + st[2]);
	
	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2] + st[i], dp[i - 3] + st[i - 1] + st[i]);

	cout << dp[n - 1];

	return 0;
}