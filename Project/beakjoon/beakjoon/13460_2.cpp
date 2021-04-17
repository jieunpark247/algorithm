#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int N, M;
char map[12][12];
int ans = 11;
int rx, ry, bx, by,ox,oy;
int visited[12][12][12][12];

pair<int, int> go(int x, int y,int dir) {
	int nx = x; int ny = y;
	while (true) {
		 nx = dx[dir] + nx;
		 ny = dy[dir] + ny;

		if (map[nx][ny] == '#') {
			return{ nx- dx[dir],ny- dy[dir] };
		}
		else if (map[nx][ny] == 'O') {
			return{ nx,ny };
		}
	}

	return { nx,ny };
}

void solve(int rex, int rey, int bex, int bey,int depth) {
	if (depth == 10) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		pair<int, int> blue = go(bex, bey, i);
		pair<int, int> red = go(rex, rey, i);
		if (red.first == ox && red.second == oy) {
			if (blue.first == ox && blue.second == oy) {
				continue;
			}
			else {
				ans = (ans > depth + 1 ? depth + 1 : ans);
		
			}
			return;
		}
		else if (blue.first == ox && blue.second == oy) continue;
	

		if (red.first == blue.first && red.second == blue.second) {
			switch (i) {
			case 0:
				if (rey > bey)  blue.second = blue.second - 1;
				else  red.second = red.second - 1;
				break;

			case 1:
				if (rex < bex) red.first = red.first - 1;
				else blue.first = blue.first - 1;
				break;

			case 2:
				if (rey > bey) red.second = red.second + 1;
				else blue.second = blue.second + 1;
				break;

			case 3:
				if (rex< bex) blue.first = blue.first + 1;
				else red.first = red.first + 1;
				break;
			}


		}
		if (visited[red.first][red.second][blue.first][blue.second] == 1 ) continue;
		visited[red.first][red.second][blue.first][blue.second] = 1;
		solve(red.first, red.second, blue.first, blue.second, depth + 1);
		visited[red.first][red.second][blue.first][blue.second] = 0;

	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'B') bx = i, by = j;
			else if (map[i][j] == 'R') rx = i, ry = j;
			else if (map[i][j] == 'O') ox = i, oy = j;
		}
	}
	visited[rx][ry][bx][by] = 1;
//	for (int i = 0; i < 4; i++) {
		solve(rx, ry, bx, by, 0);
//	}
	if (ans > 10) printf("%d", -1);
	else printf("%d", ans);


}