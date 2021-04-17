#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm> // max min ���� ����Ҷ� 

using namespace std;

enum { PATH = 1 }; //�湮�� �� �ִ��� �ƴ��� �˾Ƴ��°� || 0�̸� �湮x 1�̸� ���� 

int N, M;
int map[100][100];
bool visited[100][100];
queue < pair < pair < int, int >, int > > q;   //pair�� �� 2���� ���ε� ���� �ٸ� �ڷ����� �� 2���� �Ѳ����� ������
int dx[] = { -1,0,1,0 }; //�̵��� �� ���� x ��ǥ
int dy[] = { 0,-1,0,1 }; //�̵��� �� ���� y ��ǥ
						 // -1,0 -> ���� || 0,-1 -> �Ʒ��� || 1,0 -> ������ || 0,1 -> �Ʒ���
int Answer; // ���±��� min ���� �����Ҷ� ����ϴ� ����

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

	q.push(make_pair(make_pair(0, 0), 1)); //  0,0 cnt =1 �������
	visited[0][0] = true;

	while (!q.empty()) {
		int cur_x = q.front().first.first; //x��
		int cur_y = q.front().first.second; //y��
		int cur_cnt = q.front().second;		//�̵�Ƚ�� visited�Ҷ����� +1
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

