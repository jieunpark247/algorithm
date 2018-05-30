#include<iostream> 
#include<queue>
#include<stdio.h>

using namespace std;

int n, m;
char map[10][11];
int dx[4] = { -1, 1, 0, 0 };/// 위 아 왼 오
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
	} //RED BLUE O 좌표 구해서 각각 변수에 넣는다. 

	q.push({0, frx, fry, fbx, fby });

	 int ans = -1; // 실패로 초기화 조건에 안맞으면 실패그대로 출력

	while (!q.empty()) {

		int cnt = q.front().d;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by; //큐에 각각 red blue좌표와 cnt를 넣어준다.
		q.pop();
	
		if (cnt == 10)
			break;
			//10번 넘기면 끝 
			
			for (int i = 0; i < 4; i++) { //이동한다.
		
			 //=========================================================
				int nrx = rx + dx[i]; //방향으로 1 이동한다.
				int nry = ry + dy[i];
				int blue = 0;
				int rex = 0; //
				
				int rmove = 0; //r이 i방향으로 움직인 거리
			//	cout << "rx " << rx << "ry " << ry<<'\n';
				while (map[nrx][nry]!='#') { //다음값이 #이 아닐때가지 돌림
					//cout << nrx << " " << nry << '\n';
					rmove++;
				
					if (nrx == bx && nry == by)
						blue = rmove;
						

					if (map[nrx][nry] == 'O') 				
						rex = rmove;
						
						
					nrx += dx[i];  //다 아니면 같은방향으로 한칸더 이동한다. 
					nry += dy[i];
					
				}//R이 움직이고있는데 B가 앞에 있을때
			

				int nbx = bx + dx[i]; //방향으로 1 이동한다.
				int nby = by + dy[i];
				bool red = false;
				bool bex = false; //???
				int bmove = 0; //r이 i방향으로 움직인 거리

				while (map[nbx][nby] != '#') { //다음값이 #이 아닐때가지 돌림
					bmove++;
					if (nbx == rx && nby == ry)
						red = true;

					if (map[nbx][nby] == 'O')
						bex = true;
					nbx += dx[i];  //다 아니면 같은방향으로 한칸더 이동한다. 
					nby += dy[i];
				}//B가 움직이고있는데 R이 앞에 있을때
				 //========================================================= 움직인 거리구하기

				if (!red&&!blue) { //직선상에 존재하지 않다면?
				
					if (rex) {//일직선에 구멍있어
						//o에 도달했을때
						
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
				else if (blue) { //R이 움직이고있는데 B가 앞에 있을때
					//B와 R사이에 구멍이 있어야한다.
					if (rex) { //일직선에 구멍있어
						if (rex < blue) { // R->0 가는데 움직인값 < R->B로가는데 움직인값  결국 R0B순일때 성공!
							ans = cnt + 1;
							goto print;
						}

						continue;
					}
					else { //일직선에 구멍없어
				
						rmove--;
						q.push({ cnt + 1, rx + dx[i] * rmove, ry + dy[i] * rmove, bx + dx[i] * bmove, by + dy[i] * bmove });

					}
				}
				else { //B이 움직이고있는데 R가 앞에 있을때
					if (rex) { //일직선 상에 구멍이 있다면 실패 R과 B가 같이 구멍으로 나오기 때문 실패!
						continue;
					}
					else { //아니면 구멍이 위나 아래 있다면 bmove거리만큼 움직여주고 (위로 다시 올라가) 방향전환 
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