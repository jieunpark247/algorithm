#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int N, M, T;
int map[52][52];
int vis[52][52];
int sum;
int res;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };
int val;
int flag;int allSum; int allCnt;
int xx; int dd; int kk;
void removeSameNum(int cnt,int x, int y,int v) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (ny <= 0) nx = M;
		if (ny > M) ny = 1;
	

		if (nx <= N && ny <= M && nx > 0 && ny > 0 && vis[nx][ny] == 0 && map[nx][ny] == v && map[nx][ny] !=0) {
			flag = 1;
			vis[nx][ny] = 1;
			map[nx][ny] = 0;
			map[x][y] = 0;
			removeSameNum(cnt+1, nx, ny, v);
			map[nx][ny] = 0;
			map[x][y] = 0;
		}
	}
}
void rotateCIrcle(int x, int d,int k) {

	for (int j = 1; j <= (N / x); j++) {
		for (int i = 0; i < k; i++) {
			if (d == 0) {//시계
				map[x * j][0] = map[x * j][M];
				for (int a = M; a > 0; a--) {
					map[x * j][a] = map[x * j][a - 1];
				}
				map[x * j][0] = 0;

			}
			else if (d == 1) {//반시계
				map[x * j][M + 1] = map[x * j][1];
				for (int a = 1; a <= M; a++) {
					map[x * j][a] = map[x * j][a + 1];
				}
				map[x * j][M + 1] = 0;
			}
		}
	}

}

int main() {
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int t = 0; t < T; t++) {
		scanf("%d%d%d", &xx, &dd, &kk);
		allSum = 0; allCnt = 0; flag = 0;

		rotateCIrcle(xx, dd, kk); //원판 회전 
		
		memset(vis,0,sizeof(vis));
	
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (vis[i][j] == 0 && map[i][j] != 0) {
					vis[i][j] = 1;
					allSum += map[i][j];
					allCnt++;
					removeSameNum(0, i, j, map[i][j]); // 인접 숫자 제거 or 평균
				}
			}
		}

		if (flag == 0) {
			double avg = (double)allSum / (double)allCnt;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j] != 0) {
						if (avg < map[i][j]) {
							map[i][j]--;
						}
						else if (avg > map[i][j]) {
							map[i][j]++;
						}
					}
				}
			}

		}
	}

	res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res += map[i][j];
		}
	}//원판 적힌 수의 합 

	printf("%d", res);

}