#include <iostream>
using namespace std;

char map[30][30];	// 블럭 입력
int n, m;	// 가로와 세로 크기
int dx, dy;	// 빈 곳의 위치
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };	// 상하좌우 위치(순서대로 위, 오른쪽, 아래, 왼쪽)

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '|') {	// | 모양이고 위나 아래가 빈칸이면 위치 변동
				if (map[i - 1][j] == '.') dy = i - 1, dx = j;
				if (map[i + 1][j] == '.') dy = i + 1, dx = j;
			}
			if (map[i][j] == '-') {	// - 모양이고 왼쪽이나 오른쪽이 빈칸이면 위치 변동
				if (map[i][j - 1] == '.') dy = i, dx = j - 1;
				if (map[i][j + 1] == '.') dy = i, dx = j + 1;
			}
			if (map[i][j] == '+') {	// + 모양이고 상하좌우중에 빈칸이 있으면 위치 변동
				if (map[i - 1][j] == '.') dy = i - 1, dx = j;
				if (map[i + 1][j] == '.') dy = i + 1, dx = j;
				if (map[i][j - 1] == '.') dy = i, dx = j - 1;
				if (map[i][j + 1] == '.') dy = i, dx = j + 1;
			}
			if (map[i][j] == '1') {	// 1번 모양이고 오른쪽이나 아래가 빈칸이면 위치 변동
				if (map[i][j + 1] == '.') dy = i, dx = j + 1;
				if (map[i + 1][j] == '.') dy = i + 1, dx = j;
			}
			if (map[i][j] == '2') {	// 2번 모양이고 위나 오른쪽이 빈칸이면 위치 변동
				if (map[i - 1][j] == '.') dy = i - 1, dx = j;
				if (map[i][j + 1] == '.') dy = i, dx = j + 1;
			}
			if (map[i][j] == '3') {	// 3번 모양이고 위나 왼쪽이 빈칸이면 위치 변동
				if (map[i - 1][j] == '.') dy = i - 1, dx = j;
				if (map[i][j - 1] == '.') dy = i, dx = j - 1;
			}
			if (map[i][j] == '4') {	// 4번 모양이고 아래나 왼쪽이 빈칸이면 위치 변동
				if (map[i + 1][j] == '.') dy = i + 1, dx = j;
				if (map[i][j - 1] == '.') dy = i, dx = j - 1;
			}
		}
	}

	int loc[4] = {};
	for (int i = 0; i < 4; i++) {
		int y = dy + dir[i][0], x = dx + dir[i][1];	// 빈칸 기준 상하좌우 위치
		if (y<0 || y >= n || x<0 || x >= m) continue;	// 범위를 벗어나면 패스
		// 빈칸 기준 위칸과 연결 가능하면 +1
		if (i == 0 && (map[y][x] == 'M' || map[y][x] == '|' || map[y][x] == '+' || map[y][x] == '1' || map[y][x] == '4')) loc[i]++;
		// 빈칸 기준 오른쪽 칸과 연결 가능하면 +1
		if (i == 1 && (map[y][x] == 'M' || map[y][x] == '-' || map[y][x] == '+' || map[y][x] == '3' || map[y][x] == '4')) loc[i]++;
		// 빈칸 기준 아래칸과 연결 가능하면 +1
		if (i == 2 && (map[y][x] == 'M' || map[y][x] == '|' || map[y][x] == '+' || map[y][x] == '2' || map[y][x] == '3')) loc[i]++;
		// 빈칸 기준 왼쪽 칸과 연결 가능하면 +1
		if (i == 3 && (map[y][x] == 'M' || map[y][x] == '-' || map[y][x] == '+' || map[y][x] == '1' || map[y][x] == '2')) loc[i]++;
	}

	cout << dy + 1 << " " << dx + 1 << " ";

	if (loc[0] == 1 && loc[1] == 0 && loc[2] == 1 && loc[3] == 0)	// 위아래가 있으면
		cout << "|" << '\n';
	if (loc[0] == 0 && loc[1] == 1 && loc[2] == 0 && loc[3] == 1)	// 양옆이 있으면
		cout << "-" << '\n';
	if (loc[0] == 1 && loc[1] == 1 && loc[2] == 1 && loc[3] == 1)	// 상하좌우가 다 있으면
		cout << "+" << '\n';
	if (loc[0] == 0 && loc[1] == 1 && loc[2] == 1 && loc[3] == 0)	// 오른쪽, 아래가 있으면
		cout << "1" << '\n';
	if (loc[0] == 1 && loc[1] == 1 && loc[2] == 0 && loc[3] == 0)	// 위, 오른쪽이 있으면
		cout << "2" << '\n';
	if (loc[0] == 1 && loc[1] == 0 && loc[2] == 0 && loc[3] == 1)	// 위, 왼쪽이 있으면
		cout << "3" << '\n';
	if (loc[0] == 0 && loc[1] == 0 && loc[2] == 1 && loc[3] == 1)	// 아래, 왼쪽이 있으면
		cout << "4" << '\n';

	return 0;
}
