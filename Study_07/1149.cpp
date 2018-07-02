#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[1000][3];
int tmp[1000][3];
int tt;
int min_, col;
int ans;
int sum;
void solve(int col) {
	if (sum > ans)
		return;
	if (col >= n) {
		if (tt < ans) ans = tt;
		return;
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				tt = tmp[col][i] + map[col + 1][j];

				if (tt < tmp[col + 1][j])
					tmp[col + 1][j] = tt;
			}


		}
	}
			sum = 987654321;
			for (int ii = 0; ii < 3; ii++) {
				sum = min(tmp[col + 1][ii], sum); //맨마지막줄에 최솟값 구하기
			}


	solve(col + 1);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] = 10001;

	for (int i = 0; i < 3; i++) {
		tmp[0][i] = map[0][i];
	}


	ans = 987654321;
	solve(0);

	for (int i = 0; i < 3; i++) {
		ans = min(tmp[n - 1][i], ans); //맨마지막줄에 최솟값 구하기
	}

	cout << ans;

	return 0;
}