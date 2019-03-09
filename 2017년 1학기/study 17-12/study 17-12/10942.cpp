// 팰린드롬(앞에서 읽어도 뒤에서 읽어도 같은 수열)
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
					return 0;
				}
				ps++; pe--;
			}
			return 1;
		}
		else
		{
			while ((pe - ps) != 1)
			{
				if (arr[ps - 1] != arr[pe - 1])
				{
					return 0;
				}
				ps++; pe--;
			}
			if (arr[ps - 1] == arr[pe - 1])
				return 1;
			else
				return 0;
		}
		m--;
	}

	delete[] arr;
}