#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n;
//int cnt;
int visited[101][101];
char map[101][101];
int count[10001];
queue < pair < int, int > > q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void BFS(int a, int b, int cnt) {
	visited[a][b] = 1;
	::count[cnt]++;
	//q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n)
				if (nx >= 0 && nx < n &&ny >= 0 && ny < n) {
					if (visited[nx][ny] == 0 && map[nx][ny] == map[x][y]) //map이동값이 현재값과 같다면?
					{
						visited[nx][ny] = 1;
						::count[cnt]++; // 몆번 인지 cnt별로 셈 
						q.push(make_pair(nx, ny));
					}
				}
		} // 한번 위아래 양옆 세트로 갈수 있음  
		
	}

}
int main() {
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((map[i][j] == 'R'|| map[i][j] == 'G'|| map[i][j] == 'B') && visited[i][j] == 0) {
				q.push(make_pair(i, j));
				cnt++;	//전체 모임 갯수 세기
				BFS(i, j, cnt);
			}
		}
	} //너는 i j 전체 다돌림 모든 좌표 다돌림 bfs 한번 돌면 cnt에서 +1씩 해줌 전체 몇번 돌았는지 알 수 있다. 

	cout << cnt << '\n'; 
	//일반인

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') && visited[i][j] == 0) {
				q.push(make_pair(i, j));
				cnt++;	//전체 모임 갯수 세기
				BFS(i, j, cnt);
			}
		}
	}

	cout << cnt << '\n';



	int temp;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j + 1 < cnt; j++) {
			if (::count[j] > ::count[j + 1]) {
				temp = ::count[j];
				::count[j] = ::count[j + 1];
				::count[j + 1] = temp;
			}

		}
	}

	return 0;
}
