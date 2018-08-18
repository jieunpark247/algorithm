// 사다리 조작 15684
#include <iostream>
#include<vector>
using namespace std;
int M, N, H,a,b;
int map[11][11],map2[11][11];
int ans,res;
int finishLadder[11];
int dx[4] = { -1,1,0, 0};
int dy[4] = { 0, 0,1,-1};
int nx, ny,nn;
int cnt;
void plusLadder(int times) { //사다리를 놓았을 때
	vector<int> ind;

	int k = times;

	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i <  - k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end()); //오름차순 정렬

	do { //순열 돌리기

		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {

				

			}
		}
	}

	while (next_permutation(ind.begin(), ind.end()));



}
void goLadder(int x,int y) { //사다리를 타고 갔을 때 결과를 출력 
	if (x > M) {
		finishLadder[nn] = y;
		return;
	}

	
	if (map2[x][y] == 1) {
		nx = dx[1] + x;
		ny = dy[1] + y;

	}else if (map2[x][y] == 2) {
		nx = dx[2] + x;
		ny = dy[2] + y;
		if (nx <= N && ny <= M && nx > 0 && ny > 0)
			map2[nx][ny] = 1;

	}else if (map2[x][y] == 3) {
		nx = dx[3] + x;
		ny = dy[3] + y;
		if (nx <= N && ny <= M && nx > 0 && ny > 0)
			map2[nx][ny] = 1;
	}

	
	goLadder(nx,ny);
}
int main() {
	ans = -1;
	res = 0;
	cin >> N >> M>> H;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			map[i][j]=1;

	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		map[a][b] = 2; //go to right
		map[a][b + 1] = 3; // go to left

	}

	if (H > 3)
		H = 3;
	for (int h = 1; h <= H; h++)
		plusLadder(h);



	for (int j = 1; j <= N; j++){

		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				map2[i][j] = map[i][j];
		nn = j;
		goLadder(1, j);

	}
	for (int j = 1; j <= N; j++) 
		cout <<"("<< j<<" : "<< finishLadder[j] << ")";
	
	for (int j = 1; j <= N; j++) {
		if (finishLadder[j] != j)
			res = -1;
	}

	if (res != -1)
		ans = cnt;

	//cout << ans << endl;
}