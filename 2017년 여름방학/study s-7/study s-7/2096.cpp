#include <iostream>
#include <algorithm>
#include <cstring>	// visual에서는 안써도 컴파일 에러가 안뜨지만
					// 백준에서는 써야함(memcpy() 사용에 필요)
using namespace std;

int main()
{
	int premax[3] = { 0 }, premin[3] = { 0 };	// 이전 행까지 DP 계산한 배열
	int curmax[3], curmin[3];	// 현재 행에서 DP 계산하는 배열
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> curmax[j];
			curmin[j] = curmax[j];	// curmin에 입력한 수 넣음

			// 삼항연산자 : 조건이 참이면 앞에꺼, 거짓이면 뒤에꺼 반환
			curmax[j] += max(premax[1], (j == 1) ? max(premax[0], premax[2]) : premax[j]);
			curmin[j] += min(premin[1], (j == 1) ? min(premin[0], premin[2]) : premin[j]);
		}
		memcpy(premax, curmax, sizeof(int) * 3);	// premax에 curmax를 덮어씌움
		memcpy(premin, curmin, sizeof(int) * 3);	// premin에 curmin을 덮어씌움
	}
	sort(premax, premax + 3);
	sort(premin, premin + 3);	

	cout << premax[2] << " " << premin[0] << '\n';

	return 0;
}