#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
int map[101][101][3];
int R, C, M, Sh, r, c, s, d, z;
int res;
//0 속력 , d 이동방향 , z 크기  
struct sha{
	int ns, nd, nz;
};
sha temp[101][101];
void move(int x, int y, int dir, int sp) {
	//이동 
	int ss, dd, zz;
	ss = map[x][y][0];
	dd = map[x][y][1];
	zz = map[x][y][2];

	int ny = y + dy[dir] * sp;
	int nx = x + dx[dir] * sp;

	if (dir == 1) {
		if (x - 1 < sp) {
			int mv = (sp - (x - 1));
			int da = mv / (R - 1);
			int moveSt = mv % (R - 1);

			if (da % 2 == 0) {
				nx = 1 + moveSt;
				dd = 2;
			}
			else {
				nx = R - moveSt;
			}
		}
	}
	else if (dir == 2) {
		if (R - x < sp) {
			int mv = (sp - (R - x));
			int da = mv / (R - 1);
			int moveSt = mv % (R - 1);

			if (da % 2 == 0) {
				nx = R - moveSt;
				dd = 1;
			}
			else {
				nx = 1 + moveSt;
			}
		}
	}
	else if (dir == 3 ) {
		if (C - y < sp) {
			int mv = (sp - (C - y));
			int da = mv / (C - 1);
			int moveSt = mv % (C - 1);

			if (da % 2 == 0) {
				ny = C - moveSt;
				dd = 4;				
			}
			else {
				ny = 1 + moveSt;
			}
		}
	}
	else {
		if (y-1 < sp) {
			int mv = (sp - (y - 1));
			int da = mv / (C - 1);
			int moveSt = mv % (C - 1);

			if (da % 2 == 0) {
				ny = 1 + moveSt;
				dd = 3;
			}
			else {
				ny = C - moveSt;
			}
		}
	}


	if (temp[nx][ny].nd != 0) {
		if (temp[nx][ny].nz > map[x][y][2]) {
			return;
		}
	}

	temp[nx][ny].ns = ss;
	temp[nx][ny].nd = dd;
	temp[nx][ny].nz = zz;

	map[x][y][0] = 0;
	map[x][y][1] = 0;
	map[x][y][2] = 0;


}
void fishing(int ps) {
	for (int i = 1; i <= R; i++) {
		if (map[i][ps][1] != 0) {
			res += map[i][ps][2];
			map[i][ps][0] = 0;
			map[i][ps][1] = 0;
			map[i][ps][2] = 0;
			break;
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j][1] != 0 ) {
				move(i,j,map[i][j][1], map[i][j][0]);
			}
		}
	}


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j][0] = temp[i][j].ns;
			map[i][j][1] = temp[i][j].nd;
			map[i][j][2] = temp[i][j].nz;
		}
	}
}

int main() {
	scanf(" %d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		scanf(" %d %d %d %d %d",&r,&c, &s, &d, &z);
		map[r][c][0] = s;
		map[r][c][1] = d;
		map[r][c][2] = z;
	}
	res = 0;

	for (int i = 1; i <= C; i++) {
		memset(temp, 0, sizeof(temp));
		fishing(i);
	}

	printf("%d", res);
}