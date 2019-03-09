#include <iostream>
#include <queue>
#define BLOCK_VER	'|'
#define BLOCK_1		'1'
#define BLOCK_2		'2'
#define BLOCK_3		'3'
#define BLOCK_4		'4'
#define BLOCK_HOR	'-'
#define BLOCK_CRO	'+'
using namespace std;

char arr[26][26];	// 블럭
bool visit[26][26];	// 방문 여부
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;

struct Q {	// 지워진 블럭의 행, 열 위치와 블럭 종류
	int x;
	int y;
	char bridge;
};
queue<Q> q;

bool check_plus_x(int nx, int ny) {
	nx = nx + 1;
	if (nx <= n - 1 &&
		(arr[nx][ny] == BLOCK_VER || arr[nx][ny] == BLOCK_CRO ||
			arr[nx][ny] == BLOCK_2 || arr[nx][ny] == BLOCK_3)) {
		return true;
	}
	return false;
}

bool check_minus_x(int nx, int ny) {
	nx = nx - 1;
	if (nx >= 0 &&
		(arr[nx][ny] == BLOCK_VER || arr[nx][ny] == BLOCK_CRO ||
			arr[nx][ny] == BLOCK_1 || arr[nx][ny] == BLOCK_4)) {
		return true;
	}
	return false;
}

bool check_plus_y(int nx, int ny) {
	ny = ny + 1;
	if (ny <= m - 1 &&
		(arr[nx][ny] == BLOCK_HOR || arr[nx][ny] == BLOCK_CRO ||
			arr[nx][ny] == BLOCK_3 || arr[nx][ny] == BLOCK_4)) {
		return true;
	}
	return false;
}

bool check_minus_y(int nx, int ny) {
	ny = ny - 1;
	if (ny >= 0 &&
		(arr[nx][ny] == BLOCK_HOR || arr[nx][ny] == BLOCK_CRO ||
			arr[nx][ny] == BLOCK_1 || arr[nx][ny] == BLOCK_2)) {
		return true;
	}
	return false;
}

void eq_minus_y(int nx, int ny, char bridge) {
	if (ny >= 0 && !visit[nx][ny]) {
		if (arr[nx][ny] != '.') {
			visit[nx][ny] = true;
			q.push({ nx,ny,bridge });
		}
		else if (arr[nx][ny] == '.' && bridge == NULL) {
			if (check_plus_x(nx, ny) && check_minus_x(nx, ny) && check_minus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_CRO });
			}
			else if (check_minus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_HOR });
			}
			else if (check_plus_x(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_1 });
			}
			else if (check_minus_x(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_2 });
			}
		}
	}
}

void eq_plus_y(int nx, int ny, char bridge) {
	if (ny <= m - 1 && !visit[nx][ny]) {
		if (arr[nx][ny] != '.') {
			visit[nx][ny] = true;
			q.push({ nx,ny,bridge });
		}
		else if (arr[nx][ny] == '.' && bridge == NULL) {
			if (check_plus_x(nx, ny) && check_minus_x(nx, ny) && check_plus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_CRO });
			}
			else if (check_plus_x(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_4 });
			}
			else if (check_minus_x(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_3 });
			}
			else if (check_plus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_HOR });
			}
		}
	}
}

void eq_minus_x(int nx, int ny, char bridge) {
	if (nx >= 0 && !visit[nx][ny]) {
		if (arr[nx][ny] != '.') {
			visit[nx][ny] = true;
			q.push({ nx,ny,bridge });
		}
		else if (arr[nx][ny] == '.' && bridge == NULL) {
			if (check_minus_x(nx, ny) && check_minus_y(nx, ny) && check_plus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_CRO });
			}
			else if (check_minus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_4 });
			}
			else if (check_minus_x(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_VER });
			}
			else if (check_plus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_1 });
			}
		}
	}
}

void eq_plus_x(int nx, int ny, char bridge) {
	if (nx <= n - 1 && !visit[nx][ny]) {
		if (arr[nx][ny] != '.') {
			visit[nx][ny] = true;
			q.push({ nx,ny,bridge });
		}
		else if (arr[nx][ny] == '.' && bridge == NULL) {
			if (check_plus_x(nx, ny) && check_minus_y(nx, ny) && check_plus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_CRO });
			}
			else if (check_minus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_3 });
			}
			else if (check_plus_x(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_VER });
			}
			else if (check_plus_y(nx, ny)) {
				visit[nx][ny] = true;
				q.push({ nx,ny,BLOCK_2 });
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		char bridge = q.front().bridge;
		q.pop();

		if (bridge != NULL) {
			cout << x + 1 << ' ' << y + 1 << ' ' << bridge << '\n';
			return;
		}

		if (arr[x][y] == 'M' || arr[x][y] == 'Z') {
			for (int i = 0; i < 4; i++) {
				int nx = dy[i] + x;
				int ny = dx[i] + y;
				if (nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m - 1 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny,bridge });
				}
			}
		}
		else if (arr[x][y] == BLOCK_VER) {
			eq_plus_x(x + 1, y, bridge);
			eq_minus_x(x - 1, y, bridge);
		}
		else if (arr[x][y] == BLOCK_1) {
			eq_plus_x(x + 1, y, bridge);
			eq_plus_y(x, y + 1, bridge);
		}
		else if (arr[x][y] == BLOCK_2) {
			eq_plus_x(x, y + 1, bridge);
			eq_minus_x(x - 1, y, bridge);
		}
		else if (arr[x][y] == BLOCK_3) {
			eq_minus_y(x, y - 1, bridge);
			eq_minus_x(x - 1, y, bridge);
		}
		else if (arr[x][y] == BLOCK_4) {
			eq_plus_x(x + 1, y, bridge);
			eq_minus_y(x, y - 1, bridge);
		}
		else if (arr[x][y] == BLOCK_HOR) {
			eq_minus_y(x, y - 1, bridge);
			eq_plus_y(x, y + 1, bridge);
		}
		else if (arr[x][y] == BLOCK_CRO) {
			eq_minus_y(x, y - 1, bridge);
			eq_plus_y(x, y + 1, bridge);
			eq_minus_x(x - 1, y, bridge);
			eq_plus_x(x + 1, y, bridge);
		}
		else { // arr[y][x] == '.' 또는 도착점
			if (bridge == BLOCK_VER) {
				eq_plus_x(x + 1, y, bridge);
				eq_minus_x(x - 1, y, bridge);
			}
			else if (bridge == BLOCK_1) {
				eq_plus_x(x + 1, y, bridge);
				eq_plus_y(x, y + 1, bridge);
			}
			else if (bridge == BLOCK_2) {
				eq_plus_y(x, y + 1, bridge);
				eq_minus_x(x - 1, y, bridge);
			}
			else if (bridge == BLOCK_3) {
				eq_minus_y(x, y - 1, bridge);
				eq_minus_x(x - 1, y, bridge);
			}
			else if (bridge == BLOCK_4) {
				eq_plus_x(x + 1, y, bridge);
				eq_minus_y(x, y - 1, bridge);
			}
			else if (bridge == BLOCK_HOR) {
				eq_minus_y(x, y - 1, bridge);
				eq_plus_y(x, y + 1, bridge);
			}
			else if (bridge == BLOCK_CRO) {
				eq_minus_y(x, y - 1, bridge);
				eq_plus_y(x, y + 1, bridge);
				eq_minus_x(x - 1, y, bridge);
				eq_plus_x(x + 1, y, bridge);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'M')
				q.push({ i,j,NULL });
		}
	}

	bfs();
	return 0;
}