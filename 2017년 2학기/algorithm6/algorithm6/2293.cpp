#include <iostream>
using namespace std;

int coin, cost;
int value[10005];
int dp[10005];

void DP() {
	for (int i = 0; i < coin; i++) {
		for (int j = 1; j <= cost; j++) {
			if (j - value[i] >= 0)
				dp[j] += dp[j - value[i]];
		}
	}
}

int main() {
	cin >> coin >> cost;

	for (int i = 0; i < coin; i++)
		cin >> value[i];

	dp[0] = 1;

	DP();

	cout << dp[cost] << '\n';

	return 0;
}