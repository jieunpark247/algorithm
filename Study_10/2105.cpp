//디저트 카페 again
//2105
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
int ans, res;
int n;
int map[21][21], check[21][21];
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
int same[4];//가로 세로 같게
int ch[101];
int dircnt;
int dirx[5];
int fx, fy; bool flag;

void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			check[j][i] = 0;
		}
	}
	for (int i = 0; i < 101; i++) {
		ch[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		same[i] = 0; dirx[i] = 0;
	}
}
void initmap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[j][i] = 0;

		}
	}
}
bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < n&&y < n;
}

void solve(int x, int y, int cnt, int dir) {
	//	check[x][y] = 0;

	if (x == fx && y == fy && cnt>1) { //처음 값과 같다면 리턴
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[j][i] == 1) {
					c++;
				}
			}
		}
		ans = max(c, ans);
		return;
	}
	if (!isRange(x, y))
		return;
	if (ch[map[x][y]] == 1)
		return;
	if (check[x][y] == 1)
		return;

	for (int i = dir; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		ch[map[x][y]] = 1; //중복 방지
		check[x][y] = 1;
		solve(nx, ny, cnt + 1, i);
		cnt = cnt - 1;
		check[x][y] = 0;
		ch[map[x][y]] = 0;

	}

}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		init(); initmap();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[j][i];
			}
		}
		ans = -1;
		dircnt = -1;
		flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				init();
				fx = j; fy = i;

				solve(j, i, 1, 0);

			}
		}

		cout << "#" << t << " " << ans << endl;
	}
}