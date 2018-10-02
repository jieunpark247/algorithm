//테트로미노
#include <iostream>
#include<vector>
#include <string.h>

#define max(a,b) (a>b ? a:b)
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int map[501][501];
int visited[501][501];
int n, m;
int ans;
int ans2;
int MaxValue() {
	return max(ans, ans2);
}
void solve(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		ans = max(sum, ans);
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (visited[nx][ny] == 0) {
				sum = sum + map[nx][ny];
				solve(nx, ny, sum,cnt+1);
				sum = sum - map[nx][ny];
			}
		}
	}

}
void shape(int x, int y,int sum, int cnt) {
	if (y - 1 >= 0 && y + 1 < m &&x - 1 >= 0) {
		sum = max(sum,map[x][y - 1] + map[x][y + 1] + map[x - 1][y]);
	}

	if (y - 1 >= 0 && y + 1 < m &&x + 1 < n) {
		sum = max(sum, map[x][y-1] + map[x][y + 1] + map[x + 1][y]);
	}

	if (x - 1 >= 0 && x + 1 < n &&y - 1 >= 0) {
		sum = max(sum, map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
	}

	if (x - 1 >= 0 && x + 1 < n &&y + 1 < m) {
		sum = max(sum, map[x - 1][y] + map[x + 1][y] + map[x][y + 1]);
	}

	ans2 = max(sum, ans);

}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			solve(i, j, 0, 0);

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			shape(i, j, 0, 0);

		}
	}
	cout << MaxValue() << endl;
}
