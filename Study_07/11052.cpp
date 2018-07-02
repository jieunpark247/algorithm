#include <iostream>
#include<algorithm>
using namespace std;

int n;
int p[10000],r[10000];
int ans,sum;
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	
	r[0] = 0;
	for (int j = 1; j <= n; j++) {
		ans = 0;
		sum = 0;
		for (int i = 1; i <= j; i++) {
			sum = max(p[i] + r[j - i], sum);
		}
		r[j] = sum;
	}
	for (int j = 1; j <= n; j++) {
		ans = max(ans, r[j]);
		//cout<<j<<"ÀÏ ¶§ ÃÖ´ñ°ª : "<<r[j]<<'\n';
	}

	cout << ans;

}