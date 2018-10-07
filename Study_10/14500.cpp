//테트로미노
#include <iostream>
#include<vector>
#include <string.h>
#include<algorithm>
#define max(a,b) (a > b ? a:b)
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int map[502][502];
int visited[502][502];
int n, m;
int ans;
int ans2;
int MaxValue() {
	return max(ans, ans2);
}
void solve(int x, int y, int sum, int cnt) {
    
	if (cnt == 4) {
		ans = max(sum, ans);
        return;
	}
    visited[x][y]=1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (visited[nx][ny] == 0) {
				sum = sum + map[nx][ny];
                visited[nx][ny] = 1;
				solve(nx, ny, sum,cnt+1);
				sum = sum - map[nx][ny];
                visited[nx][ny]=0;
			}
		}
	}
    visited[x][y] = 0;
    //조심하기 !! (for문 돌아야 하니까 visited를 초기화 시켜야한다 값이 nx ny 는 다 0 인데 x,y는 0이 안되었으니 0으로 바꿔줌

}
void shape(int x, int y,int sum) {
	if (y - 1 >= 0 && y + 1 < m &&x - 1 >= 0) {
		sum = max(sum,map[x][y - 1] + map[x][y + 1] + map[x - 1][y]+map[x][y]);
	}

	if (y - 1 >= 0 && y + 1 < m && x + 1 < n) {
		sum = max(sum, map[x][y-1] + map[x][y + 1] + map[x + 1][y]+map[x][y]);
        
	}

	if (x - 1 >= 0 && x + 1 < n &&y - 1 >= 0) {
		sum = max(sum, map[x - 1][y] + map[x + 1][y] + map[x][y - 1]+map[x][y]);
	}

	if (x - 1 >= 0 && x + 1 < n &&y + 1 < m) {
		sum = max(sum, map[x - 1][y] + map[x + 1][y] + map[x][y + 1]+map[x][y]);
	}
    

	ans2 = max(sum, ans2);

}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		
			solve(i, j, 0, 0);
            shape(i, j, 0);
		}
	}



	cout << MaxValue() << endl;
}
