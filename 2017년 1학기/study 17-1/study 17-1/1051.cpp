#include <stdio.h> 
#include <math.h>	//sqrt() 

char table[1000][1000];
int hei, wid;	//max table height, max table width; 
int ans = 1;	//answer variable 

void makeTable() {	//input table values 
	int i, j;
	for (i = 0; i<hei; i++) {
		for (j = 0; j<wid; j++) {
			scanf_s("%c", &table[i][j]);
			if (table[i][j] == '\n')
			{
				j--; printf("%d", j);
			}
		}
	}
}

void search(int thisHei, int thisWid) {
	int addVal = sqrt(ans);
	while (thisHei + addVal < hei || thisWid + addVal < wid) {
		if (table[thisHei][thisWid] == table[thisHei + addVal][thisWid + addVal] &&
			table[thisHei][thisWid] == table[thisHei + addVal][thisWid] &&
			table[thisHei][thisWid] == table[thisHei][thisWid + addVal]) {
			ans = (addVal + 1) * (addVal + 1);	//addValue = 2 -> lineLength = 3; 
		}
		addVal++;
	}
}

void solve() {
	int i, j;
	for (i = 0; i<hei; i++) {
		for (j = 0; j<wid; j++) {
			search(i, j);
		}
	}
}

int main(void) {
	scanf_s("%d %d", &hei, &wid);
	makeTable();
	solve();
	printf("%d\n", ans);
	return 0;
}