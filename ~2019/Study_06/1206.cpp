#include<iostream>

using namespace std;
int h; //�ǹ� ����
int w; //���α���
int map[1001][256];
int visited[1001][256];
int cnt;
void init_map() {
	 	for (int i = 0; i < 1001; i++)
			for (int j = 0; j < 256; j++)
				map[i][j] = 0;
	
}
void init_visited() {
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 256; j++)
			visited[i][j] = 0;

}

void solve() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 256; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) { //map[][]���� 1�̰� �湮����������
				if (map[i - 1][j] == 0 && map[i - 2][j] == 0 && map[i + 1][j] == 0 && map[i + 2][j] == 0) { //map�� 2��ŭ �������ִ� ������ �� 0 �̸�
					cnt++;			// ������ ���ش�.
					visited[i][j]=1; //�湮ǥ��!
				}
			}

		}
	}

}

int main() {


	for (int t = 1; t <= 10; t++)
	{
		init_map();
		cin >> w;
		for (int i = 0; i < w; i++) {  //w��ŭ ���� 
			cin >> h;					//���̸� �Է��ϰ�
			for (int j = 0; j < h; j++) { // ���̸�ŭ 1���� �ٲ��ش�.
				map[i][j] = 1;
				
			}
		}
		cnt = 0;	
		init_visited();
		solve();


	
		cout << "#" << t << " "  <<cnt<< endl;

	}
	return 0;
}