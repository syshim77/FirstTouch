#include <iostream>
#include <algorithm>
#include <cstring>	// visual������ �Ƚᵵ ������ ������ �ȶ�����
					// ���ؿ����� �����(memcpy() ��뿡 �ʿ�)
using namespace std;

int main()
{
	int premax[3] = { 0 }, premin[3] = { 0 };	// ���� ����� DP ����� �迭
	int curmax[3], curmin[3];	// ���� �࿡�� DP ����ϴ� �迭
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> curmax[j];
			curmin[j] = curmax[j];	// curmin�� �Է��� �� ����

			// ���׿����� : ������ ���̸� �տ���, �����̸� �ڿ��� ��ȯ
			curmax[j] += max(premax[1], (j == 1) ? max(premax[0], premax[2]) : premax[j]);
			curmin[j] += min(premin[1], (j == 1) ? min(premin[0], premin[2]) : premin[j]);
		}
		memcpy(premax, curmax, sizeof(int) * 3);	// premax�� curmax�� �����
		memcpy(premin, curmin, sizeof(int) * 3);	// premin�� curmin�� �����
	}
	sort(premax, premax + 3);
	sort(premin, premin + 3);	

	cout << premax[2] << " " << premin[0] << '\n';

	return 0;
}