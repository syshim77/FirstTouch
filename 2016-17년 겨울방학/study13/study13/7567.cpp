#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char *dish;
	int h, len;

	dish = new char[51];
	cin >> dish;
	len = strlen(dish);
	h = 10;

	for (int i = 0; i < len - 1; i++)
	{
		if (dish[i] == dish[i + 1])
			h += 5;
		else
			h += 10;
	}

	cout << h;

	delete[] dish;
	return 0;
}