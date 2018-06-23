#include<iostream>
#include<string>

using namespace std;

int main() {
	string a; 
	int cnt = 0;
	getline(cin, a);

	int size = a.length();

	for (int i = 0; i < size; i++) {
		if (a.at(i) == ' ') {
			cnt++;
		}
	}

	if (a.at(0) == ' ') {
		cnt--;
	}
	if (a.at(size - 1) == ' ') {
		cnt--;
	}
	cnt++;
	cout << cnt;
	return 0;

}