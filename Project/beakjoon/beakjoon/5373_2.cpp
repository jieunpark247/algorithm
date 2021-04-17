#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

//위아래앞뒤왼오'
///UDFBLR
int cube[6][3][3];
char color[6] = { 'w','y','r','o','g','b' };
int tc, n; char cmd, area;

void change(int _area, char dir) {	
	if (dir == '+') {
		int ncube[3][3] = {
			{cube[_area][2][0],cube[_area][1][0],cube[_area][0][0]},
			{cube[_area][2][1],cube[_area][1][1],cube[_area][0][1]},
			{cube[_area][2][2],cube[_area][1][2],cube[_area][0][2]}
		};
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cube[_area][i][j] = ncube[i][j];
	}
	else {
		int ncube[3][3] = {
			{cube[_area][0][2],cube[_area][1][2],cube[_area][2][2]},
			{cube[_area][0][1],cube[_area][1][1],cube[_area][2][1]},
			{cube[_area][0][0],cube[_area][1][0],cube[_area][2][0]}
		};
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cube[_area][i][j] = ncube[i][j];
	}
}

void change2(int& v1, int& v2, int& v3, int& v4, int& v5, int& v6, int& v7, int& v8, int& v9, int& v10, int& v11, int& v12, char dir) {
	if (dir = '+') {
		int temp[3] = { v1, v2, v3 };
		v1 = v4, v2 = v5, v3 = v6;
		v4 = v7, v5 = v8, v6 = v9;
		v7 = v10, v8 = v11, v9 = v12;
		v10 = temp[0], v11 = temp[1], v12 = temp[2];
	}
	else {
		int temp[3] = { v1, v2, v3 };
		v1 = v10, v2 = v11, v3 = v12;
		v10 = v7, v11 = v8, v12 = v9;
		v7 = v4, v8 = v5, v9 = v6;
		v4 = temp[0], v5 = temp[1], v6 = temp[2];
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++) 
				for (int k = 0; k < 3; k++) 
					cube[i][j][k] = color[i];
		scanf("%d", &n);
		while (n--) {
			scanf(" %c %c", &area, &cmd);
			//위아래앞뒤왼오'
			///UDFBLR
			switch (area) {
			case 'U':
				change(0, cmd);
				change2(
					cube[2][0][0],cube[2][0][1],cube[2][0][2],
					cube[4][0][0],cube[4][0][1],cube[4][0][2],
					cube[3][0][0],cube[3][0][1],cube[3][0][2],
					cube[5][0][0],cube[5][0][1],cube[5][0][2],
					cmd);
				break;
			case 'D':
				change(1, cmd);
				change2(
					cube[2][2][0], cube[2][2][1], cube[2][2][2],
					cube[4][2][0], cube[4][2][1], cube[4][2][2],
					cube[3][2][0], cube[3][2][1], cube[3][2][2],
					cube[5][2][0], cube[5][2][1], cube[5][2][2],
					cmd);
				break;
			case 'F':
				change(2, cmd);
				change2(
					cube[0][2][0], cube[0][2][1], cube[0][2][2],
					cube[5][0][0], cube[5][1][0], cube[5][2][0],
					cube[1][2][0], cube[1][2][1], cube[1][2][2],
					cube[4][2][2], cube[4][1][2], cube[4][0][2],
					cmd);
				break;
			case 'B':
				change(3, cmd);
				change2(
					cube[0][0][2], cube[0][0][1], cube[0][0][0],
					cube[4][0][0], cube[4][1][0], cube[4][2][0],
					cube[1][0][2], cube[1][0][1], cube[1][0][0],
					cube[5][2][2], cube[5][1][2], cube[5][0][2],
					cmd);
				break;
			case 'L':
				change(4, cmd);
				change2(
					cube[0][0][0], cube[0][1][0], cube[0][2][0],
					cube[2][0][0], cube[2][1][0], cube[2][2][0],
					cube[1][2][2], cube[1][1][2], cube[1][0][2],
					cube[3][2][2], cube[3][1][2], cube[3][0][2],
					cmd);
				break;
			case 'R':
				change(5, cmd);
				change2(
					cube[0][2][2], cube[0][1][2], cube[0][0][2],
					cube[3][0][0], cube[3][1][0], cube[3][2][0],
					cube[1][0][0], cube[1][1][0], cube[1][2][0],
					cube[2][2][0], cube[2][1][0], cube[2][0][0],
					cmd);
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", cube[0][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}