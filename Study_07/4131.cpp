#include <iostream> 

using namespace std;
//////////////////////////////��ġ�� �κ� ���� ��
int n, l; // l�� ������ ����
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

		if (a == 1) // i�� i ���ڸ��Ǽ��� ���� 1�� ���
		{

			if (temp[i] > temp[i + 1]) // i �� ��ũ��?
			{

				num = temp[i + 1];
				for (int j = 0; j < l; j++) // l�� ���̸�ŭ ���θ� ���� �� �ִ°�?
				{ //�ᱹ i+1�� ���� L�� ���̸� ������ ��ŭ ������?


					if (visited[i + 1 + j] != 1) {

						if (num != temp[i + 1 + j])
						{

							flag = 0;
							break;

						}

						//			cnt++; //1���� ���Ѷ�
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


			else if (temp[i] < temp[i + 1])  //i+1�� ��ũ��?
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
						flag = 1; //���� num�� ������ 1



					}
					else
						flag = 0;//visited 1�̸� 0�̴�.
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

		//��� i�� ���� �� �� ���

	}
}
void solve() {


	for (int i = 0; i < n; i++) { // - 
								  //	cout << '\n';
		for (int j = 0; j < n; j++) {

			temp[j] = map[i][j]; // -> �������� 1�پ� �̾Ƴ���. 
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