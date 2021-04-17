#include<iostream>

#define max(a,b) (a > b ? a : b)  

using namespace std;

int n;
int map[2][100001];
int p[2][100001];


int main() {

	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n;

		for (int i = 0; i < 2; i++)
			for (int j = 2; j < n+2; j++)
				map[i][j] = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < n + 2; j++){
				cin >> map[i][j];
			}
		}


	for (int i = 0; i < 2; i++) 
		for (int j = 2; j < n + 2; j++)
				p[i][j] = 0;


		for (int i = 2; i< n + 2; i++) {
			p[0][i] = max(max(p[0][i - 1], p[1][i - 2] + map[0][i]), p[1][i - 1] + map[0][i]);
			p[1][i] = max(max(p[1][i - 1], p[0][i - 2] +map[1][i]), p[0][i - 1] + map[1][i]);


		}

		
		if (p[0][n + 1] > p[1][n + 1])
			cout << p[0][n + 1] << endl;
		else
			cout << p[1][n + 1] << endl;
		

	}

}