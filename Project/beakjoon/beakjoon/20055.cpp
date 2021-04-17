#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int N, K ,KK;
int arr[102][2];
int ngd;
int robot[102][2];
int tmp,rtmp,rtemp, temp;
int level;
void beltRotate() {
	//컨에베이어 벨트 이동 >>> ** 로봇도 같이 이동함 
	tmp = arr[0][0];
	arr[0][0] = arr[0][1];
	rtmp = robot[0][0];
	robot[0][0] = robot[0][1];
	
	for (int i = 0; i < N-1; i++) {
		temp = arr[i + 1][0];
		arr[i + 1][0] = tmp;
		tmp = temp;

		rtemp = robot[i + 1][0];
		robot[i + 1][0] = rtmp;
		rtmp = rtemp;
	}
	tmp = arr[N-1][1];
	arr[N-1][1] = temp;
	rtmp = robot[N - 1][1];
	robot[N - 1][1] = rtemp;

	for (int i = N-1; i >= 0; i--) {
		temp = arr[i - 1][1];
		arr[i - 1][1] = tmp;
		tmp = temp;
		rtemp = robot[i - 1][1];
		robot[i - 1][1] = rtmp;
		rtmp = rtemp;
	}
	//이동한 후 로봇이 N번째 위에 있으면 내림 
	if (robot[N - 1][0] == 1) {
		robot[N - 1][0] = 0;
	}
}

void robotRotate() {
//로봇 이동 
	for (int i = N-1; i >= 0 ; i--) {
		if (arr[i + 1][0] != 0 && robot[i + 1][0] == 0 && robot[i][0] == 1) {
			if ((i + 1) != N - 1) {
				arr[i + 1][0] -= 1;
				robot[i][0] = 0;
				robot[i + 1][0] = 1;
			}else{
				robot[i][0] = 0;
				arr[i + 1][0] -= 1;
			}

		}

	}
// 로봇 첫번째 컨베이어에 올라감 
	if (robot[0][0] == 0 && arr[0][0] != 0) {
		robot[0][0] = 1;
		arr[0][0] -= 1;
	}
}

int selectFin() {
	//내구도 갯수 셈
	ngd = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i][0] == 0)
			ngd++;
		if (arr[i][1] == 0)
			ngd++;
	}
	return ngd;
}
void solve(int lv) {
 	beltRotate();
	robotRotate();

	if (selectFin() >= KK) {
		level = lv;
		return;
	}
	else {
		solve(lv + 1);
	}
}
int main() {
	scanf("%d%d", &N, &KK);
	for (int i = 0; i < 2*N; i++) {
		if (i < N) {
			scanf("%d", &arr[i][0]);
		}
		else {
			scanf("%d", &arr[(2*N)-1- i][1]);
		}
	}
	solve(1);
	printf("%d",level);
	return 0;
}

