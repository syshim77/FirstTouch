#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt = 1;
	int k = 1;

	cin >> n;

	for (int i = 2; i < n; i++) {
		cnt += k;
		k++;
	}
	cnt++;

	cout << cnt % 10007;

	return 0;
}