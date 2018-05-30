#include <iostream>	
#include<queue>

using namespace std;

int n;

int map[101][101];
int visited[101][101];
int dx[] = { -1,0,1,0 };    
int dy[] = { 0,-1,0,1 };

queue < pair<int, int > > q;

void bfs(int i, int j, int h) {
	q.push(make_pair(i, j));
	visited[i][j] = 1;
	int heigh = h;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= n && ny > 0 && ny <= n) {
				if (visited[nx][ny] == 0 && map[nx][ny] > heigh) {
					visited[nx][ny] = 1;
					bfs(nx, ny, heigh);
				}
			}
		}

	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;

	for (int h = 0; h <= 100; h++) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				visited[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > h && visited[i][j] == 0) {
					count++;
					bfs(i, j, h);
				} //if
			} //for j
		}//for i } // for h

	// 최댓값 구하기
		if (result < count) {
			result = count;
		}

	}//for h
	cout << result;

	return 0;
	}
