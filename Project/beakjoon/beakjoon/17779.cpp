#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int N, map[21][21], area[21][21];
int arr[6];
int res = 987654321;
int dy[4] = { -1,1,1,-1 };
int dx[4] = { 1,1,-1,-1 };

void solve(int x, int y, int d1, int d2) {
	
		////5번선거구(경계선만) 
	int nx = x, ny = y;
	area[x][y] = 5;
	int dir = 0;
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < d1; i++) {
			nx = nx + dx[dir];
			ny = ny + dy[dir];
			area[nx][ny] = 5;
		}
		++dir;
		for (int j = 0; j < d2; j++) {
			nx = nx + dx[dir];vb
			area[nx][ny] = 5;
		}
		++dir;
	}

	//1번 선거구
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (area[i][j] == 5) break;
			area[i][j] = 1;
		}
	}
	//2번 선거구
	for (int i = x + d2; i >= 1; i--) {
		for (int j = N; j >= y + 1; j--) {
			if (area[i][j] == 5) break;
			area[i][j] = 2;
		}
	}

	//3번 선거구
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (area[i][j] == 5) break;
			area[i][j] = 3;
		}
	}
	//4번 선거구
	for (int i = N; i >= x + d2 + 1; i--) {
		for (int j = N; j >= y - d1 + d2; j--) {
			if (area[i][j] == 5) break;
			area[i][j] = 4;
		}
	}

}

int main() {
	scanf("%d" ,&N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d" ,&map[i][j]);
		 }
	}
	
	//선거구 나눔 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int a = 1; a <= N; a++) {
				for (int b = 1; b <= N; b++) {
					//범위에 벗어나면 리턴 
					if (j - a >= 1 && j + b <= N && i + a + b <= N) {
						//	5구역으로 default
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								area[i][j] = 0;
							}
						}

						solve(i, j, a, b);

						//선거구 1~5 까지 별로 인원 셈 
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								if (area[i][j] == 0) { //경계선과 그사이에있는것들은 5번으로 매꿔줌 
									area[i][j] = 5;
								}
								arr[area[i][j]] = arr[area[i][j]] + map[i][j];
								
							}
						}

						int maxArea = 0;
						int minArea = 987654321;
						//최솟값
						for (int i = 1; i <= 5; i++) {
							maxArea = max(arr[i], maxArea);
							minArea = min(arr[i], minArea);
						}

						//인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값
						res = min(res, (maxArea - minArea));

						for (int i = 1; i <= 5; i++) {
							arr[i] = 0;
						}
					}
				}
			}
		}
	}
	printf("%d", res);
}