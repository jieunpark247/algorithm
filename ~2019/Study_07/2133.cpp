#include<iostream>

using namespace std;

int n;
int newN;
int ans[32]; // 결과값
int DP[32]; //중간값 새로운값은 항상 2임 2로 초기화

int main(){
	for (int i = 0; i <= 32; i++) {
		DP[i] = 2;
	}
	
	newN = 2; //N일때의 새로운 경우의수는 항상 2개씩 추가됨
//	ans[2] = 3;
	ans[0] = 1;
	DP[2] = 3;

	cin >> n;
	if ((n % 2) == 0) { // 짝수여야 타일이 만들어짐
	
		for (int i = 2; i <= n; i += 2) { //n까지 경우의 수
			for (int j = 2; j <= i; j += 2) { //i까지 경우의 수를 만듦
				ans[i] += ans[i - j] * DP[j];  //누적하여 더해줌
		
			}
		}



	}

	
	cout << ans[n] << endl;
}