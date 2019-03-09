#include <iostream>
using namespace std;

int main()
{
	int n;
	int card[1005];
	int len[1005];	// 원소 최대 개수 누적 저장 배열
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> card[i];

	for (int i = 0; i < n; i++)
	{
		len[i] = 1;	// 값을 1로 초기화
		for (int j = 0; j < i; j++)
		{
			// 증가수열이고 이전에 더 많은 원소 개수 있으면 1 증가
			if (card[j] < card[i] && len[i] <= len[j])
				len[i] = len[j] + 1;
		}
		if (max < len[i])	// max에 최대값 저장
			max = len[i];
	}

	cout << max << '\n';

	return 0;
}