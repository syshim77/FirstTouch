#include <iostream>
using namespace std;

int main()
{
	int n;
	int card[1005];
	int len[1005];	// ���� �ִ� ���� ���� ���� �迭
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> card[i];

	for (int i = 0; i < n; i++)
	{
		len[i] = 1;	// ���� 1�� �ʱ�ȭ
		for (int j = 0; j < i; j++)
		{
			// ���������̰� ������ �� ���� ���� ���� ������ 1 ����
			if (card[j] < card[i] && len[i] <= len[j])
				len[i] = len[j] + 1;
		}
		if (max < len[i])	// max�� �ִ밪 ����
			max = len[i];
	}

	cout << max << '\n';

	return 0;
}