
#include<iostream>


using namespace std;

int main() {
	int n, m,result;
	cin >> n >> m;

	if (n > m)
		result = (n - 1) + n * (m - 1);
	else
		result = (m - 1) + m * (n - 1);
	
	
	cout << result;
}