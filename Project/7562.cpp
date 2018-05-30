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
	q.push(make_pair(i, j)); // 큐에 넣어주고
	visited[i][j] = 1; //방문 표시 
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
	cin >> t; //testcase 입력받기
	while (t--) 
	{ // testcase가 끝날때 까지..
		cin >> I;  // I*I크기의 값 입력
		cin >> u >> w >> uf >> wf; // 나이트가 있는칸 , 이동하려는 칸 입력 
		map[u][w] = 1;  //??
		map[uf][wf] = 2; //???
		
		bfs(u, w); // 나이트가 u,w부터 시작하는 bfs를 실행
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

// count[][]를 했을 때 모호합니다 라는 말이 나왔는데 이미 Count이름자체에 의미가 있어서 
// 이것을 사용했을때 모호하다는 말이 나온듯 하다.