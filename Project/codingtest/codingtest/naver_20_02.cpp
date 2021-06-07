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
        if (map[curr][i][0] == 1 && map[curr][i][1] != x && map[curr][i][1] != y && vis[i] != 1) { //간선이 연결되어있는지
            vis[i] = 1; // 방문체크
            ret += dfs(i, x, y); // 연결된 노드로 이동, 리턴할때 +1 해줌 
        }
    }
    return ret;
}

vector<int> solution(int N, vector<vector<int> > v) {
    vector<int> ans;
    n = N;

    for (int i = 0; i < n - 1; i++) {
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
                    int tmp = dfs(k, i, j); // 자른 간선이 i , j 현재 내가 위치한 노드 k
                    if (tmp != n / 3) { // 연결된 노드가 N/3인지 확인 
                        break;
                    }
                    cnt++; // 3개로 트리 나눔
                }
            }
            if (cnt == 3) { // 세부분으로 나뉘었으면
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