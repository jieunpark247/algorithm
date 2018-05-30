#include <iostream>
#include <queue>

using namespace std;

int n, m,ans;
int visited[1001][1001];
int map[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	cin >> m >> n;
	queue < pair < int, int > > q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visited[i][j] = -1;

			if (map[i][j] == 1) {
				visited[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (map[nx][ny] == 0 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
				ans = visited[nx][ny];
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visited[i][j] == -1)
			{
				ans = -1;
			}
		}
	}

	cout << ans << endl;
}
