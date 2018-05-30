#include <iostream>

using namespace std;
int map[9][9];

int main() {

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];

	cout << map[1][2];
}