//puyopuyo
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
char map[13][7];
int visited[13][17];
int flag; //flag 0 > 더이상 터질것 없음  1 : 터질것 있음 
int cnt;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int flagBom;
vector<char> v;
vector<pair<int, int>> loc;
int num;
void down() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[j][i] != '.') {
				v.push_back(map[j][i]);
				map[j][i] = '.';
			}
		}
		int col = 11;
		for (int z = v.size() - 1; z >= 0; z--) {
			map[col][i] = v[z];
			col--;
		}

		v.clear();
	}
}
void bom(char color,int x, int y) {
	loc.push_back(make_pair(x, y));
	if (num == 4) {
		//cnt++;
		flagBom = 1;
		flag = 1;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];	
		if (map[nx][ny] == color && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			num = num + 1;
			bom(color, nx, ny);
		}

	}

}
int main() {
	for (int i = 0; i < 12; i++) {
			scanf("%s",&map[i]);
		for(int j = 0; j < 6; j++) {
		}
	}
	flag = 1;
	cnt = 0;

	while (1) {
	
		flag = 0;

		while (1) {
			flagBom = 0;
			memset(visited, 0, sizeof(visited));
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (map[i][j] != '.' && visited[i][j] == 0) {
						flagBom = 0;
						visited[i][j] = 1;
						bom(map[i][j], i, j);
						if (flagBom == 1) {
							for (int a = 0; a < loc.size(); a++) {
								map[loc[a].first][loc[a].second] = '.';
							}
						}
						num = 1;
						loc.clear();
					}
				}
			}
			if (flagBom == 0) break;
		}
		if (flag == 0) break;
		cnt++;
		down();
	}

	printf("%d", cnt);
}