#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int map[15][15];
int color[15][15];
int N, K, res;
int chess[11][4];
int flag = 0;
int dy[5] = {0, 1 ,-1,0,0};
int dx[5] = {0, 0,0,-1,1 };

void solve(int x, int y, int dir, int depth ,int num) {
    int blueFlag = 0;

    if (x + dx[dir] <= 0 || y + dy[dir] <= 0 || x + dx[dir] > N || y + dy[dir] > N) {
        if (dir == 1 || dir == 3)  dir = dir + 1;
        else if (dir == 2 || dir == 4)  dir = dir - 1;
        chess[num][2] = dir;
        blueFlag = 1;
    }
    int loc = color[x + dx[dir]][y + dy[dir]];

    if (loc == 0) { // 흰색
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //움직임 
        int val = map[nx][ny];
        for (int i = 1; i <= K; i++) {
            if (x == chess[i][0] && y == chess[i][1] && depth <= chess[i][3]) {
                chess[i][0] = nx;
                chess[i][1] = ny;
                chess[i][3] = chess[i][3] + val;
                map[nx][ny]++;
                map[x][y]--;

                if (map[nx][ny] >= 4 ) flag = 1;
            }
        }
        

    }
    else if (loc == 1) {//빨강

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //움직임 
        int val = map[nx][ny];
        int val2 = map[x][y];
        for (int i = 1; i <= K; i++) {
            if (x == chess[i][0] && y == chess[i][1] && depth <= chess[i][3]) {
                chess[i][0] = nx;
                chess[i][1] = ny;
                if (map[x][y] == 1)  chess[i][3] = chess[i][3] + map[nx][ny];
                else chess[i][3] = (val2 - chess[i][3] - 1 ) + val; // 방향 반대로 한값 + 원래 이동할 곳에 있던 값 
                map[nx][ny]++;
                map[x][y]--;

                if (map[nx][ny] >= 4) flag = 1;
            }
        }
            
        
    }
    else if (loc == 2 && blueFlag == 0) {//파랑
     
        if (dir == 0 || dir == 2)  dir = dir + 1;
        else if (dir == 1 || dir == 3)  dir = dir - 1;
        chess[num][2] = dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx > 0 && ny > 0 && nx <= N && ny <= N && color[nx][ny] != 2) {
           //움직이려는 방향 파랑, 끝 이 아니라면 
            int val = map[nx][ny];
            for (int i = 1; i <= K; i++) {
                if (x == chess[i][0] && y == chess[i][1] && depth <= chess[i][3]) {
                    chess[i][0] = nx;
                    chess[i][1] = ny;
                    chess[i][3] = chess[i][3] + val;
                    map[nx][ny]++;
                    map[x][y]--;

                    if (map[nx][ny] >= 4) flag = 1;
                }
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
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        chess[i][0] = a;
        chess[i][1] = b;
        map[a][b]++;
        chess[i][2] = c;
        chess[i][3] = 0;
    }
    res = 1;
    while (-1) {
        for (int i = 1; i <= K; i++) {
            solve(chess[i][0], chess[i][1], chess[i][2], chess[i][3], i);
            if (flag == 1) {
                break;
            }
        }

        if (flag == 1) {
            printf("%d", res);
            break;
        }
        else if (res > 1000) {
            printf("-1");
            break;
        }

        res++;
    }
}