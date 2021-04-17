#include<iostream>
#include<stdio.h>

using namespace std;

#define MAX 987654321;
int map[9][10];
int k,jj;
int type[102], times[102];
int ans;
int dir[6];
int t1, t2;
int temp,tmp;
void solve(int t1,int t2) {//t1은+ 방향 t2는 - 방향으로 가준다.

    
    if (t1>4 && t2<1) // t1(+),2(-) 가 4보다 크거나 1보다 작으면 리턴
        return;
    
    
    if (dir[t1] != 0) { //t1 의 방향이 0아니면
        if (t1+1 < 5) { // 바퀴수가 4개 -> 5보다 작아야함
            if (map[t1][3] == map[t1 + 1][7]) { //비교 작은3번째 vs 큰7번째
                dir[t1 + 1] = 0;                //같으면 0

            }
            else {
                dir[t1 + 1] = dir[t1] * -1; //다르면 반대방향 -1곱해줌

            }
        }
    }
    
    else if (dir[t1] == 0) {//t1 의 방향이 0이면 t1의 바퀴가 안돌아 가므로 그 다음바퀴+1 도 돌아가지 않는다.
        if (t1 + 1 < 5) { //t1+1이 5보다 커야 한다
            dir[t1 + 1] = 0;    //다음 바퀴도 돌아가지 않음
            
        }
    }
//========t1
    
    if (dir[t2] != 0) {
        if (t2-1  > 0) {
            if (map[t2][7] == map[t2 - 1][3]) {
                dir[t2 - 1] = 0;
                
                
                
            }
            else {
                dir[t2 - 1] = dir[t2] * -1;
                
                
                
            }
            
        }
    }
    else if (dir[t2] == 0){
        if (t2 - 1 > 0){
            dir[t2 - 1] = 0;
            
        }
    }
//============t2
    solve(t1 + 1, t2 - 1);
}


int main() {
  
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 8; j++)
            scanf("%1d",&map[i][j]);
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> type[i] >> times[i];
    }
    //입력
    
    ans = 0;
    
    for (int i = 1; i <= k; i++) {
        for (int i = 0; i <= 4; i++)
            dir[i] = MAX;
        
        dir[type[i]] = times[i]; //dir 배열에 회전방향 넣어줌
        t1 = t2 = type[i]; // t1,2를 시작하는 위치에 초기화 해줌
        solve(t1,t2);
        
        
        for (int i = 1; i <= 4; i++) { //i를 4번 돌려줌
            tmp = map[i][1];
            
            if (dir[i] == 1) { // 1이라면?
                for (int j = 1; j <= 8; j++) {
                    
                    jj = j + dir[i];
                    if (jj == 9) {
                        jj = 1;
                    }
                    temp = map[i][jj];
                    map[i][jj] = tmp;
                    tmp = temp;
                    //오른쪽으로 돌아감
                }
            }
            else if (dir[i] == -1) { //-1 이라면?
                tmp = map[i][8];
                for (int j = 8; j > 0; j--) {
                    
                    jj = j + dir[i];
                    if (jj == 0) {
                        jj = 8;
                    }
                    temp = map[i][jj];
                    map[i][jj] = tmp;
                    tmp = temp;
                    //왼쪽으로 돌아감
                }
            }
  
        }
    }
    
    if (map[1][1] == 1)
        ans = ans + 1;
    if (map[2][1] == 1)
        ans = ans + 2;
    if (map[3][1] == 1)
        ans = ans + 4;
    if (map[4][1] == 1)
        ans = ans + 8;
    //각각 바퀴번호에 따라 더해줌
    
    cout << ans << endl;
    
}
