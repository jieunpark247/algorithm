//14500 테트로미노
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<algorithm>	

using namespace std;

int N, M;
int map[501][501];
int visited[501][501];
int res;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ans;
int solveRes;
void dfs(int x, int y, int cnt, int val) {
	if (cnt == 4) {
		res = max(res, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visited[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx < N && ny < M) {
			visited[nx][ny] = 1;
			dfs(nx, ny, cnt + 1, val + map[nx][ny]);
			visited[nx][ny] = 0;
		}
	}

}

int solve(int x, int y) { // ㅗ 모양 
	//4가지 
	int res;
	if (x + 1 < N && y + 1 < M && y - 1 >= 0) {//ㅗ
		res = map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y + 1];
		solveRes = max(res, solveRes);
	}
	if (x + 2 < N && y + 1 < M) {//ㅏ
		res = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
		solveRes = max(res, solveRes);
	}
	if (x + 2 < N && y - 1 >= 0) {//ㅓ
		res = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1];
		solveRes = max(res, solveRes);
	}
	if (x - 1 >= 0 && y + 1 < M && y - 1 >= 0) {//ㅜ
		res = map[x][y] + map[x - 1][y] + map[x - 1][y - 1] + map[x - 1][y + 1];
		solveRes = max(res, solveRes);
	}

	return solveRes;

}
int main() {

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//for (int a = 0; a < i; a++) {
			//	for (int b = 0; b < M; b++) {
			//		visited[a][b] = 1;

			//	}
			//}
			visited[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			ans = max(ans, res);
			ans = max(ans, solve(i, j));
			//memset(visited, 0, sizeof(visited));
			visited[i][j] =0;
		}
	}

	printf("%d", ans);
	return 0;
}

