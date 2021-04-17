#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


int map[101][101][2] = { 0, };
int vis[101];
int n;

int dfs(int curr, int x, int y) {
    vis[curr] = 1;
    int ret = 1;
    for (int i = 0; i < n; i++) {
        if (map[curr][i][0] == 1 && map[curr][i][1] != x && map[curr][i][1] != y && vis[i] != 1) {
            vis[i] = 1;
            ret += dfs(i, x, y);
        }
    }
    return ret;
}

vector<int> solution(int N, vector<vector<int> > v) {
    vector<int> ans;
    n = N;

    for (int i = 0; i < n-1; i++) {
        int x = v[i][0];
        int y = v[i][1];
        map[x][y][0] = map[y][x][0] = 1;
        map[x][y][1] = map[y][x][1] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            memset(vis, 0, sizeof(vis));
            for (int k = 0; k < n; k++) {
                if (vis[k] == 0) {
                    int tmp = dfs(k, i, j);
                    if (tmp != n / 3) {
                        break;
                    }
                    cnt++;
                }
            }
            if (cnt == 3) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }

        }
    }

    return ans;
}

int main() {

    vector < vector<int> > v;
    v.resize(8);
    v[0].push_back(0);
    v[0].push_back(2);
    v[1].push_back(2);
    v[1].push_back(1);
    v[2].push_back(2);
    v[2].push_back(4);
    v[3].push_back(3);
    v[3].push_back(5);
    v[4].push_back(5);
    v[4].push_back(4);
    v[5].push_back(5);
    v[5].push_back(7);
    v[6].push_back(7);
    v[6].push_back(6);
    v[7].push_back(6);
    v[7].push_back(8);
    solution(9, v);
    return 0;
}