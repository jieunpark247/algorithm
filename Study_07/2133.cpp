#include<iostream>

using namespace std;

int n;
int newN;
int ans[32]; // �����
int DP[32]; //�߰��� ���ο�� �׻� 2�� 2�� �ʱ�ȭ

int main(){
	for (int i = 0; i <= 32; i++) {
		DP[i] = 2;
	}
	
	newN = 2; //N�϶��� ���ο� ����Ǽ��� �׻� 2���� �߰���
//	ans[2] = 3;
	ans[0] = 1;
	DP[2] = 3;

	cin >> n;
	if ((n % 2) == 0) { // ¦������ Ÿ���� �������
	
		for (int i = 2; i <= n; i += 2) { //n���� ����� ��
			for (int j = 2; j <= i; j += 2) { //i���� ����� ���� ����
				ans[i] += ans[i - j] * DP[j];  //�����Ͽ� ������
		
			}
		}



	}

	
	cout << ans[n] << endl;
}