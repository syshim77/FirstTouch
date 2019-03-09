#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int n, quiz;
	string poketmon[1005];
	map<string, int> m;
	char question[1005][30];
	
	std::ios::sync_with_stdio(false);
	cin >> n >> quiz;

	for (int i = 1; i <= n; i++)
	{
		char one[30];

		std::ios::sync_with_stdio(false);
		cin >> one;

		poketmon[i] = one;
		m.insert(map<string, int>::value_type(poketmon[i], i));
	}
	
	for (int i = 1; i <= quiz; i++)
	{
		std::ios::sync_with_stdio(false);
		cin >> question[i];
	}

	for (int i = 1; i <= quiz; i++)
	{
		if (isdigit(question[i][0]))	// 숫자이면
		{
			std::ios::sync_with_stdio(false);
			cout << poketmon[stoi(question[i])] << '\n';
		}
		else	// 알파벳이면
		{
			std::ios::sync_with_stdio(false);
			cout << m[question[i]] << '\n';
		}
	}

	return 0;
}