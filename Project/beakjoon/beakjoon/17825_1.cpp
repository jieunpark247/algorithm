#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
int map[6][25] = { {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38},
                    {0,13,16,19} ,
                    {0,22,24} ,
                    {0,28,27,26} ,
                    {0,25,30,35},
                    {0,40,0} };
int mapSize[5] = { 19,3,2,3,3};
int res, arr[10];
int vis[6][25];
struct horse {
    int x, y;
};
horse mal[4];

void move(int i, int curr) {
    //1,2,3 배열은 > 4로 감
    if (mal[i].x == 1 || mal[i].x == 2 || mal[i].x == 3) {
        if (mal[i].y + arr[curr] > mapSize[mal[i].x]) {
              mal[i].y = arr[curr] - (mapSize[mal[i].x] - mal[i].y);
              mal[i].x = 4;
              if (mal[i].y > mapSize[mal[i].x]) {
                  mal[i].y = mal[i].y - mapSize[mal[i].x];
                  mal[i].x = 5;
                  if (mal[i].y > 2) {
                      mal[i].y = 2;
                  }
              }
        }
        else {
             mal[i].y += arr[curr]; 
        }
    }
    else if (mal[i].x == 0 || mal[i].x == 4) {
        if (mal[i].x == 4 ){
            if (mal[i].y + arr[curr] > mapSize[mal[i].x]) {
                mal[i].y = arr[curr] - (mapSize[mal[i].x] - mal[i].y);
                mal[i].x = 5;
                if (mal[i].y > 2) {
                    mal[i].y = 2;
                }
            }
            else {
                mal[i].y += arr[curr];
            }
        }else if (mal[i].x == 0) {
            if (map[mal[i].x][mal[i].y] % 10 == 0 && mal[i].y != 0) {

                mal[i].x = map[mal[i].x][mal[i].y] / 10;
                mal[i].y = 0;

                if (mal[i].y + arr[curr] > mapSize[mal[i].x]) {
                    mal[i].y = arr[curr] - (mapSize[mal[i].x] - mal[i].y);
                    mal[i].x = 4;
                }
                else {
                    mal[i].y += arr[curr];
                }
                
            }
            else if (mal[i].y + arr[curr] > mapSize[mal[i].x]) {
                mal[i].y = arr[curr] - (mapSize[mal[i].x] - mal[i].y);
                mal[i].x = 5;
                if (mal[i].y > 2) {
                    mal[i].y = 2;
                }
            }
            else{
                mal[i].y += arr[curr];
            }
        }

    }
    else if (mal[i].x == 5) {
        mal[i].y = arr[curr] + mal[i].y;
        if (mal[i].y > 2) {
            mal[i].y = 2;
        }
        
    }



}
//mal[i].x > 말의 배열 번째 
//mal[i].y > 말의 구체적 번째 수
int dfs(int curr, int score) {
    if (curr == 10) {
        return score;
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int mapX = mal[i].x;
        int mapY = mal[i].y;

        if (mal[i].y == 2 && mal[i].x == 5) continue;
      
        vis[mal[i].x][mal[i].y] = 0;

        move(i,curr);

        if (vis[mal[i].x][mal[i].y] == 1) {
            mal[i].x = mapX;
            mal[i].y = mapY;
            vis[mal[i].x][mal[i].y] = 1;
            continue;
        }

        vis[mal[i].x][mal[i].y] = 1;
        if (mal[i].y == 2 && mal[i].x == 5) {
            vis[mal[i].x][mal[i].y] = 0;
        }

        ret = max(ret, dfs(curr + 1, score + map[mal[i].x][mal[i].y]));

        vis[mal[i].x][mal[i].y] = 0;
        mal[i].x = mapX;
        mal[i].y = mapY;
        vis[mal[i].x][mal[i].y] = 1;
    }

    return ret;
 
}
int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++) {
        mal[i].x = 0;
        mal[i].y = 0;
    }

    printf("%d", dfs(0, 0));

}