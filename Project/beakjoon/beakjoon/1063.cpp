//1063
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int kc, sc, kr, sr, N;
char c;
char a;
char arr[51][3];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };
int rex, rey, resx, resy;
int dirFlag;
//strcmp
void move(int kx, int ky, int sx, int sy, int num) {
	int nx = kx; int ny = ky; int snx = sx; int sny = sy;
	rex = kx, rey = ky, resx = sx, resy = sy;
	int x; int y;
	if (strcmp(arr[num], "R") == 0) {
		x = dx[0];
		y = dy[0];
	}
	else if (strcmp(arr[num], "L") == 0) {
		x = dx[2];
		y = dy[2];
	}
	else if (strcmp(arr[num], "B") == 0) {
		x = dx[1];
		y = dy[1];
	}
	else if (strcmp(arr[num], "T") == 0) {
		x = dx[3];
		y = dy[3];
	}
	else if (strcmp(arr[num], "RT") == 0) { //µ¿ºÏ
		x = dx[0] + dx[3];
		y = dy[0] + dy[3];
	}
	else if (strcmp(arr[num], "LT") == 0) { // ¼­ºÏ
		x = dx[2] + dx[3];
		y = dy[2] + dy[3];
	}
	else if (strcmp(arr[num], "RB") == 0) {//µ¿³²
		x = dx[0] + dx[1];
		y = dy[0] + dy[1];
	}
	else if (strcmp(arr[num], "LB") == 0) {//¼­³²
		x = dx[2] + dx[1];
		y = dy[2] + dy[1];
	}

	nx = kx + x;
	ny = ky + y;
	if (nx == sx && ny == sy) {
		snx = sx + x;
		sny = sy + y;
	}

	if (nx <= 0 || ny <= 0 || nx > 8 || ny > 8 || snx <= 0 || sny <= 0 || snx > 8 || sny > 8) {
		nx = kx; ny = ky;
		snx = sx, sny = sy;
	}

	resx = snx; resy = sny;
	rex = nx; rey = ny;

}
int main() {

	scanf("%c", &c);
	kc = c - 'A'+1;
	scanf("%1d", &kr);
	kr = kr;
	scanf(" %c", &c);
	sc = c - 'A'+1;
	scanf("%1d", &sr);
	sr =  sr ;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	rex = kr; rey = kc;
	resx = sr, resy = sc;
	for (int i = 0; i < N; i++) {
		move(rex, rey, resx, resy, i);
	}

	printf("%c", rey - 1 + 'A');
	printf("%d", rex);
	printf("\n");
	printf("%c", resy - 1 + 'A');
	printf("%d", resx);


}