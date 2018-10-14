//
//  1261.cpp
//  Project
//  ¾Ë°í½ºÆÌ
// 
#include<iostream>
#include<queue>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
struct node {
	int x, y, cc;
};
#define MAX 987654321
int map[102][102];
int check[102][102];
int n, m;
int ans;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
queue<node> q;


void solve() {
	while (!q.empty()) {
		node v = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = v.x + dx[i];
			int ny = v.y + dy[i];
			int cnt = v.cc;
			int &after = check[nx][ny];

			if (nx <= n && ny <= m && nx > 0 && ny > 0) {
				if (map[nx][ny] == 1)
					cnt++;

				if (after && after <= cnt) {
					continue;
				}
				else {
					after = cnt;
					q.push({ nx,ny,cnt });
				}
			}
		}
	}
}


int main() {

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &map[j][i]);

	q.push({ 1 , 1 , 1 });
	check[1][1] = 1;

	solve();

	cout << check[n][m] - 1 << endl;
}