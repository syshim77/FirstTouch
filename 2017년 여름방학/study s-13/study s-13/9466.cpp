#include <iostream>
using namespace std;

#define siz 100005

int selected[siz] = {};
int check[siz] = {};
int team[siz] = {};
int cnt = 0;

void DFS(int num)
{
	check[num] = 1;
	
	int num2 = selected[num];

	if (check[num2])
	{
		if (!team[num2])
		{
			cnt++;

			for (int i = num2; i != num; i = selected[i])
				cnt++;
		}
	}
	else
		DFS(num2);

	team[num] = 1;
}

void init()
{
	cnt = 0;
	
	for (int i = 0; i < siz; i++)
	{
		selected[i] = 0;
		check[i] = 0;
		team[i] = 0;
	}
}

int main()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		init();

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
			cin >> selected[i];

		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
				DFS(i);
		}

		cout << n - cnt << '\n';
	}


	return 0;
}