#include<iostream>
#include<queue>

using namespace std;
int size1[100];
int size2[100];
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
	
	while(!q.empty())
	{
		
		
		cur_start = q.front();
		q.pop();

		//cout <<out": "<< cur_start  <<'\n';
		
		for (int i = 1; i < 100; i++) 
		{
		//	cout << "in: " << cur_start << '\n';

			// size 1�� size2 �Ѵ��� ���� ���ϰ� ���ǿ� ������ ť�� �־��ش�. 
			if (size1[cur_start] == i && visited[i] == 0)
			{
				//cout << "a: " << cur_start << '\n';
			//	cout << "i: " << i << '\n';
			
	
				visited[i] = 1;
				q.push(i); 
			
			

			}


			if (size2[cur_start] == i && visited[i] == 0)
			{
				//
				//			cout << "b: " << cur_start << '\n';
				//		cout << "i: " << i << '\n';


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
		{
			size1[i] = 0;
			size2[i] = 0;

		}//size�ʱ�ȭ ���� �������� ������ ���� ��ū �迭�� ���ٸ� �����迭�� �Է��Ҷ� ū�迭�� ���ڰ� �����ֱ� ������ �ʱ�ȭ ���ش�.

		cin >> t >> n;
		
		for (int i = 0; i < n; i++)
		{	
				int a; // �迭�� �ּҰ� 
				cin >> a;
				if (size1[a] == 0) 
					cin >> size1[a];  //�ּҰ��� �̹� ���ִٸ�?
				else
					cin >> size2[a]; //2��° �迭�� ������ //������ �ִ� 2�������� ������

				
			}
	
				cout << "#" <<  t << " ";
				Init_visited(); //�ʱ�ȭ
			
				result = 0; //result�ʱ�ȭ
				bfs();
				//cout << result;
				if (result == 99)  // ���� ������� 99��� 1���
					cout << "1" << endl;

				else
					cout << "0" << endl;

			
	}
	
}