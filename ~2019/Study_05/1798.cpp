
#include<iostream>
#include<algorithm>
#include <cstdio>

using namespace std;

int map[36][36];
int visited[36];
int placeT[36],placeS[36];
char a;
int res;//res�� �������� �� ������ ����� �����ϰ� ����� �ӽ����� ����
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

void dfs(int day, int now, int sums ,int sumt) {//day-> m�� 1���� 2~m-1 m���� �����ؼ� ���� / x�� y�� x->��� �� ���� �ǹ� //sums�� ������ ���ǹ�//sumt�� �ð��� �� �ǹ�//now�� ���� ��� �ǹ�
	visited[now] = 1; // x-y���� ��� ���� ,, �׷��� x�� �湮������ �湮ǥ��
	
	if (res < sums)
		res = sums; // res���� sumsat�� ��ũ�� res�� ���� || ������ �ִ� ���ϱ�
	
	//1���϶� ==============================
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
				//hotel��ȣ ���ϱ� 
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


	//m���϶�
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
	//================= �ð��� 9�ð��� ���� �ʰ� �ϱ� .. ���߿�  1���� 2~m-1 m������ ������ �ð� ��� �ؾ��Ѵ�. ���� ~ ȣ�� ������ �Ÿ� ���Ѱ��� ������ �Ǿ����� 

	

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
					map[j][i]= map[i][j]; // 1->2 2->1 �Ȱ����� ���ش�
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
	///---------------�Է¹ޱ� ��

		res = 0;
	

		
			dfs(1,1,0,0);
	
}