//
//  6087.cpp
//  Project
//  레이저 통신22
//

#include<iostream>
#include<queue>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;

char map[102][102];

int visit[102][102];
vector < pair < int, int > > laser;
int ans;
int w, h;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue < pair < pair < int, int>, pair < int, int >  > > q;

void solve() {
	while (!q.empty()) {
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int dir = q.front().first.first;
		int cnt = q.front().first.second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nc = cnt;
			if (nx >= 0 && ny >= 0 && nx < w && ny < h) {

				if (map[nx][ny] != '*') {
					int &t1 = visit[nx][ny];
					if (dir != i)  nc = nc + 1;
					if (t1 == -1 || t1 >= nc) {
						t1 = nc;
						q.push(make_pair(make_pair(i, nc), make_pair(nx, ny)));
					}


				}

			}
		}

	}
}
int main() {
	//	ios::sync_with_stdio(0);

	cin >> w >> h;
	laser.clear();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visit[j][i] = -1;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[j][i];
			 if (map[j][i] == 'C') {
				laser.push_back(make_pair(j, i));
			}
		}
	}

	ans = INF;
	int a; int b;
	a = laser[1].first;
	b = laser[1].second;
	visit[(laser[0].first)][(laser[0].second)] = 0;

	for (int i = 0; i < 4; i++)
		q.push(make_pair(make_pair(i, 0), make_pair((laser[0].first), (laser[0].second))));


	solve();

	int ans = visit[a][b];


	cout << ans << endl;
}
