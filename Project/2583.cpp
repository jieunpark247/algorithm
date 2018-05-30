#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m,n,k;
//int cnt;
int visited[102][102];
bool map[102][102];

vector<int> v;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt;

void dfs(int x, int y) {


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

				if (nx >= 0 && nx < m &&ny >= 0 && ny < n) {
					if (!visited[nx][ny] && !map[nx][ny])
					{
						visited[nx][ny] = true;
			
					
						dfs(nx, ny);
						cnt++;
					}
				}
		} 
	}


int main() {

	cin >> m >> n >> k;
	while(k--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j <  x2; j++) {			
				map[i][j] = true;
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]&& !visited[i][j]) {
	
				visited[i][j] = true;
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);

			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}