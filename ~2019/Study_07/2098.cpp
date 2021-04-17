//외판원 순회 2098번 //비트마스크?연산자?
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_SIZE 16
#define INF 987654321

int edge[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][1 << MAX_SIZE];
int n, MIN;

int dfs(int city, int state) {

	if (state == ((1 << n) - 1)) {

		if (edge[city][0] != 0) return edge[city][0];
		else return INF;
	}

	if (dp[city][state] != 0) return dp[city][state];

	dp[city][state] = INF;

	for (int i = 0; i < n; i++) {

		if ((state & (1 << i)) == 0 && edge[city][i] != 0) {
			dp[city][state] = min(dp[city][state], dfs(i, state | (1 << i)) + edge[city][i]);
		}
	}

	return dp[city][state];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> edge[i][j];
		}
	}

	MIN = INF;

	cout << dfs(0, 1 << 0);

	return 0;
}