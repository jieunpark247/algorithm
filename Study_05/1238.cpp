#include<iostream>
#include<queue>

using namespace std;
int map[101][101];
int start;
int visited[100];
int n;
int cur_start;
queue < int> q;
int result;

void Init_visited() {
	for (int i = 0; i<100; i++)
		visited[i] = 0;

}

void bfs()
{

	visited[0] = 1;
	q.push(0);

	while (!q.empty())
	{

		cur_start = q.front();
		q.pop();

		//cout <<out": "<< cur_start  <<'\n';

		for (int i = 1; i < 100; i++)
		{
			//	cout << "in: " << cur_start << '\n';

			// size 1�� size2 �Ѵ��� ���� ���ϰ� ���ǿ� ������ ť�� �־��ش�. 
			if (map[][] == i && visited[i] == 0)
			{
				//cout << "a: " << cur_start << '\n';
				//	cout << "i: " << i << '\n';


				visited[i] = 1;
				q.push(i);



			}


			


		}
		//cout << cur_start<< " ";
		if (result < cur_start) {   //��� �ִ� �̾Ƴ��� .. bfs�� �Ѳ����� ť�� ������ ������ �ǳ����� 99�� �ƴҼ��� �ִ�. �׷��Ƿ� 99��� ���� ���ԵǾ� �ִٸ�
			result = cur_start;		//����� 1�� �ϴ� ������ �ٲ���� .. �ᱹ ���� cur_start ���� ���� ū ���� 99�� ���´ٸ� ����� 1�� ������ش�.
									//	cout << result<<" ";
		}




	}

}
int main() {
	//int testcase;
	//	int n;

	//cin >> testcase;


	for (int t = 1; t <= 10; t++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				map[i][j] = 0;

		//�ʱ�ȭ ���� �������� ������ ���� ��ū �迭�� ���ٸ� �����迭�� �Է��Ҷ� ū�迭�� ���ڰ� �����ֱ� ������ �ʱ�ȭ ���ش�.

		cin >> n >>start;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> i >> j;
				map[i][j] = 1;

			}
		cout << "#" << t << " ";
		Init_visited(); //�ʱ�ȭ

		result = 0; //result�ʱ�ȭ
	//	bfs();
	

	}

}