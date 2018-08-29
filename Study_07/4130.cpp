//4130
//특이한 자석
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
void init() {
    for (int i = 1; i <=9; i++)
        for (int j = 1; j <= 10; j++)
            map[i][j] == 0;
    for (int i = 1; i <= 102; i++) {
        type[i] = 0;
        times[i] = 0;
    }
}
void solve(int t1,int t2) {
    
    if (t1>4 && t2<1)
        return;
    
    
    if (dir[t1] != 0) {
        if (t1+1 < 5) {
            if (map[t1][3] == map[t1 + 1][7]) {
                dir[t1 + 1] = 0;
                
                
            }
            else {
                dir[t1 + 1] = dir[t1] * -1;
                
                
            }
        }
    }
    else if (dir[t1] == 0) {
        if (t1 + 1 < 5) {
            dir[t1 + 1] = 0;
            
        }
    }
    
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
    
    solve(t1 + 1, t2 - 1);
}


int main() {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        init();
        cin >> k;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 8; j++)
                scanf("%1d", &map[i][j]);
        
        for (int i = 1; i <= k; i++) {
            cin >> type[i] >> times[i];
        }
        
        
        ans = 0;
        
        for (int i = 1; i <= k; i++) {
            for (int i = 0; i <= 4; i++)
                dir[i] = MAX;
            dir[type[i]] = times[i];
            t1 = t2 = type[i];
            solve(t1, t2);
            
            
            for (int i = 1; i <= 4; i++) {
                tmp = map[i][1];
                if (dir[i] == 1) {
                    for (int j = 1; j <= 8; j++) {
                        
                        jj = j + dir[i];
                        if (jj == 9) {
                            jj = 1;
                        }
                        
                        temp = map[i][jj];
                        map[i][jj] = tmp;
                        tmp = temp;
                        
                    }
                }
                else if (dir[i] == -1) {
                    tmp = map[i][8];
                    for (int j = 8; j > 0; j--) {
                        
                        jj = j + dir[i];
                        if (jj == 0) {
                            jj = 8;
                        }
                        temp = map[i][jj];
                        map[i][jj] = tmp;
                        tmp = temp;
                        
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
        
        
        cout <<"#"<<t<<" "<< ans << endl;
    }
}
