#include<iostream>	
#include<stdio.h>
using namespace std;
int N, big, small, result, tmp;
double fresult = 987654321;
void solve() {


	big = N / 5;


	for (int i = 0; i <= big; i++)
	{

		tmp = (N - (i * 5)) % 3;

		if (tmp == 0)
		{

			small = (N - (i * 5)) / 3;
			result = small + i;



		}


	}

}

int main() {

	cin >> N;
	solve();

	if (fresult > result) {
		fresult = result;
	}
	if (fresult == 0) {
		cout << "-1" << endl;
	}
	else {
		cout << fresult << endl;
	}


}
