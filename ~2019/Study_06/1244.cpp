#include<iostream>
#include<vector>
#include <algorithm>


#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a�� b�� ��ȯ

using namespace std;

vector<int> v;
int tmp[6]; int tmp2[6];
int n, r;
int ans;
int num_;
int cnt;
int result;
int maxNum;
int minNum;
int count_,maxN;


void make() {
	v.clear();

	num_ = n / 100000;
	v.push_back(num_);

	n = n - (num_ * 100000);
	num_ = n / 10000;
	v.push_back(num_);

	n = n - (num_ * 10000);
	num_ = n / 1000;
	v.push_back(num_);

	n = n - (num_ * 1000);
	num_ = n / 100;
	v.push_back(num_);

	n = n - (num_ * 100);
	num_ = n / 10;
	v.push_back(num_);

	n = n - (num_ * 10);
	num_ = n / 1;
	v.push_back(num_);
	// ������ �迭�� ���� 

	for (int ii = 0; ii < v.size(); ii++) {
		tmp[ii] = v[ii]; //�ʱ�ȭ
	}

	for (int ii = 0; ii < v.size(); ii++) {
		tmp2[ii] = tmp[ii]; //�ʱ�ȭ
	}

}


void MaxCount() {// �ִ� � �ִ��� ����
	count_ = 0;
	maxNum = 0;
	minNum = 987654321;
	for (int m = (v.size() - cnt); m < v.size(); m++) {
		maxNum = max(maxNum, tmp[m]);
		minNum = min(minNum, tmp[m]);
	}
	
	for (int m = (v.size() - cnt); m < v.size(); m++)
		if (tmp[m] == maxNum)
			count_++;
	
}

void solve() {

		for (int i = (6 - cnt); i <6; i++) {
			for (int j = 5; j >(6 - cnt - 1); j--) {

				if (count_ < 3) { // �ִ� �Ȱ��� ���ڰ� 3�� �̸��϶� for���� �������� ���� ū ���� �����Ѵ�.
					if (i != j) {		
						SWAP(tmp[i], tmp[j])
							result = tmp[0] * 100000 + tmp[1] * 10000 + tmp[2] * 1000 + tmp[3] * 100 + tmp[4] * 10 + tmp[5] * 1;
						if (ans < result)
							ans = result;
						n = ans;
						for (int ii = 0; ii < v.size(); ii++)
							tmp[ii] = tmp2[ii]; //tmp������ �ʱ�ȭ �ٽ� for���� �������� ���������� ��ȭ�ؾ� �Ѵ�.

					

					}
				}else if (count_ >= 3) {
					if (i != j && maxNum == tmp[j] && minNum == tmp[i]) { //i�� �տ������� j�� �ڿ������� ���Ǹ鼭 ,, ������������ �ִ��ڸ��� ���� ū ���� �ִ��ڸ��� �ٲ۴�
						SWAP(tmp[i], tmp[j])
							result = tmp[0] * 100000 + tmp[1] * 10000 + tmp[2] * 1000 + tmp[3] * 100 + tmp[4] * 10 + tmp[5] * 1;
							n = result;
							ans = result;		
						
					}

				break; // else if ���� ������ �ٽ� for���� ����ȵ� 
				}
				
			}
		}

	
}

int main() {
	int testcase;
	cin >> testcase;


	for (int t = 1; t <= testcase; t++) {
		cin >> n >> r;
		ans = n;
		make(); //�� ó�� �ʱ�ȭ
		MaxCount();//�ִ� ���� ����
	
		cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (tmp[i] != 0)
				cnt++;

		} //���ڸ� �����ΰ�? �迭�� 6���� �������־��� ������ 088832�ΰ�� 0�̻��� ���ڸ� ���־���Ѵ�.

		
		//===============================================================// n�� �ִ��϶� ?
			int sorttmp[6];
		for (int ii = 0; ii < v.size(); ii++) {
			sorttmp[ii] = v[ii]; //�ʱ�ȭ
		}
		sort(sorttmp, sorttmp+6);
		
		maxN= sorttmp[5] * 100000 + sorttmp[4] * 10000 + sorttmp[3] * 1000 + sorttmp[2] * 100 + sorttmp[1] * 10 + sorttmp[0] * 1;
		
		//===============================================================
		


	
		for (int rr = 0; rr < r; rr++) { //��� ���ڸ� �ٲٳ�?
			
			if (maxN == ans && count_ >= 2)  //��ġ�� ���ڰ� 2�� �̻��̰�, �ִ��̸� �״�� ���
				break;
			
			solve();
		
			if (ans == maxN && (r - rr) % 2 == 1 ) { //���� ����Ƚ���� Ȧ���̰� , �̹� �ִ��̸� �ǳ��ڸ� �ٲ���
				ans = tmp[0] * 100000 + tmp[1] * 10000 + tmp[2] * 1000 + tmp[3] * 100 + tmp[5] * 10 + tmp[4] * 1;

				break;
			}

			count_ = 0; //count���� 

			make(); // n�� �迭�� �ִ´�.
		}
		cout << "#" << t << " " << ans << endl;;
		


	}
	}