#include <iostream>	

using namespace std;

int n, m, u, w;
bool map[1001][1001];
bool visited[1001];
int cnt;
void dfs(int x) {
	visited[x] = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && map[x][i]) {
			dfs(i);
		}
	}



}
int main() {
	int cnt = 0;
	cin>> n>> m;
	for (int i = 0; i < m; i++) {
		cin >> u >>  w;
		map[u][w] = map[w][u] = 1;
	}

	for (int i = 1; i <= n; i++) {

		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	
	}
	cout << cnt;


}