#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n;
	string name, status;
	set<string> s;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> status;

		if (status == "enter")
			s.insert(name);
		else
			s.erase(name);
	}

	set<string>::reverse_iterator iter;
	for (iter = s.rbegin(); iter != s.rend(); ++iter)
		cout << *iter << '\n';

	return 0;
}