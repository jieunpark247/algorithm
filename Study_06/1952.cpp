//������//
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int Mday, Mmonth, Mthreemonth, Myear;
int answer[13],month[12],cost[4];

int result;


int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
	
		for (int i = 0; i < 4; i++)
		cin >> cost[i]; //�̿�� ���� ���ϱ�
		for (int i = 0; i < 12; i++)
			cin >> month[i]; // 12�� �̿��ȹ

	
		answer[0] = 0;
		for (int i = 1; i <= 12; i++) {
			answer[i] = min(answer[i - 1] + cost[0] * month[i - 1], answer[i - 1] + cost[1]);
			if (i >= 3) {
				answer[i] = min(answer[i], answer[i - 3] + cost[2]);
			}
		}
		if (answer[12] > cost[3])
			answer[12] = cost[3];



	
		cout << "#" << t << " " << answer[12]<<endl;
		
		
	
	}
	return 0;
}