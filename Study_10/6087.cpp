//
//  6087.cpp
//  Project
//  레이저 통신
//

#include<iostream>
#include<queue>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;
char temp[102][102];
int map[102][102];
int visited[4][102][102];
vector < pair < int, int > > laser;
int ans;
int w, h;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
queue < pair < int, pair < int, int >  > > q;

void solve() {
	while (!q.empty()) {
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int dir = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
				if (map[nx][ny] != 1) {
					int &t1 = visited[i][nx][ny], t2 = visited[dir][cx][cy];

					if (t1 && t1 <= t2) 
						continue;
					
				/*	if (visited[i][nx][ny] != 0 && visited[i][nx][ny] <= visited[dir][cx][cy]) continue;
					visited[i][nx][ny] = visited[dir][cx][cy] + 1;
					if (dir == i) visited[i][nx][ny]--;*/
					//이것도 가능 

					t1 = t2 + 1;
					if (dir == i) t1--;
					q.push(make_pair(i, make_pair(nx, ny)));

				}

			}
		}

	}
}
int main() {
	cin >> w >> h;
	laser.clear();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> temp[j][i];
			if (temp[j][i] == '*') {
				map[j][i] = 1;
			}
			else if (temp[j][i] == '.') {
				map[j][i] = 0;
			}
			else if (temp[j][i] == 'C') {
				map[j][i] = 2;
				laser.push_back(make_pair(j, i));
			}
		}
	}
	ans = INF;
	int a; int b;
	a = laser[1].first;
	b = laser[1].second;
	for (int i = 0; i < 4; i++) {
		visited[i][(laser[0].first)][(laser[0].second)] = 1;
		q.push(make_pair(i, make_pair((laser[0].first), (laser[0].second))));
	}

	solve();

	for (int i = 0; i < 4; i++) {
		int res = visited[i][a][b];
		if (!res) continue;
		if (res < ans)
			ans = res;
	}
	cout << ans - 1 << endl;
}
