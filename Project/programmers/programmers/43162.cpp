//네트워크
#include <string>
#include <vector>

using namespace std;
int map[202];
int cnt;
int visited[201][201];
void dfs(int target,int n, vector<vector<int>> computers) {
    map[target] = cnt;
    for (int i = 0; i < n; i++) {
        if (computers[target][i] == 1 && target != i && visited[target][i] == 0) {
            visited[target][i] = visited[i][target] = 1;
            dfs(i, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (map[i] == 0) {
            cnt++;
            dfs( i, n, computers);
        }
    }
    answer = cnt;
    return answer;
}

int main() {
    vector<vector<int>> c;
    // [[1, 0, 1, 1, 0, 0], [0, 1, 0, 0, 1, 1], [1, 0, 1, 1, 1, 1], [1, 0, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]
    c.push_back({ 1, 0, 1, 1, 0, 0 });
    c.push_back({ 0, 1, 0, 0, 1, 1 });
    c.push_back({ 1, 0, 1, 1, 1, 1 });
    c.push_back({ 1, 0, 1, 1, 1, 1 });
    c.push_back({ 0, 1, 1, 1, 1, 1 });
    c.push_back({ 0, 1, 1, 1, 1, 1 });
 
    solution(6, c);
    return 0;
}