#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, len;
	int cnt = 0;
	char arr[51];
	bool check;

	cin >> n;
	
	while (n != 0)
	{
		cin >> arr;
		len = strlen(arr);
		
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == '(')
			{
				check = false;
				cnt++;
			}
			else
			{
				if (arr[i - 1] == '(')
				{
					check = true;
					cnt--;
				}
				else if (cnt > 0)
				{
					check = true;
					cnt--;
				}
				else
					check = false;
			}
		}
		if (cnt > 0)
			check = false;
		
		if (check == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		cnt = 0;
		n--;
	}

	return 0;
}