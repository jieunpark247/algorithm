// �κм����� ��
//��Ʈ��ŷ��� 
#include<iostream>
#include<vector>

using namespace std;
int n,k,aa; 
int a[100],visitedTop[100],visited[100];
vector <int> v;
int cnt;

void solve(int index, int sum) {
	if (index >= n) //���࿡ n������ ���� Ƚ���� 
		return; //������  ..�׷��� ��Ʈ��ŷ���� �ڷ� ���ư���.
	if (sum > k) // �� ��ģ���� k���� ũ�� 
		return; // ������
	if (sum == k) { // ���� k�� ���ٸ�?
		cnt++; // cnt 1������
		return; // ��
	}
	if (sum < k) { //k���� ������  ?
		for (int i = index + 1; i < n; i++)
			solve(i,sum+a[i]); // ��ͷ� ������ 
			//-> ��ͷ� ������ �Լ��� �� ������ �������¿��� ��� ���ư��⶧���� 
		    //���߿� return �� �ϸ� �ٽ� ��Ʈ��ŷ���� ���� �ִ� ������ ���ư���.
	}

}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cnt = 0;
		cin >> n >> k;
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		solve(-1,0);
		cout << "#" << t << " " << cnt << endl;

	}
}