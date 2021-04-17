#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K;
int map[21][21][2];
int temp[21][21][2];
int shDir[1600][4];
int sh[421][3];
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int shark;
int sum;
int mv;

void copy_map() {
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			temp[a][b][0] = map[a][b][0];
			temp[a][b][1] = map[a][b][1];
		}
	}
}

void solve() {

	for (int i = 1; i <= M; i++) {
		mv = 0;
		if (sh[i][0] == 0) 	continue;

		for (int j = 0; j < 4; j++) {
			int dir = shDir[(i - 1) * 4 + sh[i][0]][j];
			int nx = sh[i][1] + dx[dir];
			int ny = sh[i][2] + dy[dir];
			if (temp[nx][ny][0] == 0 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
				mv = 1;
				//냄새x 기준 (우선순위)
				if (map[nx][ny][0] != 0 && map[nx][ny][0] < i) {
					sh[i][0] = 0;
					shark--;
					break;
				}
				map[nx][ny][0] = i;
				map[nx][ny][1] = K;
				sh[i][0] = dir;
				sh[i][1] = nx;
				sh[i][2] = ny;
				break;
			}
		}
		if (mv == 1) continue;

		for (int j = 0; j < 4; j++) {
			int dir = shDir[(i - 1) * 4 + sh[i][0]][j];
			int nx = sh[i][1] + dx[dir];
			int ny = sh[i][2] + dy[dir];
			if (temp[nx][ny][0] == i && nx > 0 && ny > 0 && nx <= N && ny <= N) {
				//내 냄새 (우선순위)
				mv = 1;
				//냄새x 기준 (우선순위)
				if (map[nx][ny][0] != 0 && map[nx][ny][0] < i) {
					sh[i][0] = 0;
					shark--;
					break;
				}

				map[nx][ny][0] = i;
				map[nx][ny][1] = K;
				sh[i][0] = dir;
				sh[i][1] = nx;
				sh[i][2] = ny;
				break;
			}
		}
		if (mv == 1) continue;

	}

}
int main() {
	sum = 0;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j][0]);
			if (map[i][j][0] != 0) {
				map[i][j][1] = K;
				sh[map[i][j][0]][1] = i;
				sh[map[i][j][0]][2] = j;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &sh[i][0]);
	}
	int s = 0;
	for (int i = 1; i <= M; i++) {
		for (int i = 1; i <= 4; i++) {
			s++;
			scanf("%d%d%d%d", &shDir[s][0], &shDir[s][1], &shDir[s][2], &shDir[s][3]);
		}
	}
	shark = M;
	while (-1) {
		//냄새 하나 사라짐 
		copy_map();
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				if (map[a][b][0] != 0) {
					map[a][b][1]--;
					if (map[a][b][1] == 0) map[a][b][0] = 0;
				}
			}
		}
		solve();

		sum++;
		if (shark == 1) break;
		if (sum > 1000) break;
	}
	if (sum > 1000) sum = -1;
	printf("%d", sum);
	return 0;
}