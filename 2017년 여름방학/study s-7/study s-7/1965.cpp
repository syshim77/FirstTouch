#include <iostream>
using namespace std;

int main()
{
	int n;
	int box[1000];
	int cnt[1000];
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> box[i];

	for (int i = 0; i < n; i++)
	{
		cnt[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (box[j] < box[i] && cnt[i] <= cnt[j])
				cnt[i] = cnt[j] + 1;
		}
		if (max < cnt[i])
			max = cnt[i];
	}

	cout << max << '\n';

	return 0;
}