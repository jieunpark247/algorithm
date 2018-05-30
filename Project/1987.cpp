#include <iostream>	

using namespace std;

int r, c;
char map[21][21];
int visited[30];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int cnt = 1;

void dfs(int x, int y, int count) {
	if (cnt < count)
		cnt = count;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int new_num = map[nx][ny] - 'A' + 1; //
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (visited[new_num]!= 1&& new_num>0 )
			{
				visited[new_num] = 1;

				dfs(nx, ny, count+1);
				visited[new_num] = 0;
			}

		}
	}
}

	int main() {
	
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; i < c; j++) 
				cin >> map[i][j];
				
			
			
		
		int num = map[0][0] - 'A' + 1;
		
		visited[num] = 1;
		dfs(0, 0, cnt);
		cout << cnt;
		return 0;
	}