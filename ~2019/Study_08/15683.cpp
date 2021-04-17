//
//  15683.cpp
//  Project
#include<iostream>
#include<vector>
#define min(a,b) (a < b ? a : b)
using namespace std;
#define MAX 987654321;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector <int > v;
vector < pair < int, int > > cctv; //백터 생성
int map[8][8], N, M;
int min_R; // 최소 횟수 초기화


void CCTV(int x, int y, int dir) { // 0이면 dir방향에 따라서 다음 수로 이동하는 함수 만들기
    
    if (y < 0 || x >= M || x < 0 || y >= N)
        return;
    if (map[y][x] == 6)
        return;
    if (map[y][x] == 0)
        map[y][x] = 9;
    
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    
    CCTV(nx, ny, dir); //재귀로 돌려서 계속 이동하게 한다.
    
    
}


void dfs(int num) // 0부터 cctv 크기만큼
{
    
    if (num == (int)cctv.size()) { // road가 size크기랑 같다면 최솟값 추출
        
        
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] == 0)
                    cnt = cnt + 1;
        
        if (cnt < min_R)
            min_R = cnt;
        
        return;
        
    }
    
    // 아니면? #표시 해줘야지
    int y = cctv[num].first; // cctv vector에서 xy 넣어줌 0과 6이 아닌 값들의 ㄷ좌표
    int x = cctv[num].second; // 12345가 나올 수 있지
    
    int kind = v[num]; // 12345 종류 가나오는 map[][]의 숫자를 int 변수에 넣어준다.
    int map2[8][8];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            map2[i][j] = map[i][j];
    
    
    if (kind == 1) {
        for (int dir = 0; dir < 4; dir++)
        {
            
            
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            CCTV(nx, ny, dir);
            dfs(num + 1); // 횟수 추가해주기
            
            
            
            //map 원상태로 복귀
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    map[i][j] = map2[i][j];
            
            
        }
    }
    else if (kind == 2) {
        for (int dir = 0; dir < 2; dir++)
        {
            
            
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            CCTV(nx, ny, dir);
            CCTV(x + dx[dir + 2], y + dy[dir + 2], dir + 2);
            
            
            dfs(num + 1); // 횟수 추가해주기
            
            
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    map[i][j] = map2[i][j];
        }
    }
    else if (kind == 3) {
        
        for (int dir = 0; dir < 4; dir++)
        {
            
            
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            CCTV(nx, ny, dir);
            
            int nextD = (dir + 1) % 4;
            CCTV(x + dx[nextD], y + dy[nextD], nextD);
            dfs(num + 1); // 횟수 추가해주기
            
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    map[i][j] = map2[i][j];
        }
    }
    else if (kind == 4)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            
            
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            CCTV(nx, ny, dir);
            int nextD = (dir + 1) % 4;
            CCTV(x + dx[nextD], y + dy[nextD], nextD);
            
            nextD = (dir + 2) % 4;
            CCTV(x + dx[nextD], y + dy[nextD], nextD);
            
            
            dfs(num + 1); // 횟수 추가해주기
            
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    map[i][j] = map2[i][j];
        }
    }else{
        for (int dir = 0; dir < 4; dir++) {
            
            
            
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            CCTV(nx, ny, dir);
        }
        
        
        dfs(num + 1); // 횟수 추가해주기
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                map[i][j] = map2[i][j];
        
        
        
    }
    
    
    
}
int main()
{
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6) {
                v.push_back(map[i][j]);
                cctv.push_back(make_pair(i, j));
            }
            
        }
    }
    
    min_R = MAX;
    
    dfs(0);
    
    
    cout << min_R << endl;;
    
    return 0;
}
