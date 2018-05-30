#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[4] = { 0, 1, 0, -1 }; //1위 2오 3아 4아
int dx[4] = { 1, 0, -1, 0 };

vector < pair < int, int > > cctv; //백터 생성
int map[10][10], N, M; 
int min_R = 70; // 최소 횟수 초기화
//int cnt_tmp;

void CCTV(int y, int x, int dir) { // 0이면 dir방향에 따라서 다음 수로 이동하는 함수 만들기 
//	cout << "1=========" << '\n';
	if (y < 0 || y >= N || x < 0 || x >= M)
		return;
	if (map[y][x] == 6)
		return;
	if (map[y][x] == 0) 
		map[y][x] = 7;
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		CCTV(ny, nx, dir); //재귀로 돌려서 계속 이동하게 한다.
	

}


void dfs(int num,int size) // 0부터 cctv 크기만큼 
{
//	cout << size<< '\n';
	//cout << "2=========" << '\n';
	//==============================
	if (num == size) { // road가 size크기랑 같다면 최솟값 추출 
	//	cout << "6=========" << '\n';
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0)
					cnt++;
		cout << cnt;
		min_R = min(min_R, cnt);
		cout << min_R;

		//========================== cctv 사각지대인 최솟값 구하기
	}

	// 아니면? #표시 해줘야지 
	
	int y = cctv[num].first; // cctv vector에서 xy 넣어줌 0과 6이 아닌 값들의 ㄷ좌표
	int x = cctv[num].second; // 12345가 나올 수 있지
	
	int kind = map[y][x]; // 12345 종류 가나오는 map[][]의 숫자를 int 변수에 넣어준다.
	
	int map2[10][10];//map 이 변화하면 재귀할때 변화한 상태에서 진행되니까 새로운 곳에 넣어서  실행 시켜준다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map2[i][j] = map[i][j];
	//cout << "5=========" << '\n';
	

	switch (kind)
	{
		
	case 1: //1번종류
	//	cout << "3=========" << '\n';
		for (int dir = 0; dir < 4; dir++) 
		{ // dir 4방향 움직임 90도 움직 ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, nx, dir);
			dfs(num + 1, size); // 횟수 추가해주기 


			//-------------------------------------------------------?
			//map 원상태로 복귀
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
			//------------------------------------7	-------------------?

		}
		break;
	
	case 2: //2번종류
		for (int dir = 0; dir < 2; dir++) 
		{ // dir 4방향 움직임 90도 움직 ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, nx, dir);

			
			CCTV(y + dy[dir + 2], x + dx[dir + 2], dir+2);

			dfs(num + 1, size); // 횟수 추가해주기 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		}
		break;

	case 3: //3번종류
		for (int dir = 0; dir < 4; dir++) 
		{ // dir 4방향 움직임 90도 움직 ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			CCTV(ny, nx, dir);

			int nextD = (dir + 1) % 4;
			CCTV(y + dy[dir + nextD], x + dx[dir + nextD], nextD);
			dfs(num + 1, size); // 횟수 추가해주기 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		}
		break;

	case 4: //4번종류
		for (int dir = 0; dir < 4; dir++) 
		{ // dir 4방향 움직임 90도 움직 ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, nx, dir);
			
			int nextD = (dir + 1) % 4;
			CCTV(y + dy[nextD], x + dx[nextD], nextD);

			nextD = (dir + 2) % 4;
			CCTV(y + dy[nextD], x + dx[nextD], nextD);


			dfs(num + 1, size); // 횟수 추가해주기 

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = map2[i][j];
		}
		break;

	case 5: //5번종류
		for (int dir = 0; dir < 4; dir++) { // dir 4방향 움직임 90도 움직 ok
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			CCTV(ny, x + nx, dir);
		}


			dfs(num + 1, size); // 횟수 추가해주기 

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

