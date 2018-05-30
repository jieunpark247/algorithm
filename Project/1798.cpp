
#include<iostream>
#include<algorithm>
#include <cstdio>

using namespace std;

int map[36][36];
int visited[36];
int placeT[36],placeS[36];
char a;
int res;//res는 만족도가 더 높으면 여기다 저장하게 만드는 임시저장 변수
int hotelnum;
int m, n;
int finalt, finals;

void Init_map() {
	for (int i = 1; i<=n; i++)
		for (int j = 0; j<n; j++)
			map[i][j] = 0;;

}
void Init_visited() {
	for (int i = 1; i<=n; i++)
			visited[i] = 0;

}

void dfs(int day, int now, int sums ,int sumt) {//day-> m이 1일차 2~m-1 m일차 구분해서 나눔 / x와 y는 x->어딘가 로 간다 의미 //sums은 만족도 합의미//sumt는 시간의 합 의미//now는 현재 장소 의미
	visited[now] = 1; // x-y까지 장소 뜻함 ,, 그래서 x는 방문했으니 방문표시
	
	if (res < sums)
		res = sums; // res보다 sumsat이 더크면 res에 저장 || 만족도 최댓값 구하기
	
	//1일일때 ==============================
	if (day < m) {
		
	//	now = 1;
	


		for (int i = 2; i <= n; i++) {
			
			sumt = map[now][i] + placeT[i];
			sums += placeS[i];
			visited[i] = 1;
			now = i;
			//===================================
	//		cout << i << " ";
			//===================================
			if (sumt < 540) {
				int suma = sumt;
				for (int j = 1; j <= n; j++) {
					if (placeT[j] == 0)
						hotelnum = j;
					//===================================
					cout << "J: " << hotelnum << '\n';
					//===================================
				//hotel번호 구하기 
					sumt += map[now][hotelnum];
				}
				if (sumt < 540) {
		
					max(finals, sums);
					cout << sums; 
				}
				else {
					dfs(1, 1, 0, 0);
				}
			}
		}
		
	}
	//===============================
	cout << "s" << sums << "now"<< now <<"N";


	//m일일때
	if (day == m) {
		
	}


	for (int i = 1; i <= n; i++) {
		sumt=map[now][i]+placeT[i];
	}
					
					





	//====================
	if (sumt < 540) {

	}
		
	else {

	}
	//================= 시간은 9시간을 넘지 않게 하기 .. 그중에  1일차 2~m-1 m일차로 나눠서 시간 계산 해야한다. 공항 ~ 호텔 까지의 거리 더한값은 고정이 되어있음 

	

}
int main() 
{
		int testcase;
		cin >> testcase;
		for (int t = 1; t <= testcase; t++)
		{
			cin >> n >> m;
			Init_map();
			Init_visited();

			for (int j = 1; j <= n; j++)
				for (int i = 2; i <= n+1 - j; i++) {
					cin >> map[i][j];
					map[j][i]= map[i][j]; // 1->2 2->1 똑같으니 써준다
					//cout << map[i][j];
				}
			

			cout << "-----1" << '\n';
			for (int i = 0; i <n; i++)
			{
				cin >> a;
				if (a == 'P')
				{
					cin >> placeT[i] >> placeS[i];
					//totalhappy += placeS[i];
					//cout << "-----2" << '\n';
				}
				
				else
				{
					placeT[i] = 0;
					placeS[i] = 0;

					//cout << "-----3" << '\n';
				}
				//cout << "-----4" << '\n';
			}

				cout << "#" << t << '\n';
			
		}
	///---------------입력받기 끝

		res = 0;
	

		
			dfs(1,1,0,0);
	
}