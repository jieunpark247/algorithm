#include<iostream>
#include<algorithm>
#include<vector>	
#include<string.h>
using namespace std;

int map[101][101]; 
int R,C,K;
int res;
int arr[102];
int r, c;
int rr, cc;
vector <pair<int, int>> v;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

void solve() {
	while (-1) {
		memset(arr, 0, sizeof(arr));

		if (map[R][C] == K) {
			printf("%d", res);
			break;
		}
		if (res > 100) {
			printf("-1");
			break;
		}

		// r 행 , c 열 
		if (r >= c) {
			//R연산 모든 행
			for (int i = 0; i < r; i++) { //행
				for (int j = 0; j < c; j++) { //열
					if (map[i][j] != 0) {
						arr[map[i][j]]++;

					}
				}
				for (int z = 1; z <= 100; z++) {
					if (arr[z] != 0) {
						v.push_back({ arr[z],z });
					}
				}
				for (int j = 0; j < c; j++) {
					map[i][j] = 0;
				}

				//횟수, 수 순서 
				sort(v.begin(), v.end(), compare);

				// 큰 배열 기준으로 나머지 0으로 채워넣기 
				int vsize = v.size() * 2;
				cc = max(cc, vsize);
				rr = r;


				for (int cp = 0; cp < v.size(); cp++) {
					map[i][cp * 2] = v[cp].second;
					map[i][cp * 2 + 1] = v[cp].first;
				}
				memset(arr, 0, sizeof(arr));
				v.clear();
			}

		}
		else {
			//C연산  모든 열
			for (int j = 0; j < c; j++) { //열
				for (int i = 0; i < r; i++) { //행
					if (map[i][j] != 0) {
						arr[map[i][j]]++;
					}
				}
				for (int z = 1; z <= 100; z++) {
					if (arr[z] != 0) {
						v.push_back({ arr[z],z });
					}
				}
				for (int i = 0; i < r; i++) {
					map[i][j] = 0;
				}
				//횟수, 수 순서 
				sort(v.begin(), v.end(), compare);

				// 큰 배열 기준으로 나머지 0으로 채워넣기 
				int vsize = v.size() * 2;
				rr = max(rr, vsize);
				cc = c;
				
				for (int cp = 0; cp < v.size(); cp++) {
					map[cp*2][j] =  v[cp].second;
					map[cp * 2 + 1][j] = v[cp].first;
				}
				memset(arr, 0, sizeof(arr));
				v.clear();
			}

		}

		r = rr; c = cc;
		res++;
	}
}
int main() {

	scanf("%d%d%d", &R, &C, &K);
	R = R - 1;
	C = C - 1;
	res = 0;
	memset(map, 0, sizeof(map));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d",&map[i][j]);
		}
	}

	r = 3; c = 3;
	solve();

}