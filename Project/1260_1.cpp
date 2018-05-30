#include<iostream>
#include<queue>

using namespace std;

int n, m, v;

bool visited[10001];
bool map[10001][10001];
queue<int> q;

void init_visited() //초기화함수 
{
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}
void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";

	for (int y = 1; y <= n; y++)
	
		if (visited[y] == false && map[x][y] == true)
		{
			visited[y] = true;
			dfs(y);
		}
	
}

void bfs()
{
	visited[v] = true; // 정점 방문표시
	q.push(v);
	while (!q.empty()) 
	{
		int vv = q.front();
		q.pop();
		cout << vv << " ";
		for (int i = 1; i <= n; i++) 
			if (visited[i] == false && map[vv][i] == true)// 연결되어있고 방문하지않았으면?
			{
				visited[i] = true;
				q.push(i);
			}
		
	}
}

int main() {

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) 
	{ 
		int start, end;
		cin >> start >> end;
		map[start][end] = true; // map[s][e]가 연결되었다고 표시
		map[end][start] = true;
	}

	init_visited();
		dfs(v);
		cout << endl;
	init_visited();
		bfs();
		return 0;
	

}