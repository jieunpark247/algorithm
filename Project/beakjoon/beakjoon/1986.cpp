#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int map[1002][1002];
int chess;
int x, y;
int cnt;
int dy[8] = { 1, 0, -1, 0, 1, -1,1,-1  };
int dx[8] = { 0, 1, 0, -1 ,1 ,-1, -1,1 };
queue <pair<int, pair<int, int > > > q;
vector < pair<int, int> > queen;
vector < pair<int, int> > knight;

void goknight(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i] * 2;
		int cy = y + dy[i] * 2;
		if (i % 2 == 0) {
			if (cx + dx[1] > 0 && cx + dx[1] <= N && cy + dy[1] >0 && cy + dy[1] <= M && map[cx + dx[1]][cy + dy[1]] == 0) {
				map[cx + dx[1]][cy + dy[1]] = 2;
			}
			if (cx + dx[3] > 0 && cx + dx[3] <= N && cy + dy[3] >0 && cy + dy[3] <= M && map[cx + dx[3]][cy + dy[3]] == 0) {
				map[cx + dx[3]][cy + dy[3]] = 2;
			}
		}
		else if (i % 2 == 1) {
			if (cx + dx[0] > 0 && cx + dx[0] <= N && cy + dy[0] > 0 && cy + dy[0] <= M && map[cx + dx[0]][cy + dy[0]] == 0) {
				map[cx + dx[0]][cy + dy[0]] = 2;
			}
			if (cx + dx[2] > 0 && cx + dx[2] <= N && cy + dy[2] > 0 && cy + dy[2] <= M && map[cx + dx[2]][cy + dy[2]] == 0) {
				map[cx + dx[2]][cy + dy[2]] = 2;
			}
		}
	}

}
void goqueen(int x,int y) {

	while (!q.empty()) {
		int dir  = q.front().first;
		int cx = q.front().second.first + dx[dir];
		int cy = q.front().second.second + dy[dir];
		q.pop();

		if (cx <= 0 || cy <= 0 || cx > N || cy > M || map[cx][cy] > 1) continue;

		map[cx][cy] = 1;
		q.push(make_pair(dir, make_pair(cx,cy)));

	}
		
		
	
}
int main() {
	scanf("%d%d", &N, &M);
	int nn = 1;
	for (int j = 0; j < 3; j++) {
		scanf("%d",&chess);
		for (int i = 0; i < chess; i++) {
			scanf("%d%d", &x, &y);
			map[x][y] = nn;
			if (nn == 1) {
				queen.push_back(make_pair(x, y));
			}
			else if (nn == 2) {
				knight.push_back(make_pair(x, y));
			}
		}
		nn = nn + 1;
	}
	

	for (int j = 0; j < queen.size(); j++) {
		for (int i = 0; i < 8; i++) {
			q.push(make_pair(i, make_pair(queen[j].first, queen[j].second)));
			goqueen(queen[j].first, queen[j].second);
		}
	}

	for (int i = 0; i < knight.size(); i++) {
		goknight(knight[i].first, knight[i].second);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}

	printf("%d",cnt);
	return 0;
}