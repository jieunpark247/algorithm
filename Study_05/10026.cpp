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
					if (visited[nx][ny] == 0 && map[nx][ny] == map[x][y]) //map�̵����� ���簪�� ���ٸ�?
					{
						visited[nx][ny] = 1;
						::count[cnt]++; // �p�� ���� cnt���� �� 
						q.push(make_pair(nx, ny));
					}
				}
		} // �ѹ� ���Ʒ� �翷 ��Ʈ�� ���� ����  
		
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
				cnt++;	//��ü ���� ���� ����
				BFS(i, j, cnt);
			}
		}
	} //�ʴ� i j ��ü �ٵ��� ��� ��ǥ �ٵ��� bfs �ѹ� ���� cnt���� +1�� ���� ��ü ��� ���Ҵ��� �� �� �ִ�. 

	cout << cnt << '\n'; 
	//�Ϲ���

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') && visited[i][j] == 0) {
				q.push(make_pair(i, j));
				cnt++;	//��ü ���� ���� ����
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
