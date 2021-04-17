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
	
		////5�����ű�(��輱��) 
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

	//1�� ���ű�
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (area[i][j] == 5) break;
			area[i][j] = 1;
		}
	}
	//2�� ���ű�
	for (int i = x + d2; i >= 1; i--) {
		for (int j = N; j >= y + 1; j--) {
			if (area[i][j] == 5) break;
			area[i][j] = 2;
		}
	}

	//3�� ���ű�
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (area[i][j] == 5) break;
			area[i][j] = 3;
		}
	}
	//4�� ���ű�
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
	
	//���ű� ���� 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int a = 1; a <= N; a++) {
				for (int b = 1; b <= N; b++) {
					//������ ����� ���� 
					if (j - a >= 1 && j + b <= N && i + a + b <= N) {
						//	5�������� default
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								area[i][j] = 0;
							}
						}

						solve(i, j, a, b);

						//���ű� 1~5 ���� ���� �ο� �� 
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								if (area[i][j] == 0) { //��輱�� �׻��̿��ִ°͵��� 5������ �Ų��� 
									area[i][j] = 5;
								}
								arr[area[i][j]] = arr[area[i][j]] + map[i][j];
								
							}
						}

						int maxArea = 0;
						int minArea = 987654321;
						//�ּڰ�
						for (int i = 1; i <= 5; i++) {
							maxArea = max(arr[i], maxArea);
							minArea = min(arr[i], minArea);
						}

						//�α��� ���� ���� ���ű��� ���� ���� ���ű��� �α� ������ �ּڰ�
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