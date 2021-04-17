#include<iostream>	

using namespace std;

int main() {
	int arra[10000];
	int n;
	int a, b, c, d, e;
	for (int i = 1; i <= 10000; i++) {
		a = i % 10;
		b = (i / 10) % 10;
		c = (i / 100) % 10;
		d = (i / 1000) % 10;
		e = (i / 10000) % 10;
		arra[i - 1] = i + a + b + c + d + e;

	}

	bool isCreate = false;
	for (int i = 1; i <= 10000; i++) {
		isCreate = false;
		for (int j = 1; j <= 10000; j++) {
			if (arra[j - 1] == i) {
				isCreate = true;
				break;
			}
		}

		if (!isCreate) {
			cout << i << endl;
		}

	}
	return 0;
}
