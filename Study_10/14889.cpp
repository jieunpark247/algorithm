//��ŸƮ�� ��ũ
//14889
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n,m;
int k;
int map[51][51];
int map2[51][51];
vector < pair <int , pair < int, int > > > v;
queue  < pair <int, pair < int, int > > >  q;
queue   <int >  times;
int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 };
int ans;
int timecheck[51][51];
bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
void solve(int time) {

	//if (time == k)
	//	return;
	for (int i = 0; i < k; i++) {
		times.push(i);
	}
	//while (!times.empty()) {

	//	int time = times.front();
	//	times.pop();

		while (!q.empty()) {

			int num = q.front().first; // ��ȣ
			int x = q.front().second.first; //x��ǥ 
			int y = q.front().second.second; // y��ǥ

			q.pop();

			//�����¿� ����
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (map[nx][ny] == 0 && timecheck[nx][ny] == 0 && isRange(nx, ny)) {
						timecheck[nx][ny] = time;  //�� Ÿ�Ӷ��� ������
						map[nx][ny] = num;
						q.push(make_pair(map[nx][ny], make_pair(nx, ny)));
				
				}//�ϰ͵� ������ ?

				else if (map[nx][ny] < map[x][y] && timecheck[nx][ny] == time && isRange(nx, ny)) { // ���ö��?? 
					timecheck[nx][ny] = time;
					map[nx][ny] = num;
					q.push(make_pair(map[nx][ny], make_pair(nx, ny)));
				}//��ġ�� ����� ū�ͺ���


				//�̹� ���������� ���ڸ��� �Ѿ
			}

		}
		

	
//	}
	//	solve(time+1);

	

}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				map[i][j] = map2[i][j] = times[i][j] = 0; // init 

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				map2[i][j] = map[i][j];

			}
		}


		solve(0);
		ans = 0;
		
			//	if (map[i][j] >= 0)
			//		ans++;

		cout <<"#"<< t << " " << ans << endl;

	}
}