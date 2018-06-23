#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define min(a , b) (a < b) ?(a):(b);
#define max(a , b) (a < b) ?(b):(a);

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

char map[20][20] = { 0 };
long long visit[20][20] = { 0 };
char mem = 0;
int result = 0;
int num = 0;
int r, c;
int tc;

void dfs(int row, int cal, int dir) 
{
	char ca = map[row][cal];
	if (result)
		return;
	if (visit[row][cal] & (1 << dir * 5 + num)) {
		return;
	}
	visit[row][cal] = visit[row][cal] | (1 << dir * 5 + num);

	if (ca == '@') {
		result = 1;
		return;
	}

	//========== 수행명령
	switch (ca) {
	case '<':
		dir = 3; // 왼쪽
		row += dr[dir];
		cal += dc[dir];
		if (cal < 0)
			cal = c - 1;
		break;

	case '>':
		dir = 1; // 오
		row += dr[dir];
		cal += dc[dir];
		if (cal > c - 1)
			cal = 0;
		break;

	case '^':
		dir = 0; //위
		row += dr[dir];
		cal += dc[dir];
		if (row < 0)
			row = r - 1;
		break;
	case 'v':
		dir = 2; //아
		row += dr[dir];
		cal += dc[dir];
		if (row > r - 1)
			row = 0;
		break;

	case '_':
		if (num == 0)
			dir = 1;
		else
			dir = 3;

		row += dr[dir];
		cal += dc[dir];
	
		if (row < 0)
			row = r - 1;
		else if (row > r - 1)
			row = 0;
		else if (cal < 0)
			cal = c - 1;
		else if (cal > c - 1)
			cal = 0;
		break;

	case '|':
		if (num == 0)
			dir = 2;
		else
			dir = 0;

		row += dr[dir];
		cal += dc[dir];
		if (row < 0)
			row = r - 1;
		else if (row > r - 1)
			row = 0;
		else if (cal < 0)
			cal = c - 1;
		else if (cal > c - 1)
			cal = 0;
		break;

	case '?':
		for (int i = 0; i < 4; i++) {
			dir = i;
			int tmpr = row;
			int tmpc = cal;

			row += dr[dir];
			cal += dc[dir];
			if (row < 0)
				row = r - 1;
			else if (row > r - 1)
				row = 0;
			else if (cal < 0)
				cal = c - 1;
			else if (cal > c - 1)
				cal = 0;
			
			dfs(row, cal, dir);
			row = tmpr;
			cal = tmpc;

		}
		return;
		break;
	case '.':
		row += dr[dir];
		cal += dc[dir];
		if (row < 0)
			row = r - 1;
		else if (row > r - 1)
			row = 0;
		else if (cal < 0)
			cal = c - 1;
		else if (cal > c - 1)
			cal = 0;
		break;

//????????????????????????
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		num = ca-'0';
		
		//????????????????
		row += dr[dir];
		cal += dc[dir];
		if (row < 0)
			row = r - 1;
		else if (row > r - 1)
			row = 0;
		else if (cal < 0)
			cal = c - 1;
		else if (cal > c - 1)
			cal = 0;
		break;
	case '+':
		if (num == 15)
			num = 0;
		else
			num++;

		row += dr[dir];
		cal += dc[dir];
		if (row < 0)
			row = r - 1;
		else if (row > r - 1)
			row = 0;
		else if (cal < 0)
			cal = c - 1;
		else if (cal > c - 1)
			cal = 0;
		break;


	case '-':
		if (num == 0)
			num = 15;
		else
			num--;


		row += dr[dir];
		cal += dc[dir];
		if (row < 0)
			row = r - 1;
		else if (row > r - 1)
			row = 0;
		else if (cal < 0)
			cal = c - 1;
		else if (cal > c - 1)
			cal = 0;
		break;
	default:
		break;

	}
	dfs(row, cal, dir);
	
}

int main()
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) 
	{
		tc = i;
		cin >> r >> c;

		for (int j = 0; j < r; j++) 
		{
			for (int k = 0; k < c; k++) 
			{
				cin >> map[j][k];
			}
		}
		memset(visit, 0, sizeof(visit));
		dfs(0, 0, 1);
		if (result) {
			cout << "#" << i << " YES" << endl;
		}
		else {
			cout << "#" << i << " NO" << endl;
		}
		result = 0;

		num = 0;
	}
	return 0;
	}

