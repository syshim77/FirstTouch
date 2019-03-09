#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int nol, nos;
	int cnt = 0;
	string s;
	set<string> listen, see;

	cin >> nol >> nos;

	for (int i = 0; i < nol; i++)
	{
		cin >> s;
		listen.insert(s);
	}
	for (int i = 0; i < nos; i++)
	{
		cin >> s;
		if (listen.count(s))
		{
			see.insert(s);
			cnt++;
		}
	}

	cout << cnt << "\n";
	set<string>::iterator result;
	for (result = see.begin(); result != see.end(); ++result)
		cout << *result << "\n";

	return 0;
}