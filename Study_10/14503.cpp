//·Îº¿Ã»¼Ò±â 14503

#include<iostream>
using namespace std;
int n, m,r,c;
int d;
int dx[4] = { -1,0,1,0 }; //0ºÏ 1µ¿ 2³² 3¼­
int dy[4] = { 0,1,0,-1 };
int map[51][51];
int map2[51][51];
int ans;
int dire[4] = { 3,0,1,2 };
int back[4] = { 2,3,0,1 };
void pr() {
	cout << "\n'";
	for (int i = 0; i < n; i++) {
		cout << "\n'";
			for (int j = 0; j < m; j++) {
				cout << map[i][j];
			}
	}cout << "\n'";
	cout << "\n'";
}

bool isRange(int x ,int y) {
	return (x >= 0 && x < n &&y >= 0 && y < m); 
}
void robot(int x, int y, int dir,int cnt) {

	//pr();
	//cout << cnt<<'\n';
	
	if (map[x][y] == 0) //1¹ø
		map[x][y] = 2;

	int leftdir = dire[dir];
	int nx = x + dx[leftdir];
	int ny = y + dy[leftdir];
	int b = back[dir];
//	cout << map[nx][ny] << " sddf"<<x<<y << isRange(nx, ny)<<dir;

	if (map[nx][ny] == 0 && isRange(nx, ny)) {
		//cout << "A" << '\n';
	//	cout << "dir" << leftdir << '\n';
		cnt = 0;
		robot(nx, ny, leftdir, cnt); 
	}//2-1
	else if (map[nx][ny] != 0 && cnt !=4 && isRange(nx, ny)) {
	//	cout << "B" << '\n';
	//	cout <<"dir"<< leftdir << '\n';
		robot(x, y, leftdir, cnt + 1);
	}//2-2
	
	else if (map[nx][ny] != 0 && cnt==4 && map[x + dx[b]][y + dy[b]] != 1 && isRange(nx, ny)) {
		//cout << "C" << '\n';
		//cout << "dir" << dir << '\n';
		cnt = 0;
		robot(x + dx[b], y + dy[b], dir, cnt);
	}//2-3
	else if (map[nx][ny] != 0 && cnt ==4 && map[x + dx[b]][y + dy[b]] == 1 && isRange(nx, ny)) {
		//cout << "D" << '\n';
		//cout << "dir" << leftdir << '\n';
		return;
	}//2-4

	
}
/*void solve(int x, int y, int dir) {

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	switch (dir)
	{
		case 0:
			robot();

			solve(nx, ny, 3);
			break;

		case 1:

			robot();
			solve(nx, ny, 0);
			break;

		case 2:
			robot();
			solve(nx, ny, 1);
			break; 

		case 3:

			robot();
			solve(nx, ny, 2);
			break;

	}
	


}*/
int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
	

	// solve( r,  c,  d);
	robot( r,c, d, 0);
	 ans = 0;
	 for (int i = 0; i < n; i++)
		 for (int j = 0; j < m; j++)
			 if (map[i][j] == 2)
				 ans++;
	 cout << ans << endl;

}