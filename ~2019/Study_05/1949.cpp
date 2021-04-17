
#include <iostream>
#include <cstdio>
using namespace std;

int map[10][10];
bool visited[10][10];
int n, k; //  n*n크기, k 깊이만큼 깎을 수 있음
int res, maph;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0 ,1,-1};

void Init_map() {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			map[i][j] = 0;

}
void Init_visited() {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			visited[i][j] = 0;

}


void dfs(int x, int y, int cnt, bool flag) 
{

	visited[x][y] = 1; //방문상태 true로 바꿔놓고

	for (int i = 0; i < 4; i++)  //이동하는 for문 돌림
	{
	
		int nx = x + dx[i];		//x좌표이동
		int ny = y + dy[i];		//y좌표이동

		if (nx< 0 || nx >=n || ny<0 || ny >= n) // 만약 범위에벗어나거나
			continue;		
		if (visited[nx][ny]) // 만약 방문했으면
			continue;		//continue


		if (map[x][y] > map[nx][ny])  //만약 현재있는 값이 이동한 값보다 크면(다음 값이 작다면?,내리막길이라면?)
		{
			dfs(nx, ny, cnt + 1, flag); //재귀로 이동한 좌표와, 간횟수를 +1해주고 ,산을 깎지않았으니 flag그대로 해줌
			visited[nx][ny] = 0;	//방문취소
		}
		else if(map[x][y] <= map[nx][ny] && !flag) //만약 그게아니고 이동한값이 더 크거나 같으면서 && 산을 깎은적이 없다면?
		{
			//cout << "1=====" << '\n';
			for (int j = 1; j <= k; j++) //for문을 1부터 깎을 수 있는 깊이만큼 돌려서
			{
				flag = true;		//산을 깎았으니 true표시를 해준다.
				map[nx][ny] -= j;	//이동한 산의 크기에 - 깎을 만큼 빼준다.
				if (map[nx][ny] < map[x][y]) // 만약에 깎은 이동할 경로 결과값이 현재 xy값보다 작으면?
				
					dfs(nx, ny, cnt + 1, flag);	//재귀 .. 깎았음 표시
					visited[nx][ny] = 0;		 //
					//	cout << "cnt"<<cnt<<'\n';
				
				//cout << "2=====" << '\n';
				map[nx][ny] += j; //if가 아니면 다시 깎은거 없애줘야하니 +해줌
				flag = false; // 깎았다는 표시도 없애줌
			}
		}
		if (res < cnt) {	//만약에 cnt값이 그 전값인 res값보다 길다면 
			res = cnt;		//긴값으로 바꿔주기
	//		cout << "flag"<<flag << '\n';
		
		}

	//	cout<<"nx"<<nx<<"ny"<<ny << '\n';
	}

	
}

int main()
{
	int testcase;
	cin >> testcase;		//테케수입력


	for (int t = 1; t <= testcase; t++)	//테케수만큼 for문 돌리기 
	{
		cin >> n >> k;				// 크기 . 깊이 입력
		res = 0;	
		maph = 0;					//res maph초기화

		Init_map();


		for (int i = 0; i < n; i++) 	//for 문 n크기만큼 돌리기
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];

				if (maph < map[i][j]) //만약 이전값보다 map의 값이 더 크다면
					maph = map[i][j];// 그 값으로 넣어주기 최고 높은 maph값 구하기
				
			}
		
	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maph) { // 최고 높은 값이 map에 있다면 
					Init_visited(); //방문초기화해주고
					//cout <<i<<","<<j<<'\n';
					dfs(i, j, 1, false); //dfs돌리기
				
				}
				
			}
		cout << "#" << t << " " << res << endl;
	}


}
