#include <iostream> 

using namespace std;
//////////////////////////////겹치는 부분 빼면 끝
int n, l; // l은 경사로의 길이
int map[101][101], temp[101];
int visited[101];
int cnt;
int num;
int flag;
int a;
void count_() {
	for (int i = 0; i < n - 1; i++) {
		if (temp[i] > temp[i + 1])
			a = (temp[i] - temp[i + 1]);
		else
			a = (temp[i + 1] - temp[i]);

		if (a == 1) // i와 i 옆자리의수의 차가 1일 경우
		{

			if (temp[i] > temp[i + 1]) // i 가 더크면?
			{

				num = temp[i + 1];
				for (int j = 0; j < l; j++) // l의 길이만큼 경사로를 놓을 수 있는가?
				{ //결국 i+1의 값이 L의 길이를 지날때 만큼 같은가?


					if (visited[i + 1 + j] != 1) {

						if (num != temp[i + 1 + j])
						{

							flag = 0;
							break;

						}

						//			cnt++; //1증가 시켜라
						flag = 1;

						visited[i + 1 + j] = 1;

					}
					else
						flag = 0;
				}
				//	cout << "flag-" << flag << '\n';

				if (flag == 0)
					break;

			}


			else if (temp[i] < temp[i + 1])  //i+1이 더크면?
			{
				num = temp[i];


				for (int j = 0; j < l; j++)
				{



					if (visited[i - j] != 1) {
						;
						if (num != temp[i - j])
						{
							flag = 0;

							break;

						}
						flag = 1; //값이 num과 같으면 1



					}
					else
						flag = 0;//visited 1이면 0이다.
				}

				//		cout << "flag/" << flag << '\n';
				if (flag == 0)
					break;


			}

		}

		else if (temp[i + 1] != temp[i]) {

			flag = 0;
			break;
		}
		else
			flag = 1;

		//모든 i가 같은 수 일 경우

	}
}
void solve() {


	for (int i = 0; i < n; i++) { // - 
								  //	cout << '\n';
		for (int j = 0; j < n; j++) {

			temp[j] = map[i][j]; // -> 방향으로 1줄씩 뽑아낸다. 
								 //		cout << temp[j];
		}
		flag = 0;
		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		count_();
		if (flag == 1) {
			cnt++;
		}
		//	cout << "cnt:/" << cnt << '\n';


	}



	for (int j = 0; j < n; j++) // | 
	{
		//	cout << '\n';
		for (int i = 0; i < n; i++) {
			temp[i] = map[i][j];
			//		cout << temp[i];
		}
		flag = 0;
		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		count_();
		if (flag == 1) {
			cnt++;
		}

		//	cout << "cnt:|" << cnt << '\n';
	}


}



int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n >> l;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = 0;
		for (int i = 0; i < n; i++){
			visited[i] = 0;
			temp[i] = 0;
		}


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];



			cnt = 0;
		solve();
		cout << "#" << t << " " << cnt << endl;

	}
}