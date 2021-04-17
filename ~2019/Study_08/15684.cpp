//
//  15684.cpp
//  Project
//사다리 조작
#include <iostream>

#include <memory.h>

using namespace std;
int M, N, H, a, b;
int visited[31][12];
int map[31][12], map3[31][12];
int ans;
int finishLadder[12];
int dx[4] = { -1,1,0, 0 };
int dy[4] = { 0, 0,1,-1 };
int nx, ny, nn;
int cnt; int cn;
int tt;

bool goLadder() { //사다리를 타고 갔을 때 결과를 출력a
	for (int i = 1; i <= N; i++) 
	{
		int current = i; 
		for (int j = 1; j <= H; j++) 
		{
			if (map[j][current] == 2)
				current += 1;
			else if (current - 1 > 0 && map[j][current - 1] == 2)
				current -= 1;
		}

		if (i == current)
			continue;
		else
			return false;
	}

	return true;
}


void plusLadder(int times, int xx, int tt) { //사다리를 놓는 경우의 수 출력


	if (times >= tt) {
	
		if (goLadder()) {
			ans = tt;
		}
		return;
	}

	if (ans >= 0)
		return;



	int map2[31][12];
	memcpy(map2, map, sizeof(map2));

	for (int h = xx; h <= H; h++) {
		for (int j = 1; j < N; j++) {
			if (map[h][j] == 1 && map[h][j + 1] == 1) {
				//visited[h][j] == 1;
				map[h][j] = 2;
				map[h][j + 1] = 3;

				times = times + 1;
				plusLadder(times, h, tt);
				times = times - 1;
				memcpy(map, map2, sizeof(map));
			

			}
		}
	}

	return;

}

int main() {
	 ios_base::sync_with_stdio(false);
	ans = -1;
	cin >> N >> M >> H;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = 1;

	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		map[a][b] = 2; //go to right
		map[a][b + 1] = 3; // go to left
	

	}



	for (int t = 0; t <= 3; t++) {
	
		plusLadder(0, 1, t);

		if (ans >= 0)
			break;



	}
	cout << ans << endl;

	return 0;
}
