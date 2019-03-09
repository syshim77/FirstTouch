#include <iostream>
#include <string>
using namespace std;

int main()
{
	string l[5005];
	string s[5005];
	string result[5005];
	string temp;
	int nol, nos;
	int cnt = 0;

	cin >> nol >> nos;

	for (int i = 0; i <= nol; i++)
		getline(cin, l[i]);
	for (int i = 0; i < nos; i++)
		getline(cin, s[i]);

	for (int i = 0; i <= nol; i++)
	{
		for (int j = 0; j < nos; j++)
		{
			if (l[i].compare(s[j]) == 0)
			{
				result[cnt] = l[i];
				cnt++;
			}
		}
	}

	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = 0; j < cnt - 1; j++)
		{
			if (result[j].compare(result[j + 1]) > 0)
			{
				temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
		}
	}

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << result[i] << endl;

	return 0;
}