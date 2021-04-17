#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

int N;
int map[21][21];
int vis[21][21];
int sx, sy, sny, snx, curr_size;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int minVal;
int time, ti;
int eatFish;
queue<pair<pair<int, int>,pair<int, int>>> q;
void bfs() {
    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;

        int t = q.front().second.first;
        int size = q.front().second.second;
        q.pop();

        if (map[x][y] < size && map[x][y] != 0 && map[x][y] != 9) {
            if (t < minVal) {
                minVal = t;
                ti = t;
                sx = x, sy = y;
            }
            else if (t == minVal) {
                if (sx > x)
                    sx = x, sy = y;
                else if (sx == x)
                    if (sy > y)
                        sx = x, sy = y;
                ti = t;
            }
            continue;
        }

        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < N && ny < N && nx >= 0 && ny >= 0 && vis[nx][ny] == 0 && map[nx][ny] <= size) {
                vis[nx][ny] = 1;
                q.push({ {nx,ny},{t+1,size} });
            }

        }


    }

}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                sx = i; sy = j;
                map[i][j] = 0;
            }
        }
    }
    time = 0;
    int size = 2;
    eatFish = 0;

    while (-1) {
        snx = sx, sny = sy;
        minVal = 987654321;
        memset(vis, 0, sizeof(vis));
        vis[snx][sny] = 1;
        q.push({ {snx,sny},{0,size} });
        bfs();
        if (snx == sx && sny == sy) break;
        time += ti;
        eatFish = eatFish + 1;
        if (eatFish == size) {
            size++;
            eatFish = 0;
        }
        map[sx][sy] = 0;
    }

    printf("%d", time);

}