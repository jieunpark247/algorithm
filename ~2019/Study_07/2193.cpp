//2193 ÀÌÄ£¼ö
//DP
#include<iostream>

using namespace std;

int n;
int num_ ;
long long v[2][100];

int main() {

	cin >> n;
	num_ = (n + 1) / 2;
	v[0][0] = 1;
	v[1][0] = 1;
	v[0][1] = 2;
	v[1][1] = 3;

	for (int i = 2; i < num_ ; i++) {
		v[0][i] = v[0][i - 1] + v[1][i - 1];
		v[1][i] = v[0][i] + v[1][i - 1];
	}

		if (n % 2 == 0)
			cout << v[1][num_ - 1] << endl;
		else
			cout << v[0][num_ - 1] << endl;

		return 0;
	
}
