#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm> // max min 값은 사용할때 

using namespace std;

enum { PATH = 1 }; //방문할 수 있는지 아닌지 알아내는값 || 0이면 방문x 1이면 가능 

int N, M;
int map[100][100];
bool visited[100][100];
queue < pair < pair < int, int >, int > > q;   //pair란 값 2개의 쌍인데 서로 다른 자료형의 값 2개를 한꺼번에 저장함
int dx[] = { -1,0,1,0 }; //이동할 때 쓰는 x 좌표
int dy[] = { 0,-1,0,1 }; //이동할 때 쓰는 y 좌표
						 // -1,0 -> 왼쪽 || 0,-1 -> 아래쪽 || 1,0 -> 오른쪽 || 0,1 -> 아래쪽
int Answer; // 가는길의 min 값을 추출할때 사용하는 변수

void Init_map() {
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			map[i][j] = false;

}
void Init_visited() {
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			visited[i][j] = false;

}
void solve() {

	q.push(make_pair(make_pair(0, 0), 1)); //  0,0 cnt =1 값만들기
	visited[0][0] = true;

	while (!q.empty()) {
		int cur_x = q.front().first.first; //x값
		int cur_y = q.front().first.second; //y값
		int cur_cnt = q.front().second;		//이동횟수 visited할때마다 +1
		q.pop();

		if (cur_x == N - 1 && cur_y == M - 1) {
			Answer = min(cur_cnt, Answer);
			continue;
		}

		for (int i = 0; i<4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if (!visited[new_x][new_y] && map[new_x][new_y] == PATH &&
				new_x >= 0 && new_y >= 0 && new_x<N&&new_y<M) {

				q.push(make_pair(make_pair(new_x, new_y), cur_cnt + 1));
				visited[new_x][new_y] = true;
			}
		}
	}
}

int main() {
	Answer = 987654321;
	scanf("%d %d", &N, &M);
	Init_map();
	Init_visited();
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			scanf("%1d", &map[i][j]);
	solve();
	printf("%d", Answer);


	return 0;
}

