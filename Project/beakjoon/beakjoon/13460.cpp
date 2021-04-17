#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char map[11][11];
int N, M;
char v;
int rx, ry, bx, by;
int dir;
int flagR, flagB;
int res, ans;
void solve(int rrx, int rry, int bbx ,int bby, int ddir) {
	if (flagR == 1 && flagB == 1) {
		return;
	}

	int crx = rrx + dx[ddir];
	int cry = rry + dy[ddir];
	int cbx = bbx + dx[ddir];
	int cby = bby + dy[ddir];



	if (flagR == 0) {
		if (map[crx][cry] == '#' || map[crx][cry] == 'B' || crx < 0 || cry < 0 || crx >= N || cry >= M) {
			crx = rrx; cry = rry;
			flagR = 1;
		}
		else if (map[crx][cry] == 'O') {
			res = 1;
			return;
		}
	}

	if (flagB == 0) {
		if (map[cbx][cby] == '#' || map[cbx][cby] == 'R' || cbx < 0 || cby < 0 || cbx >= N || cby >= M) {
			cbx = bbx; cby = bby;
			flagB = 1;
		}
		else if (map[crx][cry] == 'O') {
			return;
		}

	}
	solve(crx, cry, cbx, cby, ddir);
}
int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);	
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				rx = i; ry = j;
			}else if (map[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	int times = 10;
	dir = -1;
	res = 0;
	while (times--) {
		for (int i = 0; i < 4; i++) {
			flagR = 0; flagB = 0;
			if (dir != i ) {
				solve(rx, ry, bx, by, i);
				dir = i;
			}
		}

		if (res == 1) {
			ans = 10 - times;
			break;
		}
	}

	if (res == 0) printf("%d",ans = -1);
	else printf("%d", ans);

	return 0;
}