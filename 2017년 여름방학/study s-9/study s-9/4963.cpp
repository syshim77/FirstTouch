#include <iostream>
using namespace std;

int x[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int y[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int map[55][55] = {};
int dfs[55][55] = {};
int w, h;

void visit(int nx, int ny)
{
	dfs[nx][ny] = 1;

	for (int i = 0; i < 8; i++)
	{
		int loc_x = nx + x[i];
		int loc_y = ny + y[i];

		if (loc_x >= 0 && loc_x < h && loc_y >= 0 && loc_y < w)
		{
			if (dfs[loc_x][loc_y] == 0 && map[loc_x][loc_y] == 1)
				visit(loc_x, loc_y);
		}
	}
}

int main()
{
	while (1)
	{
		int cnt = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < 55; i++)
		{
			for (int j = 0; j < 55; j++)
			{
				map[i][j] = 0;
				dfs[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (dfs[i][j] == 0 && map[i][j] == 1)
				{
					visit(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}