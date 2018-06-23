
#include <iostream>
#include <cstdio>
using namespace std;

int map[10][10];
bool visited[10][10];
int n, k; //  n*nũ��, k ���̸�ŭ ���� �� ����
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

	visited[x][y] = 1; //�湮���� true�� �ٲ����

	for (int i = 0; i < 4; i++)  //�̵��ϴ� for�� ����
	{
	
		int nx = x + dx[i];		//x��ǥ�̵�
		int ny = y + dy[i];		//y��ǥ�̵�

		if (nx< 0 || nx >=n || ny<0 || ny >= n) // ���� ����������ų�
			continue;		
		if (visited[nx][ny]) // ���� �湮������
			continue;		//continue


		if (map[x][y] > map[nx][ny])  //���� �����ִ� ���� �̵��� ������ ũ��(���� ���� �۴ٸ�?,���������̶��?)
		{
			dfs(nx, ny, cnt + 1, flag); //��ͷ� �̵��� ��ǥ��, ��Ƚ���� +1���ְ� ,���� �����ʾ����� flag�״�� ����
			visited[nx][ny] = 0;	//�湮���
		}
		else if(map[x][y] <= map[nx][ny] && !flag) //���� �װԾƴϰ� �̵��Ѱ��� �� ũ�ų� �����鼭 && ���� �������� ���ٸ�?
		{
			//cout << "1=====" << '\n';
			for (int j = 1; j <= k; j++) //for���� 1���� ���� �� �ִ� ���̸�ŭ ������
			{
				flag = true;		//���� ������� trueǥ�ø� ���ش�.
				map[nx][ny] -= j;	//�̵��� ���� ũ�⿡ - ���� ��ŭ ���ش�.
				if (map[nx][ny] < map[x][y]) // ���࿡ ���� �̵��� ��� ������� ���� xy������ ������?
				
					dfs(nx, ny, cnt + 1, flag);	//��� .. ����� ǥ��
					visited[nx][ny] = 0;		 //
					//	cout << "cnt"<<cnt<<'\n';
				
				//cout << "2=====" << '\n';
				map[nx][ny] += j; //if�� �ƴϸ� �ٽ� ������ ��������ϴ� +����
				flag = false; // ��Ҵٴ� ǥ�õ� ������
			}
		}
		if (res < cnt) {	//���࿡ cnt���� �� ������ res������ ��ٸ� 
			res = cnt;		//�䰪���� �ٲ��ֱ�
	//		cout << "flag"<<flag << '\n';
		
		}

	//	cout<<"nx"<<nx<<"ny"<<ny << '\n';
	}

	
}

int main()
{
	int testcase;
	cin >> testcase;		//���ɼ��Է�


	for (int t = 1; t <= testcase; t++)	//���ɼ���ŭ for�� ������ 
	{
		cin >> n >> k;				// ũ�� . ���� �Է�
		res = 0;	
		maph = 0;					//res maph�ʱ�ȭ

		Init_map();


		for (int i = 0; i < n; i++) 	//for �� nũ�⸸ŭ ������
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];

				if (maph < map[i][j]) //���� ���������� map�� ���� �� ũ�ٸ�
					maph = map[i][j];// �� ������ �־��ֱ� �ְ� ���� maph�� ���ϱ�
				
			}
		
	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maph) { // �ְ� ���� ���� map�� �ִٸ� 
					Init_visited(); //�湮�ʱ�ȭ���ְ�
					//cout <<i<<","<<j<<'\n';
					dfs(i, j, 1, false); //dfs������
				
				}
				
			}
		cout << "#" << t << " " << res << endl;
	}


}
