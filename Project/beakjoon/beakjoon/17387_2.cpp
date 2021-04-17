#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int N, K, map[15][15][15],color[15][15];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int chess[15][4];
int flag = 0;

void solve(int x, int y, int dir,int num) {
    int blueflag = 0;

    //맨 끝에 있을 때 >> 방향 바꿔주어야 한다. 
    if (x + dx[dir] <= 0 || y + dy[dir] <= 0 || x + dx[dir] > N || y + dy[dir] > N) {
        if (dir == 1 || dir == 3)  dir = dir + 1;
        else if (dir == 2 || dir == 4)  dir = dir - 1;
        chess[num][2] = dir;
        blueflag = 1;
    }
    
    int nextColor = color[x + dx[dir]][y + dy[dir]];
    //방향 별로 기능 수행 

    if (nextColor == 0) { //W
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        //내 위에 있는 체스는 함께 움직임 (map[x][y][현재 움직일 체스 위치] ~~[맨 마지'막(제일 위에 있는) 체스위치 ])
        int mapsize = map[x][y][0];
        int mapstart = chess[num][3];
        for (int i = mapstart; i <= mapsize; i++) {
            ++map[nx][ny][0]; // 이동 
            --map[x][y][0]; //원래 있던 자리 갯수 제거
            chess[map[x][y][i]][3] = map[nx][ny][0];    //움직일 자리에 체스가 있다면 그 위로 올라감 
            chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y값 변경 
            map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //이동할 체스 원래있던애 위에 올리기
            map[x][y][i] = 0; // 원래있던 체스 초기화

            if (map[nx][ny][0] >= 4) flag = 1;
        }

    }
    else if (nextColor == 1) { //R
        int nx = x + dx[dir];
        int ny = y + dy[dir];


        //내 위에 있는 체스는 함께 움직임 (map[x][y][현재 움직일 체스 위치] ~~[맨 마지막(제일 위에 있는) 체스위치 ])
        int mapsize = map[x][y][0];
        int mapstart = chess[num][3];
        for (int i = mapsize; i >= mapstart; i--) {
            ++map[nx][ny][0]; // 이동 
            --map[x][y][0]; //원래 있던 자리 갯수 제거
            chess[map[x][y][i]][3] = map[nx][ny][0];    //움직일 자리에 체스가 있다면 그 위로 올라가는 번째  
            chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y값 변경 
            map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //이동할 체스 원래있던애 위에 올리기
            map[x][y][i] = 0; // 원래있던 체스 초기화

            if (map[nx][ny][0] >= 4) flag = 1;
        }


    }
    else if (nextColor == 2 && blueflag == 0) { //B
        if (dir == 1 || dir == 3)  dir = dir + 1;
        else if (dir == 2 || dir == 4)  dir = dir - 1;
      
        chess[num][2] = dir; // blue > 방향 바꿈 
       
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //방향 바꿔서도 파란색이면 >> 방향바꾼채로 앞으로 가지 말기 
        if (color[nx][ny] == 0 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
            //내 위에 있는 체스는 함께 움직임 (map[x][y][현재 움직일 체스 위치] ~~[맨 마지막(제일 위에 있는) 체스위치 ])
            int mapsize = map[x][y][0];
            int mapstart = chess[num][3];
            for (int i = mapstart; i <= mapsize; i++) {
                ++map[nx][ny][0]; // 이동 
                --map[x][y][0]; //원래 있던 자리 갯수 제거
                chess[map[x][y][i]][3] = map[nx][ny][0];    //움직일 자리에 체스가 있다면 그 위로 올라감 
                chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y값 변경 
                map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //이동할 체스 원래있던애 위에 올리기
                map[x][y][i] = 0; // 원래있던 체스 초기화

                if (map[nx][ny][0] >= 4) flag = 1;
            }
        }
        else if (color[nx][ny] == 1 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
            //내 위에 있는 체스는 함께 움직임 (map[x][y][현재 움직일 체스 위치] ~~[맨 마지막(제일 위에 있는) 체스위치 ])
            int mapsize = map[x][y][0];
            int mapstart = chess[num][3];
            for (int i = mapsize; i >= mapstart; i--) {
                ++map[nx][ny][0]; // 이동 
                --map[x][y][0]; //원래 있던 자리 갯수 제거
                chess[map[x][y][i]][3] = map[nx][ny][0];    //움직일 자리에 체스가 있다면 그 위로 올라가는 번째  
                chess[map[x][y][i]][0] = nx; chess[map[x][y][i]][1] = ny; //x,y값 변경 
                map[nx][ny][map[nx][ny][0]] = map[x][y][i]; //이동할 체스 원래있던애 위에 올리기
                map[x][y][i] = 0; // 원래있던 체스 초기화

                if (map[nx][ny][0] >= 4) flag = 1;
            }

        }


    }
}
int main() {
	scanf("%d%d", &N, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &color[i][j]);
		}
	}

	for (int i = 1; i <= K; i++) {
		scanf("%d%d%d", &chess[i][0], &chess[i][1], &chess[i][2]);
		map[chess[i][0]][chess[i][1]][1] = i;
		chess[i][3] = 1; // 몇번째 위치하는지  
		map[chess[i][0]][chess[i][1]][0] = 1; //같은 칸에 말이 두 개 이상 있는 경우는 입력으로 주어지지 않는다.
	}


    int res = 1;

    while (1) {

  
        for (int i = 1; i <= K; i++) {
            solve(chess[i][0], chess[i][1], chess[i][2], i);
            if (flag == 1) {
                break;
            }
        }
        
        if (flag == 1) {
            printf("%d", res);
            break;
        }else if (res > 1000) {
            printf("-1");
            break;
        }
        res++;
    }

}
