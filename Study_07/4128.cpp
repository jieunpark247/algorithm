#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int map[21][21];
int checked[21];
int A, B;

int ans;

void init_map() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = 0;
}
void init_checked() {
	for (int i = 1; i <= n; i++)
			checked[i] = 0;
}


void solve(int dFood) { //detail->���  food->����
	

	vector<int> ind;

	int k = dFood;

	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < n - k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end()); //�������� ����

	do { //���� ������

		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				checked[i+1]=1;//A������ ��ᰪ���� ���� ex>123�̸� 123���� 

			}
			if (ind[i] == 0) {
				checked[i+1] = 0; //B������ ��ᰪ���� ���� ex>456�̸� 456����

			}

		}
		A = 0, B = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (checked[i] == 0 && checked[j] == 0)
					A += map[i][j];
				if (checked[i] == 1 && checked[j] == 1)
					B += map[i][j];

			}
		}
		ans = min(abs(A - B), ans);

	}

	while (next_permutation(ind.begin(), ind.end()));





}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n;
		init_map();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];

	
		init_checked();
		ans = 999999999;
		solve(n / 2);

		cout << "#" << t << " " << ans << endl;;


	}
}