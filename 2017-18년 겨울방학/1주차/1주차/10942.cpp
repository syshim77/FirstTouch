#include <iostream>
#include <stdio.h>
using namespace std;

int dp[2001][2001];

int main(void) {

	int n;
	int room[2001] = {};

	std::ios_base::sync_with_stdio(false);

	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> room[i];

	int question;
	cin >> question;

	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
		dp[0][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			if (room[j] == room[j + i - 1] && dp[i - 2][j + 1] == 1)
				dp[i][j] = 1;
		}
	}
	while (question--) {
		int st, en;
		cin >> st >> en;
		printf("%d\n", dp[en - st + 1][st]);
	}

	return 0;
}