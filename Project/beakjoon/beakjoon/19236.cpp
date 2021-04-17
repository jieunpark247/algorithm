//청소년 상어
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct fishLoc {
	int x;
	int y;
	int dir;
};
int map[5][5];
int visited[5][5];
fishLoc fish[17];
int dx[9] = {0, -1,-1,0,1,1,1,0,-1 };
int dy[9] = {0, 0,-1,-1,-1,0,1,1,1 };
int tempFish;
void copyMap(int tmpMap[5][5], fishLoc tmpFish[17]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmpMap[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		tmpFish[i] = fish[i];
	}
}
void copyTemp(int tmpMap[5][5], fishLoc tmpFish[17]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = tmpMap[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		fish[i] = tmpFish[i];
	}
}
void moveFish() {
	for (int i = 1; i <= 16; i++) {
		int dir = fish[i].dir;
		for (int d = dir; d < dir + 8; d++) {
			int x = fish[i].x; 
			int y = fish[i].y;
			int dd = d > 8 ? d % 8 : d;
			int nx = x + dx[dd % 9];
			int ny = y + dy[dd % 9];
			if (fish[i].dir == 0) continue;
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && map[nx][ny] != -1 && map[x][y] != -1 ) {
					tempFish = map[nx][ny];
					map[x][y] = tempFish;
					fish[tempFish].x = x; fish[tempFish].y = y;
					map[nx][ny] = i;
					fish[i].x = nx; fish[i].y = ny;
					fish[i].dir = d > 8 ? d % 8 : d;
					break;
			}
		}
	}
}

int moveShark(int sx, int sy, int sdir,int eat) {
	moveFish();
	int tmpMap[5][5];
	fishLoc tmpFish[17];
	int eatedFish = 0;
	copyMap(tmpMap, tmpFish);
	for (int i = 1; i <= 4; i++) {
		int nx = sx + dx[sdir] * i;
		int ny = sy + dy[sdir] * i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 &&  map[nx][ny] > 0) {
			int ndir = fish[map[nx][ny]].dir;
			map[sx][sy] = 0;
			fish[map[nx][ny]].x = fish[map[nx][ny]].y = fish[map[nx][ny]].dir = 0;
			int ef = map[nx][ny];
			map[nx][ny] = -1;
 			eatedFish = max(moveShark(nx, ny, ndir, eat + ef),eatedFish);
			copyTemp(tmpMap, tmpFish);
		}
	}
	return max(eat, eatedFish);
}
 
int main() {
	int dir;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d%d", &map[i][j], &dir);
			fish[map[i][j]] = { i,j,dir };
		}
	}

	//맨처음 0,0에서 물고기 먹음
	int sdir =  fish[map[0][0]].dir;
	fish[map[0][0]].x  = fish[map[0][0]].y = fish[map[0][0]].dir = 0;
	int f = map[0][0];
	map[0][0] = -1; // -1은 상어 0은 암것도 없음 
	//물고기 이동 , 상어 이동 
	printf("%d",moveShark(0, 0, sdir,f));	
	return 0;
}