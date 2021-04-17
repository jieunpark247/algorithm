//마법사 상어와 파이어볼 
#include <iostream>
#include <vector>
using namespace std;
struct fireball {
	int m; int s; int d;
};
vector <fireball> map[55][55];
vector <fireball> temp[55][55];
int N, M, K, r, c, m, s, d;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void move() {
	//파이어볼 이동 
	vector <fireball> temp[55][55];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() > 0) {
				for (int z = 0; z < map[i][j].size(); z++) {
					int dir = map[i][j][z].d;
					int mass = map[i][j][z].m;
					int speed = map[i][j][z].s;
					int nx = ((i + dx[dir] * speed) + 1000*N) % N;
					int ny = ((j + dy[dir] * speed) + 1000*N) % N;
					temp[nx][ny].push_back({ mass,speed,dir });
				}
				map[i][j].erase(map[i][j].begin(), map[i][j].end());
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j].size() > 0) {
				for (int z = 0; z < temp[i][j].size(); z++) {
					map[i][j].push_back(temp[i][j][z]);
				}	
			}
		}
	}
}
void twoMore() {
	//하나로 합쳐짐 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int mass = 0; int speed = 0; int dir = 0;
			if (map[i][j].size() > 1) {
				for (int z = 0; z < map[i][j].size(); z++) {
					mass += map[i][j][z].m;
					speed += map[i][j][z].s;
					//dir = map[i][j][z].d;
					if (map[i][j][z].d % 2 == 0) {
						if (dir == 1 || dir == 3)  dir = 3;
						else dir = 2;
					}
					else {
						if (dir == 2 || dir == 3) dir = 3;
						else dir = 1;
					}
				}
				int sz = map[i][j].size();
				map[i][j].erase(map[i][j].begin(), map[i][j].end());
				//질량 속력 방향 4개 각각 넣음 
				for (int a = 0; a < 4; a++) {
					//질령 0x이면 소멸 
					if (mass / 5 > 0) {
						if (dir == 1 || dir == 2) {
							map[i][j].push_back({ mass / 5,speed / sz, a * 2 });
						}
						else {
							map[i][j].push_back({ mass / 5,speed / sz, a * 2 + 1 });
						}

					}

				}
			}
			
		}
	}
	

}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		fireball f;
		scanf("%d%d", &r, &c);
		scanf("%d", &f.m);
		scanf("%d", &f.s);
		scanf("%d", &f.d);
		map[r-1][c-1].push_back(f);
	}
	while (K--) {
		move();
		twoMore();
	}
	int sum=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() > 0) {
				for (int z = 0; z < map[i][j].size(); z++) {
					sum += map[i][j][z].m;
				}
			}
		}
	}

	printf("%d", sum);	
	return 0;
}