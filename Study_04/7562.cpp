#include<iostream>
#include<queue>

using namespace std; 

int t, u, w, uf, wf, I ,cnt;
int map[301][301];
int visited[301][301];
int c[301][301];
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

queue < pair < int, int > > q;

void bfs(int i, int j) 
{	
	q.push(make_pair(i, j)); // ť�� �־��ְ�
	visited[i][j] = 1; //�湮 ǥ�� 
	while (!q.empty()) 
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < I && ny < I) 
			{
				if (visited[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					visited[nx][ny] = 1;
					c[nx][ny] = c[x][y] + 1;

				}
			}

		}
	}

}

int main() 
{
	cin >> t; //testcase �Է¹ޱ�
	while (t--) 
	{ // testcase�� ������ ����..
		cin >> I;  // I*Iũ���� �� �Է�
		cin >> u >> w >> uf >> wf; // ����Ʈ�� �ִ�ĭ , �̵��Ϸ��� ĭ �Է� 
		map[u][w] = 1;  //??
		map[uf][wf] = 2; //???
		
		bfs(u, w); // ����Ʈ�� u,w���� �����ϴ� bfs�� ����
		cout <<  c[uf][wf] << '\n';
		cnt = 0;
		for (int i = 0; i < 301; i++) 
			for (int j = 0; j < 301; j++) 
			{
				c[i][j] = 0;
				visited[i][j] = 0;
			}
		
		map[u][w] = 0;
		map[uf][wf] = 0;

	
	}

}

// count[][]�� ���� �� ��ȣ�մϴ� ��� ���� ���Դµ� �̹� Count�̸���ü�� �ǹ̰� �־ 
// �̰��� ��������� ��ȣ�ϴٴ� ���� ���µ� �ϴ�.