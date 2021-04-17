#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int N, T, X, Y;
int arr[10001][3];
int map[10][10];
int blue[4][6];
int green[6][4];
int score;
int res;

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j]<< " ";
		}
		cout << endl;
	}
	cout << endl;
}
void moveTile(int type, int x,int y) {
	int a = x;
	int b = y;
	switch (type) {
	case 1:
		while (-1) {
			if (map[x][y] == 0 && x != 10) {
				x = x + 1;
			}
			else {
				map[x - 1][y] = 1;
				break;
			}
		}
		while(-1){
			if (map[a][b] == 0 && b != 10) {
				b = b + 1;
			}
			else {
				map[a][b-1] = 1;
				break;
			}
		}
		break;

	case 2:
		while (-1) {
			if ((map[x][y] == 0 && map[x][y + 1] == 0) && x != 10) {
				x = x + 1;
			}
			else {
				map[x - 1][y] = 1;
				map[x - 1][y+1] = 1;
				break;
			}
		}
		while (-1) {
			if ((map[a][b] == 0 && map[a][b + 1] == 0) && b != 10 && b + 1 < 10) {
				b = b + 1;
			}
			else {
				map[a][b - 1] = 1;
				map[a][b] = 1;
				break;
			}
		}
		break;

	case 3:
		while (-1) {
			if ((map[x][y] == 0 && map[x + 1][y] == 0) && x != 10 && x + 1 < 10) {
				x = x + 1;
			}
			else {
				map[x - 1][y] = 1;
				map[x][y] = 1;
				break;
			}
		}
		while (-1) {
			if ((map[a][b] == 0 && map[a + 1][b] == 0) && b != 10) {
				b = b + 1;
			}
			else {
				map[a][b - 1] = 1;
				map[a + 1][b - 1] = 1;
				break;
			}
		}
		break;
	}
}
void removeTile() {
	//행 , 열이 꽉찼을때
	//blue green
	for (int j = 4; j < 10; j++) {
		int bcnt = 0;
		int gcnt = 0;
		for (int i = 0; i < 4; i++) {
			if (map[i][j] == 1) bcnt++;
			if (map[j][i] == 1) gcnt++;
			if (bcnt == 4) {
				for (int a = 0; a < 4; a++) {
					map[a][j] = 0;
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 9; j >= 4; j--) {
						int a = i; int b = j;
						if (map[a][b] != 0) {
							while (-1) {
								a++;
								if (map[a][b] == 1 || a == 10) {
									map[i][j] = 0;
									map[a - 1][b] = 1;
									break;
								}
							}
						}
					}
				}

				score++;
			}
			if (gcnt == 4) {
				for (int a = 0; a < 4; a++) {
					map[j][a] = 0;
				}
				for (int i = 0; i < 4; i++) {
					for (int j = 9; j >= 4; j--) {
						int a = j; int b = i;
						if (map[a][b] != 0) {
							while (-1) {
								a++;
								if (map[a][b] == 1 || a == 10) {
									map[j][i] = 0;
									map[a - 1][b] = 1;
									break;
								}
							}
						}
					}
				}
	
				score++;
			}
		}
	}

	

	int bflag = 0;
	int gflag = 0;
	//연한 색일 때 
	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[j][i] == 1) {
				if (i == 4) {
					bflag = 2;
					break;
				}
				else {
					bflag = 1;
				}
			}
			if (map[i][j] == 1) {
				if (i == 4) {
					gflag = 2;
					break;
				}
				else {
					gflag = 1;
				}
			}
		}
		if (bflag > 0 || gflag > 0) break;
	}

	for (int i = 9; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			if (bflag >= 1) {
				if ((i == 4 && bflag >= 1) || (i == 3 && bflag == 2)) {
					map[j][i] = 0;
				}
				else {
					map[j][i] = map[j][i - bflag];
				}
			}
			if (gflag >= 1) {
				if ((i == 4 && gflag >= 1) || (i == 3 && gflag == 2)) {
					map[i][j] = 0;
				}
				else {
					map[i][j] = map[i - gflag][j];
				}
			}
		}
	}

}



int main() {
	res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &T, &X, &Y);
		//arr[i][0] = T;
		//arr[i][1] = X;
		//arr[i][2] = Y;
	//	cout << "--------------------" << endl;
		moveTile(T,X,Y);
	//	print();
		removeTile();
	//	print();
	//	cout << "--------------------" << endl;

	}



	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				res++;
			}
		}
	}
	printf("%d", score);
	printf("\n");
	printf("%d", res);
}