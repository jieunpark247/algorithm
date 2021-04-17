
#include<iostream>
#include<queue>
#include <cstdio>

using namespace std;

int map[16][16];
int visited[16][16];
int an = 0;
queue < pair < int, int > > q;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void Init_map() {
	for (int i = 0; i<16; i++)
		for (int j = 0; j<16; j++)
			map[i][j] = 0;

}
void Init_visited() {
	for (int i = 0; i<16; i++)
		for (int j = 0; j<16; j++)
			visited[i][j] = 0;

}

void bfs()
{
	q.push(make_pair(1, 1));
	visited[1][1] = 1;

	while (!q.empty())
	{
		int cur_x = q.front().first; //x°ª
		int cur_y = q.front().second; //y°ª
		q.pop();
		//	if (map[cur_x][cur_y] == 3)
		//		cout << "1" << '\n';
		//if(map[cur_x][cur_y] != 3)
		//	cout << "0" << '\n';

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];

			if (visited[new_x][new_y] == 0 && map[new_x][new_y] != 1)
			{
				if (map[new_x][new_y] == 3)
				{
					if (new_x >= 0 && new_y >= 0 && new_x < 16 && new_y < 16)
					{

						q.push(make_pair(new_x, new_y));
						visited[new_x][new_y] = true;
						an = 1;

					}
					
				}
			}

		}
		visited[cur_x][cur_y] = 0;

		//	cout << map[cur_x][cur_y];
	}

}

int main() {
	int testcase;

	for (int t = 0; t < 10; t++)
	{
		cin >> testcase;
		Init_map();
		Init_visited();

		for (int i = 0; i<16; i++)
			for (int j = 0; j<16; j++)
				scanf_s("%1d", &map[i][j]);

		cout << "#" << testcase << '\n';
		bfs();
		cout << an << endl;

	}

	return 0;

}
