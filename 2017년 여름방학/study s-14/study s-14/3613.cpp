#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char input[210];
	int barnum = 0; int bignum = 0;

	cin >> input;

	int len = strlen(input);

	for (int i = 0; i < len; i++)
	{
		if (input[i] == '_')
		{
			barnum++;
		}
		if (input[i] >= 65 && input[i] <= 90)
		{
			bignum++;
		}
	}

	if (barnum&&bignum)
	{
		cout << "Error!" << '\n';
		return 0;
	}
	
	// c++
	if (barnum&&!bignum)
	{
		if (input[0] == '_' || input[len - 1] == '_')
		{
			cout << "Error!" << '\n';
			return 0;
		}

		for (int i = 0; i < len; i++)
		{
			if (input[i] == '_'&&input[i + 1] == '_')
			{
				cout << "Error!" << '\n';
				return 0;
			}

			if (input[i] == '_')
			{
				input[i + 1] = toupper(input[i + 1]);

				for (int j = i; j < len; j++)
				{
					input[j] = input[j + 1];
				}
			}
		}
	}
	// java
	else if (!barnum&&bignum)
	{
		if (isupper(input[0]))
		{
			cout << "Error!" << '\n';
			return 0;
		}

		for (int i = 0; i < len; i++)
		{
			if (input[i] == ' ')
			{
				cout << "Error!" << '\n';
				return 0;
			}

			if (isupper(input[i]))
			{
				input[i] = tolower(input[i]);
				len++;

				for (int j = len; j > i; j--)
				{
					input[j] = input[j - 1];
				}
				input[i] = '_';
			}
		}
	}

	cout << input << '\n';

	return 0;
}