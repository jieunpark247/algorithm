#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

int n, m;
int map[8][8], temp[8][8], visited[8][8];
int cnt,result;
vector < pair < int, int > > v;
vector < pair < int, int > > vzero;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
queue < pair < int, int > > q;



void bfs(int xx,int yy) { // 이동한값이 0이면 2로 바꿈
	
	
		q.push(make_pair(xx, yy));
		
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)//밭의 4방향 조사
			{

				int nx = x + dx[i];
				int ny = y + dy[i];


				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				
					if (temp[nx][ny] == 0 ) {
						
						q.push(make_pair(nx, ny));
						temp[nx][ny] = 2;
						visited[nx][ny] = 1;
						

					}
				}
			}
		}


	}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				v.push_back(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	} //map값이 2인값의 x y 좌표를 vector에 집어넣어라

	//==================================================
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (map[i][j] == 0 && visited[i][j] == 0) {
				vzero.push_back(make_pair(i, j));
			

			}
		}
	}// 0인좌표를 vector에 넣음

	//조합 map이 0 세개를 할 수 있는 xy좌표
	vector<int> ind;
	int k = 3;

	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < vzero.size() - k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());

	do { //조합 돌리기

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = map[i][j]; //임시 map만들기


		for (int i = 0; i < ind.size(); i++) {


			if (ind[i] == 1) {

				temp[vzero[i].first][vzero[i].second] = 1;

			}

		}
	
		
		
		for (int vv = 0; vv < v.size(); vv++) {
			bfs(v[vv].first, v[vv].second);
			//2로 다 바꾸기 
		}
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 0)
					cnt++;

			}
		} // 0인값의 갯수 구하기

		if (result < cnt)
			result = cnt;

	} //최댓값 구하기
	
while (next_permutation(ind.begin(), ind.end())); 


	cout << result << endl;

}