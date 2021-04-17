#include <iostream>
#include <math.h>
using namespace std;
int N;
int map[502][502];
int visit[502][502];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int sum;
void moveSend(int x, int y, int dir) {
	int totalSend =  map[x][y];

	int val = (int)map[x][y] * 0.05;
	if (x + 2 * dx[dir] >= 0 && x + 2 * dx[dir] < N && y + 2 * dy[dir] >= 0 && y + 2 * dy[dir] < N) {
		map[x + 2 * dx[dir]][y + 2 * dy[dir]] += val;
	}
	totalSend -= val;
	
	int ndir = (dir + 1) % 4;
	val = (int)map[x][y] * 0.07;
	if (x + dx[ndir] >= 0 && x + dx[ndir] < N && y + dy[ndir] >= 0 && y + dy[ndir] < N) {
		map[x + dx[ndir]][y + dy[ndir]] += val;
	}
	totalSend -= val;
	val = (int)map[x][y] * 0.02;
	if (x + 2 * dx[ndir] >= 0 && x + 2 * dx[ndir] < N && y + 2 * dy[ndir] >= 0 && y + 2 * dy[ndir] < N) {
		map[x + 2 * dx[ndir]][y + 2 * dy[ndir]] += val;
	}
	totalSend -= val;
	val = (int)map[x][y] * 0.1;
	if (x + dx[ndir] + dx[dir] >= 0 && x + dx[ndir] + dx[dir] < N && y + dy[ndir] + dy[dir] >= 0 && y + dy[ndir] + dy[dir] < N) {
		map[x + dx[ndir] + dx[dir]][y + dy[ndir] + dy[dir]] += val;
	}
	totalSend -= val;
	int bdir = (dir + 2) % 4;
	val = (int)map[x][y] * 0.01;
	if (x + dx[ndir] + dx[bdir] >= 0 && x + dx[ndir] + dx[bdir] < N && y + dy[ndir] + dy[bdir] >= 0 && y + dy[ndir] + dy[bdir] < N) {
		map[x + dx[ndir] + dx[bdir]][y + dy[ndir] + dy[bdir]] += val;
	}
	totalSend -= val;

	ndir = (dir + 3) % 4;
	val = (int)map[x][y] * 0.07;
	if (x + dx[ndir] >= 0 && x + dx[ndir] < N && y + dy[ndir] >= 0 && y + dy[ndir] < N) {
		map[x + dx[ndir]][y + dy[ndir]] += val;
	}
	totalSend -= val;
	val = (int)map[x][y] * 0.02;
	if (x + 2 * dx[ndir] >= 0 && x + 2 * dx[ndir] < N && y + 2 * dy[ndir] >= 0 && y + 2 * dy[ndir] < N) {
		map[x + 2 * dx[ndir]][y + 2 * dy[ndir]] += val;
	}
	totalSend -= val;
	val = (int)map[x][y] * 0.1;
	if (x + dx[ndir] + dx[dir] >= 0 && x + dx[ndir] + dx[dir] < N && y + dy[ndir] + dy[dir] >= 0 && y + dy[ndir] + dy[dir] < N) {
		map[x + dx[ndir] + dx[dir]][y + dy[ndir] + dy[dir]] += val;
	}
	totalSend -= val;
	bdir = (dir + 2) % 4;
	val = (int)map[x][y] * 0.01;
	if (x + dx[ndir] + dx[bdir] >= 0 && x + dx[ndir] + dx[bdir] < N && y + dy[ndir] + dy[bdir] >= 0 && y + dy[ndir] + dy[bdir] < N) {
		map[x + dx[ndir] + dx[bdir]][y + dy[ndir] + dy[bdir]] += val;
	}
	totalSend -= val;
	if (x + dx[dir] >= 0 && x + dx[dir] < N && y + dy[dir] >= 0 && y + dy[dir] < N) {
		map[x + dx[dir]][y + dy[dir]] += totalSend;
	}
	map[x][y] = 0;
}
void rotate(int x, int y, int dir) {
	moveSend(x, y, dir);
	if (x == 0 && y == 0) return;
	int ndir = (dir + 1) % 4;
	int nx = x + dx[ndir];
	int ny = y + dy[ndir];

	if (visit[nx][ny] == 0 ) {
		visit[nx][ny] = 1;
		rotate(nx, ny, ndir);
	}
	else {
		visit[x + dx[dir]][y + dy[dir]] = 1;
		rotate(x + dx[dir], y + dy[dir], dir);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			sum += map[i][j];
		}
	}
	int x = N / 2 + dx[0];
	int y = N / 2 + dy[0];
	visit[N / 2][N / 2] = 1;
	visit[x][y] = 1;
	rotate(x, y, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum -= map[i][j];
		}
	}
	printf("%d", sum);
	return 0;
}