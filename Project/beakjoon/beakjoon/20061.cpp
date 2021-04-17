#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;
int N;
int map[10][10];
int t, x, y;
int score;
vector<pair<int, int>> v;
void removeMove(int color, int line) {
	//블록라인 제거 후 아래/ 오른쪽으로 블록들 이동 
	for (int i = line; i > 3; i--) {
		if (i > 9) continue;
		for (int j = 0; j < 4; j++) {
			if (color == 0) {
				//green
				map[i][j] = map[i - 1][j];
			}
			else if (color == 1) {
				map[j][i] = map[j][i - 1];
			}
		}
	}
}
void move() {
	//맨처음 블록 생성될때 green blue로 이동 
	if (v.size() == 1) {
		int fx = v[0].first;
		int fy = v[0].second;
		map[fx][fy] = 0;
		for (int i = 0; i <= 10; i++) {
			if (fx + i == 10) {
				map[fx + i -1][fy] = 1;
				break;
			}else if (map[fx + i][fy] == 1) {
				//green 
				map[fx + i -1][fy] = 1;
				break;
			}
		}
		for (int i = 0; i <= 10; i++) {
			if (fy + i == 10) {
				map[fx][fy + i -1] = 1;
				break;
			}else if (map[fx][fy + i] == 1) {
				//blue 
				map[fx][fy + i -1] = 1;
				break;
			}
		}
	}else {
		int fx = v[0].first; int fy = v[0].second;
		int sx = v[1].first; int sy = v[1].second;
		map[fx][fy] = 0; map[sx][sy] = 0;

		for (int i = 0; i <= 10; i++) {
			if (fx + i == 10 || sx + i == 10) {
				map[fx + i - 1][fy] = 1;
				map[sx + i - 1][sy] = 1;
				break;
			}
			else if (map[fx + i][fy] == 1 || map[sx + i][sy] == 1) {
				//green 
				map[fx + i - 1][fy] = 1;
				map[sx + i - 1][sy] = 1;
				break;
			}
		}
		for (int i = 0; i <= 10; i++) {
			if (fy + i == 10 || sy + i == 10) {
				map[fx][fy + i -1] = 1;
				map[sx][sy + i -1] = 1;
				break;
			}else if (map[fx][fy + i] == 1 || map[sx][sy + i] == 1) {
				//blue 
				map[fx][fy + i -1] = 1;
				map[sx][sy + i -1] = 1;
				break;
			}
		}
	}
}

void removeLine() {
	//다완성된 블록라인 제거
	int gcnt,bcnt = 0;
	for (int i = 6; i < 10; i++) {
			gcnt = bcnt = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) {
			//green 
				gcnt++;
			}
			if (map[j][i] == 1) {
			//blue 
				bcnt++;
			}
		}
		if (gcnt == 4 || bcnt == 4) {
			if(gcnt == 4) score++;
			if (bcnt == 4) score++;
			//모든 행 or 열이 다 채워졌으면?
			for (int j = 0; j < 4; j++) {
				if (gcnt == 4) map[i][j] = 0;
				else if (bcnt == 4) map[j][i] = 0;
			}
			if(gcnt == 4) 	removeMove(0, i);
			else 	removeMove(1, i);
		}
	}
}
void moveSpecialArea() {
	//4,5,라인에 있는 경우 1,2줄씩 밀기 
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j < 6; j++) {
			if (map[j][i] == 1) {
				if (j == 4) {
					removeMove(0, 10);
				}
				else if (j == 5) {
					removeMove(0, 10);
				}
			}
			else if (map[i][j] == 1) {
				if (j == 4) {
					removeMove(1, 10);
				}
				else if (j == 5) {
					removeMove(1, 10);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	score = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &t, &x, &y);
		v.clear();
		if (t == 1) {
			map[x][y] = 1;
			v.push_back({ x,y });
		}
		else if (t == 2) {
			map[x][y] = map[x][y + 1] = 1;
			v.push_back({ x,y });
			v.push_back({ x,y + 1 });
		}
		else if (t == 3) {
			map[x][y] = map[x + 1][y] = 1;
			v.push_back({ x,y });
			v.push_back({ x + 1,y });
		}
		move();
		removeLine();
		moveSpecialArea();
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j < 10; j++) {
			if (map[i][j] == 1) {
				sum++;
			}
			if (map[j][i] == 1) {
				sum++;
			}
		}
	}

	printf("%d\n", score);
	printf("%d", sum);
	return 0;
}