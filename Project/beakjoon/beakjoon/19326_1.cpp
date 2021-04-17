#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int map[4][4][2];
int fish[17][3];
int shx, shy, shDir;
int eatFishNum;
int temp[4][4][2];
int tempFish[17][3];
void copyMap() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int z = 0; z < 2; z++) {
				map[i][j][z] =  temp[i][j][z];
			}
		}
	}

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 3; j++) {
			fish[i][j] = tempFish[i][j]; 
		}
	}
}
void initMap() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int z = 0; z < 2; z++) {
				temp[i][j][z] = map[i][j][z];
			}
		}
	}

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 3; j++) {
			tempFish[i][j] = fish[i][j];
		}
	}
}
void eatFish(int x,int y) {
	for (int j = 0; j < 3; j++) {
		fish[map[x][y][0]][j] = 0;
	}
	map[x][y][0] = map[x][y][1] = 0;
}
void moveFish(int fishN) {
	int x = fish[fishN][1];
	int y = fish[fishN][2];
	int dir = fish[fishN][0];

	for (int i = 0; i <= 8; i++) {
		int ndir;
		if (i != 0) {
			 ndir = (dir-1 + i) % 8 +1;
		}
		else {
			ndir = dir;
		}
		int nx = x + dx[ndir];
		int ny = y + dy[ndir];

		if (shx != nx || shy != ny) {
			if ((nx >= 0 && ny >= 0 && nx < 4 && ny < 4)) {
				//물고기 이동 o 
				//물고기 둘이 바꿈 
				int tempfishNum; int tempfishDir;
				map[x][y][1] = ndir;
				tempfishNum = map[x][y][0];
				tempfishDir = map[x][y][1];

				map[x][y][0] = map[nx][ny][0];
				map[x][y][1] = map[nx][ny][1];

				map[nx][ny][0] = tempfishNum;
				map[nx][ny][1] = tempfishDir;

				fish[map[x][y][0]][0] = map[x][y][1];
				fish[map[x][y][0]][1] = x; fish[map[x][y][0]][2] = y;
				fish[map[nx][ny][0]][0] = map[nx][ny][1];
				fish[map[nx][ny][0]][1] = nx; fish[map[nx][ny][0]][2] = ny;

				break;

			}
		}
	}
	
}

void moveShark(int ef,int x, int y ,int dir) {

	initMap();

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[dir];
		int ny = x + dy[dir];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return;

		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			shx = nx;
			shy = ny; 
			shDir = map[shy][shx][1];
			eatFish(shx, shy);
			for (int i = 1; i < 17; i++) {
				moveFish(i);
			}
			moveShark(eatFishNum++, shx, shy, shDir);
			copyMap();
		}
	}
}
int main() {

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j= 0; j < 4; j++) {
			scanf("%d", &map[i][j][0]);
			scanf("%d", &map[i][j][1]);
			fish[map[i][j][0]][0] = map[i][j][1];
			fish[map[i][j][0]][1] = i;
			fish[map[i][j][0]][2] = j;
		}
	}
	
	shy = shx = 0;
	shDir = map[shy][shx][1];
	eatFish(shx,shy);
	eatFishNum = 1;
	for (int i = 1; i < 17; i++) {
		moveFish(i);
	}
	//첫번째 턴 먼저 

	moveShark(eatFishNum,shx,shy,shDir);

	printf("%d", eatFishNum);
}