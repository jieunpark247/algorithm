#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int N, M, K, map[51][51], k[], R, C, S;
int findMin() {
	int minVal = 987654321;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += map[i][j];
		}
		minVal = min(sum, minVal);
	}
	return minVal;

}
void rotate(int r,int c,int s) {

	
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &R, &C, &S);
		rotate(R, C, S);
	}
	printf("%d",findMin());
}