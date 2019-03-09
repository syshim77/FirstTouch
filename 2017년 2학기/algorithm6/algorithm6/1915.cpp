#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int r, c, n;
	int map[105][105] = {};
	int max = 0;

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf_s("%1d", &n);

			if (i == 0 || j == 0)
				map[i][j] = n;
			else {
				if (n) {
					map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;

					if (map[i][j] > max)
						max = map[i][j];
				}
			}
		}
	}

	cout << max*max << '\n';

	return 0;
}