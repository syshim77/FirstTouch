// �Ӹ����(�տ��� �о �ڿ��� �о ���� ����)
#include <iostream>
using namespace std;

int main()
{
	int *arr;
	int n, m, s, e;
	int ps, pe;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;
	while (m != 0)
	{
		cin >> s >> e;
		ps = s; pe = e;
		if ((e - s) % 2 == 0)
		{
			while (ps != pe)
			{
				if (arr[ps - 1] != arr[pe - 1])
				{
					cout << "0" << endl;
					break;
				}
				ps++; pe--;
			}
			if (ps == s && pe == e)
			{
				if (arr[ps - 1] == arr[pe - 1])
					cout << "1" << endl;
			}
			else
				cout << "1" << endl;
		}
		else
		{
			while ((pe - ps) != 1)
			{
				if (arr[ps - 1] != arr[pe - 1])
				{
					cout << "0" << endl;
					break;
				}
				ps++; pe--;
			}
			if (ps == s && pe == e)
			{
				if (arr[ps - 1] == arr[pe - 1])
					cout << "1" << endl;
			}
			else
				cout << "1" << endl;
		}
		m--;
	}

	delete[] arr;
	return 0;
}