#include <iostream>

using namespace std;
int map[9][9];
int findNum[9];
int r;
bool find(int n) {

	for (int i = 0; i < 9; i++)
		if (findNum[i] == n)
			return true;
	
	return false;
}
// 1차 배열에 가로 세로 네모 안의 숫자를 0~8번까지 다 넣고 1~9까지 있는지 확인하는 함수

bool result()
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			findNum[j] = map[i][j];
	//		cout << findNum[j];
		}

		for (int j = 1; j < 10; j++)
				if (!find(j))
					return false;
			//가로

	}
	
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++) {
			findNum[i] = map[i][j];
	//		cout << findNum[i];
		}
		for (int i = 1; i < 10; i++)

			if (!find(i))
				return false;

		//세로

	}


	for (int t = 0; t<9; t++) 
	{
		int idx = 0;
		for (int i = (t / 3) * 3; i<((t / 3) * 3 + 3); i++)
			for (int j = (t % 3) * 3; j<((t % 3) * 3 + 3); j++)
				findNum[idx++] = map[i][j];
		for (int i = 1; i < 10; i++)
			if (!find(i))
				return false;
	}//네모


	//다 맞으면 true해줘
	return true;
}
int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		for (int i = 0; i < 9; i++) 
			for (int j = 0; j < 9; j++) 
				cin >> map[i][j];

		cout << "#" << t << " " << result()<<'\n';
	}


	return 0;
}
