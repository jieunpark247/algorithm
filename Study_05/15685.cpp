#include <iostream> 
#include <vector>

using namespace std;

int k, n; //k���� ,n�� �巡��Ŀ��
int x, y, d, g; //xy�� �巡��Ŀ�� ������ , d�� ���۹��� g�� ����
int dy[4] = { 0,-1, 0, 1 };
int dx[4] = { 1, 0,-1, 0 };
int map[101][101];
vector <int> dragon;
int cnt;



void solve() 
{

	map[y][x] = 1; // ó�� y,x��ǥ 1�� ǥ��
	//vector <int> dragon;
	dragon.push_back(0); //*2�Ҷ� 0���� �����ϸ� ��� 0�� ������ 1���� ������ �� �ֵ��� 0�� �ּҿ� ���� �־��ش�.
	dragon.push_back(d);

	int c_y = y + dy[d]; 
	int c_x = x + dx[d]; //c_y c_x ���� d�� �������� �̵��� �� �־��ش�.

	
	map[c_y][c_x] = 1; // d�� �������� ��ĭ �̵��� �� 1�� ǥ��
	int length = 1; // �̵��ϴ� Ƚ�� 0���� 1�� 1���� 2�� ... �����Ѵ�.
	//int nn = 0;
	for (int gg = 0; gg < g; gg++) //g���븸ŭ ������ 
	{
		
		for (int l = length; l > 0; l--) // length �� 1�� �ɶ� ���� �����ش�. 
		{
		
			int dir = (dragon[l] + 1) % 4; // dragon vector�迭���� ���� 1�� �������ش�.
			int ny = c_y + dy[dir]; 
			int nx = c_x + dx[dir];
			
			map[ny][nx] = 1; //�̵��� �� 1ǥ��
		//	cout << " dir:" << dir;
			dragon.push_back(dir); //���� vector�� �־��� 
			c_y = ny; // �̵��Ѱ��� c_y�� �־��ش� �����ָ� �ٽ� ó������ �������Ѵ�.
			c_x = nx;

		}
		length = length*2; //�̵� ���̴� 2��� ���� 
		
	
	}


}


int main() {

	cin>> n ;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;

		solve();

		dragon.clear(); //vector �ʱ�ȭ �����ָ� ���� vector ���� ��� ���� ��

	}


	//cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				cnt++;	//�� �����̰� ��� 1�̸� cnt++ ���ش�. 

	cout << cnt<<endl;
		

}