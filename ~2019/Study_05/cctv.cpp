#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[4] = { 0, 1, 0, -1 }; //1�� 2�� 3�� 4��
int dx[4] = { 1, 0, -1, 0 };

vector < pair < int, int > > cctv; //���� ����
int map[10][10], N, M; 
int min_R = 70; // �ּ� Ƚ�� �ʱ�ȭ
//int cnt_tmp;

void CCTV(int y, int x, int dir) { // 0�̸� dir���⿡ ���� ���� ���� �̵��ϴ� �Լ� ����� 
//	cout << "1=========" << '\n';
	if (y < 0 || y >= N || x < 0 || x >= M)
		return;
	if (map[y][x] == 6)
		return;
	if (map[y][x] == 0) 
		map[y][x] = 7;
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		CCTV(ny, nx, dir); //��ͷ� ������ ��� �̵��ϰ� �Ѵ�.
	

}


void dfs(int num,int size) // 0���� cctv ũ�⸸ŭ 
{
//	cout << size<< '\n';
	//cout << "2=========" << '\n';
	//==============================
	if (num == size) { // road�� sizeũ��� ���ٸ� �ּڰ� ���� 
	//	cout << "6=========" << '\n';
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0)
					cnt++;
		cout << cnt;
		min_R = min(min_R, cnt);
		cout << min_R;

		//========================== cctv �簢������ �ּڰ� ���ϱ�
	}

	// �ƴϸ�? #ǥ�� ������� 
	
	int y = cctv[num].first; // cctv vector���� xy �־��� 0�� 6�� �ƴ� ������ ����ǥ
	int x = cctv[num].second; // 12345�� ���� �� ����
	
	int kind = map[y][x]; // 12345 ���� �������� map[][]�� ���ڸ� int ������ �־��ش�.
	
	int map2[10][10];//map �� ��ȭ�ϸ� ����Ҷ� ��ȭ�� ���¿��� ����Ǵϱ� ���ο� ���� �־  ���� �����ش�.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map2[i][j] = map[i][j];
	//cout << "5=========" << '\n';
	

	switch (kind)
	{
		
	case 1: //1������
	//	cout << "3=========" << '\n';
		for (int dir = 0; dir < 4; dir++) 
		{ // dir 4���� ������ 90�� ���� ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, nx, dir);
			dfs(num + 1, size); // Ƚ�� �߰����ֱ� 


			//-------------------------------------------------------?
			//map �����·� ����
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
			//------------------------------------7	-------------------?

		}
		break;
	
	case 2: //2������
		for (int dir = 0; dir < 2; dir++) 
		{ // dir 4���� ������ 90�� ���� ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, nx, dir);

			
			CCTV(y + dy[dir + 2], x + dx[dir + 2], dir+2);

			dfs(num + 1, size); // Ƚ�� �߰����ֱ� 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		}
		break;

	case 3: //3������
		for (int dir = 0; dir < 4; dir++) 
		{ // dir 4���� ������ 90�� ���� ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			CCTV(ny, nx, dir);

			int nextD = (dir + 1) % 4;
			CCTV(y + dy[dir + nextD], x + dx[dir + nextD], nextD);
			dfs(num + 1, size); // Ƚ�� �߰����ֱ� 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		}
		break;

	case 4: //4������
		for (int dir = 0; dir < 4; dir++) 
		{ // dir 4���� ������ 90�� ���� ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, nx, dir);
			
			int nextD = (dir + 1) % 4;
			CCTV(y + dy[nextD], x + dx[nextD], nextD);

			nextD = (dir + 2) % 4;
			CCTV(y + dy[nextD], x + dx[nextD], nextD);


			dfs(num + 1, size); // Ƚ�� �߰����ֱ� 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		}
		break;

	case 5: //5������
		for (int dir = 0; dir < 4; dir++) { // dir 4���� ������ 90�� ���� ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, x + nx, dir);
		}


			dfs(num + 1, size); // Ƚ�� �߰����ֱ� 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		
		break;



	}


}
int main()
{
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;
			if (temp > 0 && temp < 6) 
				cctv.push_back(make_pair(i, j));
			map[i][j] = temp;
			//cout << "4=========" << '\n';
			
		}
	}

	cout << cctv.size() << '\n';
	dfs(0, cctv.size());
//	cout << min_R;

	return 0;
}

