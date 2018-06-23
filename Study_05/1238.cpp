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

			// size 1과 size2 둘다의 값을 비교하고 조건에 맞으면 큐에 넣어준다. 
			if (map[][] == i && visited[i] == 0)
			{
				//cout << "a: " << cur_start << '\n';
				//	cout << "i: " << i << '\n';


				visited[i] = 1;
				q.push(i);



			}


			


		}
		//cout << cur_start<< " ";
		if (result < cur_start) {   //결과 최댓값 뽑아내기 .. bfs는 한꺼번에 큐에 보내기 때문에 맨끝값이 99가 아닐수도 있다. 그러므로 99라는 값이 포함되어 있다면
			result = cur_start;		//출력을 1로 하는 것으로 바꿔야함 .. 결국 나온 cur_start 값중 제일 큰 값인 99가 나온다면 결과는 1로 출력해준다.
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

		//초기화 값을 덮을수는 있지만 전에 더큰 배열을 쓴다면 작은배열을 입력할때 큰배열의 숫자가 남아있기 때문에 초기화 해준다.

		cin >> n >>start;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> i >> j;
				map[i][j] = 1;

			}
		cout << "#" << t << " ";
		Init_visited(); //초기화

		result = 0; //result초기화
	//	bfs();
	

	}

}