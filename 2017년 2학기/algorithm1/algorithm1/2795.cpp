#include <iostream>
#include <algorithm>
using namespace std;

int city, rode;
int route[105][105];

int floyd(int st, int en)
{
	int cnt = 0;
	// st->en���� ���� �ִܰ�ΰ� ��� ������ �������� �˾ƾ��ϴµ�
	// �װ� ��� �����ؾ����� �𸣰���...

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
			{
				route[j][k] = min(route[j][k], route[j][i] + route[i][k]);
			}
		}
	}

	return route[st][en];
}

void init_max()
{
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			if (i == j)
				route[i][j] = 0;
			else
				route[i][j] = 100000000;
		}
	}
}

int main()
{
	cin >> city >> rode;

	init_max();

	for (int i = 1; i <= rode; i++)
	{
		int a, b;
		cin >> a >> b;

		route[a][b] = 1;
	}

	cout << floyd(1, 2) << " " << floyd(2, 1) << '\n';

	return 0;
}