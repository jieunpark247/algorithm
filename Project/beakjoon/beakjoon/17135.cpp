#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
int dy[4] = { -1,1,1,-1 };
int dx[4] = { 1,1,-1,-1 };
int N, M, D;
int map[20][20];
int ks[3] = { 0, };
vector<pair<pair<int, int>, pair<int, int>>> v;
int killDf, res;
int temp[20][20];
int arKill[3];
bool compare(pair<pair<int, int>, pair<int,int>>& a, pair<pair<int, int>, pair<int, int>>& b) {
	if (a.first.second == b.first.second) {
			return a.second.second < b.second.second;
		}

	return a.first.second < b.first.second;
	

}

void down() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (i == 0) {
				map[i][j] = 0;
			}
			else {
				map[i][j] = map[i - 1][j];
			}
		}
	}
}
void attack() {
	int flag = 1;
	while (flag) {
		for (int i = 0; i < 3; i++) arKill[i] = 0;  //초기화
		flag = 0;
		for (int a = 0; a < 3; a++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					int dis = abs(N - i) + abs(ks[a] - j);
					if (map[i][j] == 1 && dis <= D) {
						v.push_back({ {a,dis} ,{ i,j } });
					}
					if (map[i][j] == 1) {
						flag = 1;
					}
				}
			}
		}
		if (v.size() == 0) {
			down();
			continue;
		}

		sort(v.begin(), v.end(), compare); //vector 비교 
		int ar = 0;
		for (int i = 0; i < v.size(); i++) {
			if (ar == 3) break;
			if (arKill[v[i].first.first] == 0) {
				if (map[v[i].second.first][v[i].second.second] == 1)
					killDf++;
				map[v[i].second.first][v[i].second.second] = 0;
				arKill[v[i].first.first] = 1;
				ar++;
			}
		}
		v.clear();
		down();
	}

}
void ksLoc(int depth, int next) {
	if (depth == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = map[i][j];
			}
		}
		attack();
		res = max(killDf, res);
		killDf = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = temp[i][j];
			}
		}
		return;
	}

	for (int i = next; i < M; i++) {
		ks[depth] = i;
		ksLoc(depth + 1, i + 1);
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	ksLoc(0, 0);
	printf("%d", res);
	return 0;
}