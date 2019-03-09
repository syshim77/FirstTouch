#include <iostream>
using namespace std;

int main()
{
	int month;
	int date = 1;
	int d[5];

	cin >> month >> date;

	/*
	1/1 mon
	8 15 22 29
	2/1 thr
	8 15 22
	3/1 sun
	8 15 22 29
	4/1 wed
	8 15 22 29
	5/1 fri
	8 15 22 29
	6/1 mon
	8 15 22 29
	7/1 wed
	8 15 22 29
	8/1 sat
	8 15 22 29
	9/1 tue
	8 15 22 29
	10/1 thr
	8 15 22 29
	11/1 sun
	8 15 22 29
	12/1 tue
	8 15 22 29
	*/
	
	d[0] = 1;
	for (int i = 1; i < 5; i++)
	{
		d[i] = date + (7 * i);
	}

	if (month == 1 || month == 6)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "MON" << endl;
			}
		}
	}

	if (month == 9 || month == 12)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "TUE" << endl;
			}
		}
	}

	if (month == 4 || month == 7)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "WED" << endl;
			}
		}
	}

	if (month == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			if (date == d[i])
			{
				cout << "THU" << endl;
			}
		}
	}

	if (month == 10)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "THU" << endl;
			}
		}
	}

	if (month == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "FRI" << endl;
			}
		}
	}

	if (month == 8)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "SAT" << endl;
			}
		}
	}

	if (month == 3 || month == 11)
	{
		for (int i = 0; i < 5; i++)
		{
			if (date == d[i])
			{
				cout << "SUN" << endl;
			}
		}
	}

	return 0;
}