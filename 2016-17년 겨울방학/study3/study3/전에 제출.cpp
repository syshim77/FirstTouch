#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	string str;
	short sh_m, sh_d;
	short shrg_mnth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> sh_m >> sh_d;
	if (sh_m != 1)
	{
		for (int i = 0; i < sh_m - 1; ++i)
		{
			sh_d += shrg_mnth[i];
		}
	}
	switch (sh_d % 7)
	{
	case 0: str = "SUN";
		break;
	case 1: str = "MON";
		break;
	case 2: str = "TUE";
		break;
	case 3: str = "WED";
		break;
	case 4: str = "THU";
		break;
	case 5: str = "FRI";
		break;
	case 6: str = "SAT";
		break;
	}
	cout << str << endl;

	return 0;
}
