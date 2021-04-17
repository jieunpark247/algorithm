#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int tc, N;
char arr[1001][2];
char u[3][3], d[3][3], f[3][3], b[3][3], l[3][3], r[3][3];
char temp[3][3];
int clock[2][8];
void goClock(int flag) {
	if (flag == true) {
		for (int z = 0; z < 2; z++) {
			char tmp = u[0][0];
			char ttmp = '0';
			for (int j = 0; j < 8; j++) {
				int x = clock[0][j];
				int y = clock[1][j];
				int nx = clock[0][(j + 1) % 8];
				int ny = clock[1][(j + 1) % 8];
				ttmp = tmp;
				tmp = u[nx][ny];
				u[nx][ny] = ttmp;
			}
		}
	}
	else if (flag == false) {
		for (int z = 0; z < 2; z++) {
			char tmp = u[1][0];
			char ttmp = '0';
			for (int j = 7; j >= 0; j--) {
				int x = clock[0][j];
				int y = clock[1][j];
				int nx = clock[0][(j - 1 +8) % 8];
				int ny = clock[1][(j - 1 +8) % 8];
				ttmp = tmp;
				tmp = u[nx][ny];
				u[nx][ny] = ttmp;
			}
		}
	}
}
void solve(int i) {
	switch (arr[i][0]) {

	case 'U': //À­¸é
		if (arr[i][1] == '-') {//¹Ý½Ã°è
			for (int j = 0; j < 3; j++) temp[0][j] = b[0][j];
			for (int j = 0; j < 3; j++) b[0][j] = r[0][j];
			for (int j = 0; j < 3; j++) r[0][j] = f[0][j];
			for (int j = 0; j < 3; j++) f[0][j] = l[0][j];
			for (int j = 0; j < 3; j++) l[0][j] = temp[0][j];
			goClock(false);
			
		}
		else if (arr[i][1] == '+') { //½Ã°è
			for (int j = 0; j < 3; j++) temp[0][j] = l[0][j];
			for (int j = 0; j < 3; j++) l[0][j] = f[0][j];
			for (int j = 0; j < 3; j++) f[0][j] = r[0][j];
			for (int j = 0; j < 3; j++) r[0][j] = b[0][j];
			for (int j = 0; j < 3; j++) b[0][j] = temp[0][j];
			goClock(true);
		
		}
		break;

	case 'D': //¾Æ·§ ¸é
		if (arr[i][1] == '-') {
			for (int j = 0; j < 3; j++) temp[2][j] = b[2][j];
			for (int j = 0; j < 3; j++) b[2][j] = r[2][j];
			for (int j = 0; j < 3; j++) r[2][j] = f[2][j];
			for (int j = 0; j < 3; j++) f[2][j] = l[2][j];
			for (int j = 0; j < 3; j++) l[2][j] = temp[2][j];
			goClock(false);
		}
		else if (arr[i][1] == '+') {
			for (int j = 0; j < 3; j++) temp[2][j] = l[2][j];
			for (int j = 0; j < 3; j++) l[2][j] = f[2][j];
			for (int j = 0; j < 3; j++) f[2][j] = r[2][j];
			for (int j = 0; j < 3; j++) r[2][j] = b[2][j];
			for (int j = 0; j < 3; j++) b[2][j] = temp[2][j];
			goClock(true);
		}
		break;

	case 'F'://¾Õ¸é
		if (arr[i][1] == '-') {
		
			goClock(false);
		}
		else if (arr[i][1] == '+') {

			goClock(true);
		}
		break;

	case 'B'://µÞ¸é
		if (arr[i][1] == '-') {

			goClock(false);
		}
		else if (arr[i][1] == '+') {
			goClock(true);
		}
		break;

	case 'L': //¿ÞÂÊ¸é
		if (arr[i][1] == '-') {
			goClock(false);
		}
		else if (arr[i][1] == '+') {
			goClock(true);
		}
		break;

	case 'R': //¿À¸¥ÂÊ¸é
		if (arr[i][1] == '-') {
			goClock(false);
		}
		else if (arr[i][1] == '+') {
			goClock(true);
		}
		break;

	}
}
int main() {
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		scanf("%d", &N);
		for (int i = 0; i < 1001; i++) {
			arr[i][0] = '0';
			arr[i][1] = '0';
		}
		clock[0][0] = 0; clock[0][1] = 0; clock[0][2] = 0; clock[0][3] = 1; clock[0][4] = 2; clock[0][5] = 2; clock[0][6] = 2; clock[0][7] = 1;
		clock[1][0] = 0; clock[1][1] = 1; clock[1][2] = 2; clock[1][3] = 2; clock[1][4] = 2; clock[1][5] = 1; clock[1][6] = 0; clock[1][7] = 0;

		
		for (int i = 0; i < N; i++) {
			scanf("%s", &arr[i]);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				u[i][j] = 'w', d[i][j] = 'y', f[i][j] = 'r';
				b[i][j] = 'o', l[i][j] = 'g', r[i][j] = 'b';
			}
		}

		for (int i = 0; i < N; i++) {
			solve(i);
		}

	}




}