#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   
#include<vector>
#include<algorithm>   

using namespace std;
int map[5][25] = { {20,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
                    {3,13,16,19} ,
                    {2,22,24} ,
                    {3,28,27,26} ,
                    {4,25,30,35,40} };
int vis[5][25];
int N;
int ans;
int arr[10];
struct horse {
    int x, y;
};
horse mal[4];
void move(int ii, int ncurr) {
    if (mal[ii].y == 0) {
        mal[ii].y += arr[ncurr];
        if (mal[ii].y > map[mal[ii].x][0]) {
            if (mal[ii].x == 4 || mal[ii].x == 0) { //4
                mal[ii].x = -1; mal[ii].y = -1;
            }
            else {
                mal[ii].y = mal[ii].y - map[mal[ii].x][0];
                mal[ii].x = 4;
            }
        }
    }
    else {
        if (mal[ii].x == 4 || mal[ii].x == 0) {
            if ((arr[ncurr] + mal[ii].y) > map[mal[ii].x][0]) {
                mal[ii].x = -1; mal[ii].y = -1;
            }
            else {
                mal[ii].y += arr[ncurr];
            }
        }
        else {
            if ((arr[ncurr] + mal[ii].y) > map[mal[ii].x][0]) {
                mal[ii].y = arr[ncurr] - (map[mal[ii].x][0] - mal[ii].y);
                mal[ii].x = 4;
                if (mal[ii].y > map[mal[ii].x][0]) {
                    mal[ii].x = -1; mal[ii].y = -1;
                }
            }
            else {
                mal[ii].y += arr[ncurr];
            }
        }
    }

    //두개가 같은위치라서 위치 하나로 visit 체크하게 변경했어
    if (mal[ii].x == 0 && mal[ii].y == 20) {
        mal[ii].x = 4;
        mal[ii].y = 4;
    }
}

int dfs(int curr, int score) {
    if (curr == 10) {
        return score;
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int mapX = mal[i].x;
        int mapY = mal[i].y;

        if (mal[i].x == -1 || mal[i].y == -1) {
            continue;
        }

        //continue 한 다음에 -1이아닐때 0해줘야 런타임에러안나요 
        vis[mal[i].x][mal[i].y] = 0;

        if (map[mal[i].x][mal[i].y] == 10 && mal[i].y != 0) {
            mal[i].x = 1;
            mal[i].y = 0;
        }
        else if (map[mal[i].x][mal[i].y] == 20 && mal[i].y != 0) {
            mal[i].x = 2;
            mal[i].y = 0;

        }
        else if (map[mal[i].x][mal[i].y] == 30 && mal[i].y != 0 && mal[i].x == 0) {
            mal[i].x = 3;
            mal[i].y = 0;
        }

        move(i, curr);

        if (vis[mal[i].x][mal[i].y] == 1) {
            mal[i].x = mapX;
            mal[i].y = mapY;
            vis[mal[i].x][mal[i].y] = 1;
            continue;
        }
        int temp = 0;

        if (mal[i].x != -1 && mal[i].y != -1 && mal[i].y != 0) {
            temp = map[mal[i].x][mal[i].y];
            vis[mal[i].x][mal[i].y] = 1;
        }
        ret = max(ret, dfs(curr + 1, score + temp));
        vis[mal[i].x][mal[i].y] = 0;
        mal[i].x = mapX;
        mal[i].y = mapY;


        //마지막에 visit 1로 다시 돌려줘야하해요
        vis[mal[i].x][mal[i].y] = 1;


    }
    return ret;
}


int main() {

    for (int i = 0; i < 10; i++) {
        scanf("%d", &N);
        arr[i] = N;
    }
    for (int i = 0; i < 4; i++) {
        mal[i].x = 0;
        mal[i].y = 0;
    }

    printf("%d", dfs(0, 0));
}