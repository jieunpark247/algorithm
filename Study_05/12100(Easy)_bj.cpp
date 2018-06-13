#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;

int n;
int map[20][20];
int dx[4] = { -1, 1, 0, 0 };/// 위 아 왼 오
int dy[4] = { 0, 0, -1, 1 };

int solve(int idx) {

	if (idx == 5) { //5번 다돌렸으면?
		int maxB = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				maxB= max(maxB, map[i][j]);
		return maxB; //최댓값 구하기
	}

	int maxB = 0;
	for (int i = 0; i < 4; i++) {
		int temp[20][20];
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)
				temp[a][b] = map[a][b];
		//새 temp에 map 값을 저장한다.



	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
