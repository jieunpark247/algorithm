//나무재테크 
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include <functional>
using namespace std;
int N, M, K , x, y, z;
int map[11][11];
int food[11][11];
vector <int > v[11][11];
vector <pair<pair<int, int>,pair<int, int>>> vSummer;
vector <pair<int, int>> vFall;

//bool cmp(const pair<pair<int, int>, pair<int, int>>& a, const pair<pair<int, int>, pair<int, int>> & b)
//{
//	return a.second.second > b.second.second;
//}

void solve() {
	//봄 
	vector <int > vv[11][11];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//int vsize = v[i][j].size();
				//나무
			for (int zz = 0; zz < v[i][j].size(); zz++) {
				if (v[i][j][zz] <= map[i][j]) {
					//영양제 냠
					map[i][j] = map[i][j] - v[i][j][zz];
					v[i][j][zz] = v[i][j][zz] + 1;
					vv[i][j].push_back(v[i][j][zz]);

					if (v[i][j][zz] % 5 == 0 ) {
						vFall.push_back({ i,j });
					}

				}
				else {
					//죽음
					vSummer.push_back({ {i,j},{v[i][j][zz],zz} });
				}
			}

		}
	}

	//여름 
	if (vSummer.size() != 0) {
	//	sort(vSummer.begin(), vSummer.end(), cmp);
		for (int i = 0; i < vSummer.size(); i++) {
			int nx = vSummer[i].first.first;
			int ny = vSummer[i].first.second;
			int nz = vSummer[i].second.first;
			int zz = vSummer[i].second.second;
			map[nx][ny] += (nz/2);
			
			//v[nx][ny].erase(v[nx][ny].begin() + zz);

		}
	}


	//가을 
	if (vFall.size() != 0) {
		for (int i = 0; i < vFall.size(); i++) {
			int nx = vFall[i].first;
			int ny = vFall[i].second;

			if (nx - 1 > 0) vv[nx - 1][ny].push_back(1);			
			if (ny - 1 > 0)  vv[nx][ny - 1].push_back(1);
			if (nx + 1 <= N) vv[nx + 1][ny].push_back(1);
			if (ny + 1 <= N) vv[nx][ny + 1].push_back(1);
			if (nx - 1 > 0 && ny - 1 > 0) vv[nx - 1][ny - 1].push_back(1);
			if (nx - 1 > 0 && ny + 1 <= N) vv[nx - 1][ny + 1].push_back(1);
			if (nx + 1 <= N && ny - 1 > 0) vv[nx + 1][ny - 1].push_back(1);
			if (nx + 1 <= N && ny + 1 <= N)	vv[nx + 1][ny + 1].push_back(1);
		}

	}

	//겨울 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += food[i][j];
		}
	}

	vSummer.clear();
	vFall.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			v[i][j].clear();
			for (int z = 0; z < vv[i][j].size(); z++) {
				v[i][j].push_back(vv[i][j][z]);
			}
		}
	}


}
int main() {
	scanf("%d%d%d", &N, &M, &K);//111
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &food[i][j]);
			map[i][j] = 5;
		}
	}


;	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x][y].push_back(z);
	}

	while(K--){

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (v[i][j].size() > 1) {
					sort(v[i][j].begin(), v[i][j].end());
				}
			}
		}
		solve();

	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(v[i][j].size() != 0) cnt += v[i][j].size();
			
		}
	}

	printf("%d", cnt);
}