#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

int N; int Q; int L;
int map[70][70];
int tmpMap[70][70];
int visit[70][70];
int M;
int bigCount;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>> q;
int removeIce(int x, int y) {
	int ans = 0 ;
	if (x-1>=0 && tmpMap[x - 1][y] != 0) {
		ans++;
	}
	if (y-1>=0 && tmpMap[x][y - 1] != 0) {
		ans++;
	}
	if (x+1 < M && tmpMap[x + 1][y] != 0) {
		ans++;
	}
	if (y+1 < M && tmpMap[x][y + 1] != 0) {
		ans++;
	}
	return ans;
}
void rotate(int xstart, int xend, int ystart, int yend,int n ) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			tmpMap[i][j] = map[i][j];
		}
	}
	for (int i = xstart; i <xend; i++) { //a+mapsize 시작위치 ,, mapSize 잘린 맵 크기 
		for (int j = ystart; j < yend; j++) {
			map[i][j] = tmpMap[xstart + ystart + n - j - 1][ystart-xstart + i];
		}
	}

}

void solve(int mapSize,int totalSize) {

	int mapCnt = totalSize / mapSize;
	for (int a = 0; a < mapCnt; a++) {
		for (int b = 0; b < mapCnt; b++){
			int xs = a * mapSize;
			int xe = (a * mapSize) + mapSize;
			int ys = b * mapSize;
			int ye = (b * mapSize) + mapSize;
			rotate(xs, xe, ys, ye, mapSize);
			xs = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			tmpMap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (3 > removeIce(i, j)) {
				if(map[i][j] != 0 ) map[i][j]--;
			}
		}
	}

}
void bigLump(int x, int y,int cnt) { // 큰 덩어리 개수 
	q.push({x,y});
	visit[x][y] = -1;
	int ncnt;
	int ccnt =1;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = nx + dx[i];
			int cy = ny + dy[i];
			if (map[cx][cy] != 0 && visit[cx][cy] != -1 && cx >= 0 && cy >= 0 && cx < M && cy < M) {
				visit[cx][cy] = -1;
				ccnt++;
				q.push({cx,cy});
			}
		}
	}
	if (bigCount < ccnt) {
		bigCount = ccnt;
	}
}
int main() {
	scanf("%d%d", &N, &Q);
	M = pow(2, N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &L);
		int mapSize = pow(2, L);
		solve(mapSize, M);
	}
	int sum =0;
	bigCount = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			sum += map[i][j];
			if (map[i][j] != 0 && visit[i][j] != -1) {
				bigLump(i,j,0);
			}
		}
	}

	printf("%d\n", sum);
	printf("%d", bigCount);
	return 0;
}
