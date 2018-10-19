//
// 2206.cpp
//  Project
//  벽부수고 이동하기

#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define INF 987654321
struct node {
	int nb, b; //안부숨,부숨
};
struct queueV {
	int x, y, cnt, flag;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
node visited[1001][1001];
//node map[11][11];
//int visited[11][11];
int map[1001][1001];
int n, m;
int ans;
queue <queueV> q;
bool isRange(int x, int y) {
	return x > 0 && y > 0 && x <= n&&y <= m;
}
void solve(int x, int y) {
	q.push({ x,y,1,0 });
	visited[1][1].b = 1; visited[1][1].nb = 1;
	while (!q.empty())
	{
		queueV qq = q.front();
		q.pop();
		if (qq.x == n && qq.y == m) {
			ans = min(ans, qq.cnt);
		}
		for (int i = 0; i < 4; i++) {
			int nx = qq.x + dx[i];
			int ny = qq.y + dy[i];

			if (isRange(nx, ny)) {
				if (qq.flag == 0 && map[nx][ny] == 0 && visited[nx][ny].nb == 0) {
					//벽 안부숨
					visited[nx][ny].nb = 1;
					q.push({ nx,ny,qq.cnt + 1,qq.flag });
				}
				else if (qq.flag == 0 && map[nx][ny] == 1 && visited[nx][ny].b == 0) {
					//벽부숴야해
					//map[nx][ny] = 0;
					visited[nx][ny].b = 1;
					q.push({ nx,ny,qq.cnt + 1,1 });
				}
				else if (qq.flag == 1 && map[nx][ny] == 0 && visited[nx][ny].b == 0) {
					//벽 부순후 

					visited[nx][ny].b = 1;
					q.push({ nx,ny,qq.cnt + 1,qq.flag });
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	ans = INF;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			visited[i][j].b = 0;
			visited[i][j].nb = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);

		}
	}

	solve(1, 1);

	if (ans == INF)
		ans = -1;

	cout << ans << endl;
}