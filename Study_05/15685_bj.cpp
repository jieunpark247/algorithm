#include <iostream> 
#include <vector>

using namespace std;

int k, n; //k세대 ,n개 드래곤커브
int x, y, d, g; //xy는 드래곤커브 시작점 , d는 시작방향 g는 세대
int dy[4] = { 0,-1, 0, 1 };
int dx[4] = { 1, 0,-1, 0 };
int map[101][101];
vector <int> dragon;
int cnt;



void solve() 
{

	map[y][x] = 1; // 처음 y,x좌표 1로 표시
	//vector <int> dragon;
	dragon.push_back(0); //*2할때 0부터 시작하면 계속 0이 나오니 1부터 시작할 수 있도록 0의 주소에 값을 넣어준다.
	dragon.push_back(d);

	int c_y = y + dy[d]; 
	int c_x = x + dx[d]; //c_y c_x 값에 d의 방향으로 이동한 값 넣어준다.

	
	map[c_y][c_x] = 1; // d의 방향으로 한칸 이동한 값 1로 표시
	int length = 1; // 이동하는 횟수 0세대 1번 1세대 2번 ... 증가한다.
	//int nn = 0;
	for (int gg = 0; gg < g; gg++) //g세대만큼 돌려줌 
	{
		
		for (int l = length; l > 0; l--) // length 가 1이 될때 까지 돌려준다. 
		{
		
			int dir = (dragon[l] + 1) % 4; // dragon vector배열에서 방향 1씩 증가해준다.
			int ny = c_y + dy[dir]; 
			int nx = c_x + dx[dir];
			
			map[ny][nx] = 1; //이동한 값 1표시
		//	cout << " dir:" << dir;
			dragon.push_back(dir); //방향 vector에 넣어줌 
			c_y = ny; // 이동한값을 c_y에 넣어준다 안해주면 다시 처음부터 돌려야한다.
			c_x = nx;

		}
		length = length*2; //이동 길이는 2배로 증가 
		
	
	}


}


int main() {

	cin>> n ;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;

		solve();

		dragon.clear(); //vector 초기화 안해주면 이전 vector 값이 계속 유지 됨

	}


	//cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				cnt++;	//네 귀퉁이가 모두 1이면 cnt++ 해준다. 

	cout << cnt<<endl;
		

}