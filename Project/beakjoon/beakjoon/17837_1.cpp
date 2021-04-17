#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int N, K;
int map[15][15][15];
int mapcolor[15][15];
bool endflag;
//vector<int, int> map[15][15];
int mal[15][4];
int res;
int dy[5] = { 0,1,-1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

int changeDir(int dir) {
	int ndir;
	if (dir % 2 == 1) {
		ndir = dir + 1;
	}
	else if (dir % 2 == 0) {
		ndir = dir - 1;
	}
	return ndir;
}
void solve(int x, int y, int dir,int val) {
	bool isWall = false;
	if (x + dx[dir] <= 0 || y + dy[dir]<=0 || x + dx[dir] > N || y + dy[dir] > N) {
		isWall = true;
		dir = changeDir(dir);
		mal[val][2] = dir;

	}
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int currLvl=0;
	int depth = map[x][y][0];

	for (int i = 1; i <= depth; i++) {
		if (map[x][y][i] == val) {
			currLvl = i;
		}
	}

	if (mapcolor[nx][ny] == 0) {
		//»Ú
		for (int i = currLvl; i <= depth; i++) {
			map[nx][ny][map[nx][ny][0] + 1] = map[x][y][i];
			mal[map[x][y][i]][0] = nx;
			mal[map[x][y][i]][1] = ny;
			map[x][y][i] = 0;
			map[x][y][0]--;
			map[nx][ny][0]++;
		}
	}
	else if (mapcolor[nx][ny] == 1) {
		//ª°
		for (int i = depth; i >= currLvl; i--) {
			map[nx][ny][map[nx][ny][0] + 1] = map[x][y][i];
			mal[map[x][y][i]][0] = nx;
			mal[map[x][y][i]][1] = ny;
			map[x][y][i] = 0;
			map[x][y][0]--;
			map[nx][ny][0]++;
		}

	}
	else if (mapcolor[nx][ny] == 2) {
		//∆ƒ
		dir = changeDir(dir);
		if (isWall == false || mapcolor[x + dx[dir]][y+dy[dir]] != 2) { 
			// ∫Æø° ∞£ ¿˚¿Ã æ¯¥¬ ∞ÊøÏ, πŸ≤Ô πÊ«‚¿Ã ∆ƒ∂˚¿Ã æ∆¥—∞ÊøÏ
			mal[val][2] = dir;
			if (mapcolor[x + dx[dir]][y + dy[dir]] == 1) {
				//ª°∞≠
				for (int i = depth; i >= currLvl; i--) {
					map[nx][ny][map[nx][ny][0] + 1] = map[x][y][i];
					mal[map[x][y][i]][0] = nx;
					mal[map[x][y][i]][1] = ny;
					map[x][y][i] = 0;
					map[x][y][0]--;
					map[nx][ny][0]++;
				}
			}else{
				//»Ú
				for (int i = currLvl; i <= depth; i++) {
					map[nx][ny][map[nx][ny][0] + 1] = map[x][y][i];
					mal[map[x][y][i]][0] = nx;
					mal[map[x][y][i]][1] = ny;
					map[x][y][i] = 0;
					map[x][y][0]--;
					map[nx][ny][0]++;
				}
			}
		}

	}

	if (map[nx][ny][0] >= 4) endflag = true;


}
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &mapcolor[i][j]);
		}
	}

	for (int i = 1; i <= K; i++) {
		scanf("%d%d%d", &mal[i][0], &mal[i][1], &mal[i][2]);
		map[mal[i][0]][mal[i][1]][0] = 1;
		map[mal[i][0]][mal[i][1]][1] = i;
	}
	res = -1;
	int cnt = 0;
	endflag = false;
	while (-1) {
		cnt++;
		for (int i = 1; i <= K; i++) {
			solve(mal[i][0], mal[i][1], mal[i][2],i);
			if (cnt > 1000 || endflag == true) break;
		}
			if (cnt > 1000 || endflag == true) break;
	}
	
	if (cnt <= 1000) res = cnt;
	printf("%d", res);
}