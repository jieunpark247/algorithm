#include<iostream> 
#include<queue>
#include<stdio.h>

using namespace std;

int n, m;
char map[10][11];
int dx[4] = { -1, 1, 0, 0 };/// �� �� �� ��
int dy[4] = { 0, 0, -1, 1 };
int fx, fy;
int frx, fry, fbx, fby;

struct node {
	int d, rx, ry, bx, by;
};

int main() {
	queue<node> q;

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin>> map[i][j];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R')
				frx = i, fry = j;
			else if (map[i][j] == 'B')
				fbx = i, fby = j;
			else if (map[i][j] == 'O')
				fx = i; fy = j;
		}
	} //RED BLUE O ��ǥ ���ؼ� ���� ������ �ִ´�. 

	q.push({0, frx, fry, fbx, fby });

	 int ans = -1; // ���з� �ʱ�ȭ ���ǿ� �ȸ����� ���б״�� ���

	while (!q.empty()) {

		int cnt = q.front().d;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by; //ť�� ���� red blue��ǥ�� cnt�� �־��ش�.
		q.pop();
	
		if (cnt == 10)
			break;
			//10�� �ѱ�� �� 
			
			for (int i = 0; i < 4; i++) { //�̵��Ѵ�.
		
			 //=========================================================
				int nrx = rx + dx[i]; //�������� 1 �̵��Ѵ�.
				int nry = ry + dy[i];
				int blue = 0;
				int rex = 0; //
				
				int rmove = 0; //r�� i�������� ������ �Ÿ�
			//	cout << "rx " << rx << "ry " << ry<<'\n';
				while (map[nrx][nry]!='#') { //�������� #�� �ƴҶ����� ����
					//cout << nrx << " " << nry << '\n';
					rmove++;
				
					if (nrx == bx && nry == by)
						blue = rmove;
						

					if (map[nrx][nry] == 'O') 				
						rex = rmove;
						
						
					nrx += dx[i];  //�� �ƴϸ� ������������ ��ĭ�� �̵��Ѵ�. 
					nry += dy[i];
					
				}//R�� �����̰��ִµ� B�� �տ� ������
			

				int nbx = bx + dx[i]; //�������� 1 �̵��Ѵ�.
				int nby = by + dy[i];
				bool red = false;
				bool bex = false; //???
				int bmove = 0; //r�� i�������� ������ �Ÿ�

				while (map[nbx][nby] != '#') { //�������� #�� �ƴҶ����� ����
					bmove++;
					if (nbx == rx && nby == ry)
						red = true;

					if (map[nbx][nby] == 'O')
						bex = true;
					nbx += dx[i];  //�� �ƴϸ� ������������ ��ĭ�� �̵��Ѵ�. 
					nby += dy[i];
				}//B�� �����̰��ִµ� R�� �տ� ������
				 //========================================================= ������ �Ÿ����ϱ�

				if (!red&&!blue) { //������ �������� �ʴٸ�?
				
					if (rex) {//�������� �����־�
						//o�� ����������
						
						ans = cnt + 1;			
						goto print;
					}
					else if (bex) {
						continue;
					}
					else {
					q.push({ cnt + 1, rx + dx[i] * rmove, ry + dy[i] * rmove, bx + dx[i] * bmove, by + dy[i] * bmove });
					}

				}
				else if (blue) { //R�� �����̰��ִµ� B�� �տ� ������
					//B�� R���̿� ������ �־���Ѵ�.
					if (rex) { //�������� �����־�
						if (rex < blue) { // R->0 ���µ� �����ΰ� < R->B�ΰ��µ� �����ΰ�  �ᱹ R0B���϶� ����!
							ans = cnt + 1;
							goto print;
						}

						continue;
					}
					else { //�������� ���۾���
				
						rmove--;
						q.push({ cnt + 1, rx + dx[i] * rmove, ry + dy[i] * rmove, bx + dx[i] * bmove, by + dy[i] * bmove });

					}
				}
				else { //B�� �����̰��ִµ� R�� �տ� ������
					if (rex) { //������ �� ������ �ִٸ� ���� R�� B�� ���� �������� ������ ���� ����!
						continue;
					}
					else { //�ƴϸ� ������ ���� �Ʒ� �ִٸ� bmove�Ÿ���ŭ �������ְ� (���� �ٽ� �ö�) ������ȯ 
						bmove--; 
						
						q.push({ cnt + 1, rx + dx[i] * rmove, ry + dy[i] * rmove, bx + dx[i] * bmove, by + dy[i] * bmove });

					}
				}

			}//for
	}//while(empty)

print:
	printf("%d\n", ans);
	return 0;
}//main