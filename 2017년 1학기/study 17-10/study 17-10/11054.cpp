#include <iostream>
using namespace std;

int main()
{
	int n, maxarr;
	int dp[2][1001] = { 0 };
	int arr[1001] = { 0 };
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		maxarr = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (maxarr < dp[0][j])
					maxarr = dp[0][j];
			}
		}
		dp[0][i] = maxarr + 1;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		maxarr = 0;
		for (int j = n; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				if (maxarr < dp[1][j])
					maxarr = dp[1][j];
			}
		}
		if (dp[1][i] < maxarr + 1)
			dp[1][i] = maxarr + 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (max < dp[0][i] + dp[1][i])
			max = dp[0][i] + dp[1][i];
	}

	cout << max - 1;

	return 0;
}

// 구글에서 검색했어요... 죄송합니다...
// 이해는 다 했으니까 시험 끝나고 그동안 못 푼 문제들 풀어보면서
// 이것도 같이 다시 풀어볼게요...ㅎ 죄송합니다ㅠ