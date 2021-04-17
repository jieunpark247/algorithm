#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int N, M, T;
int map[52][52];
int visited[52][52];
vector <int> X,D,K;
int x, d, k;
int res;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };
bool flag;
bool flagOne;
int allVal, cnt;
void rotate(int x,int d,int k) {
	int temp;
	if (d == 0) { //시계
		for (int j = 0; j < k; j++) {
			temp = map[x][M];
			for (int i = M; i > 1; i--) {
				map[x][i] = map[x][i - 1];
			}
			map[x][1] = temp;
		}		
	}
	else if (d == 1) { //반시계
		for (int j = 0; j < k; j++) {
			temp = map[x][1];
			for (int i = 1; i < M; i++) {
				map[x][i] = map[x][i + 1];
			}
			map[x][M] = temp;
		}

	}
}
void nearby(int cx, int cy, int val ,int cnt) {
	if (cnt >= 2) {
		map[cx][cy] = 0;
		flag = true;
	}
	for (int i = 0; i < 4; i++){
		int nx = cx + dx[i];
		int ny = cy + dy[i];

		 if (ny <= 0) ny = M;
		 else if(ny > M) ny = 1;

		if (visited[nx][ny] == 0 && map[nx][ny] == val && map[nx][ny] != 0 && nx > 0 && ny > 0 && nx <= N && ny <= M) {
			visited[nx][ny] = 1;
			nearby(nx, ny, val, cnt + 1);
		}
	}

}
int main() {
	scanf("%d%d%d", &N, &M, &T);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	
	for (int a = 0; a < T; a++) {
		scanf("%d%d%d", &x,&d,&k);
		
		int tm = N / x;
		
		for (int t = 1; t <= tm; t++) {
			rotate(x*t,d,k);
		}

		memset(visited,0,sizeof(visited));

		flagOne = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				flag = false;
				visited[i][j] = 1;
				nearby(i, j, map[i][j], 1);
				if (flag) {
					map[i][j] = 0;
					flagOne = true;
				}
			}
		}

		if (!flagOne) {
			cnt = 0;
			allVal = 0;
 			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j] != 0) {
						allVal += map[i][j];
						cnt++;
					}
				}
			}
		
			double avg = (double)allVal / (double)cnt;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j] != 0 && map[i][j] < avg) {
						map[i][j]++;
					}
					else if(map[i][j] != 0 && map[i][j] > avg) {
						map[i][j]--;
					}
				}
			}
		}


	}
	////////////////////////////////
	res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res += map[i][j];
		}
	}

	printf("%d", res);
}