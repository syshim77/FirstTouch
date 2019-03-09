// 커플 만들기
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m, w;
	int men[1000];
	int women[1000];
	int dp[1000];

	cin >> m >> w;
	for (int i = 0; i < m; i++)
		cin >> men[i];
	for (int i = 0; i < w; i++)
		cin >> women[i];

	return 0;
}