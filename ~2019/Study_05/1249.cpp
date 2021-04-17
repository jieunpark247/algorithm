//1249 ���޷�
//using ���ͽ�Ʈ��
#include<iostream>
#include<queue>
#define MAX 987654321;

using namespace std;
int n;
int map[101][101];
int map2[101][101];
int dx[] = {0,-1 ,1,0 }; // �� �� �� ��
int dy[] = {-1,0, 0,1 };
queue < pair < pair < int, int >, int> > q;

void init_map() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			map[i][j] = 0;
}
void init_map2() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			map2[i][j] = MAX;
}


void solve() { //�밢�� �������� ���鼭 ���ڸ� ���س��� , ��ġ�� �κ��� �� �������� �������

	q.push(make_pair(make_pair(0, 0), 0)); 


	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int cur_time = q.front().second;

		q.pop();
		if (cur_time > map2[x][y])
			continue;

	

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int time = map[nx][ny];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (cur_time+time<map2[nx][ny]) { //map2�� �ִ� ���� curtime + time ���� ũ��? curtime+time�� ����ִ´�.
					map2[nx][ny] = cur_time + time; //map2���� ���ݱ��� �ð��� + map�� �ִ� �ð��� ���Ѱ��� ����ִ´�.
					q.push(make_pair(make_pair(nx, ny), map2[nx][ny])); //push �ض�

				}
			}
		}//for
	}//while
}


int main() {
	int testcase;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {

		init_map();

		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf_s("%1d", &map[i][j]);

		init_map2();
		solve();
		cout << "#" << t << " " << map2[n-1][n-1] << endl;



	}
	return 0;
}