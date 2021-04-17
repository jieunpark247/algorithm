//
//  15683.cpp
//  Project
//
//  Created by Ji-Eun Park on 2018. 10. 17..
//  Copyright © 2018년 Ji-Eun Park. All rights reserved.
// 감시 CCTV not complete
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <memory.h>
using namespace std;
vector<pair<pair<int,int>,int>> cctv;

int n,m, map[10][10];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt,ans;

bool isRange(int x,int y){
    return x>=0&&y>=0&&x<n&&y<m;
}
void go(int x, int y,int i){
    //while (true) {

        if(!isRange(x, y) || map[x][y]==6)
            return;
   
        if(map[x][y]==0)
            map[x][y]=7;
        
    int nx = x+dx[i];
    int ny = y+dy[i];
    go(nx,ny,i);
        
   // }
}

void solve(int c,int dir){
    if(c==cctv.size()){
        cnt =0;
        for(int i =0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j] == 0)
                    cnt++;
        
        if(cnt<ans)
            ans=cnt;
        
        return;
    }
    int x = cctv[c].first.first;
    int y = cctv[c].first.second;
    
    int temp[10][10];
    memcpy(temp, map, sizeof(temp));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = map[i][j];
    switch (dir) {
        case 1:
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                go(nx,ny, i);
                solve(c+1,cctv[c+1].second);
                memcpy(map, temp, sizeof(map));
               
            }
            break;
            
        case 2:
            for(int i=0;i<2;i++){

                go(x+dx[i],y+dy[i], i); go(x+dx[(i+2)],y+dy[(i+2)], (i+2));
                solve(c+1,cctv[c+1].second);
                memcpy(map, temp, sizeof(map));
         
               
            }
            break;
            
        case 3:
            for(int i=0;i<4;i++){

                go(x+dx[i],y+dy[i], i); go(x+dx[(i+1)%4],y+dy[(i+1)%4], (i+1)%4);
                solve(c+1,cctv[c+1].second);
                memcpy(map, temp, sizeof(map));
              
            }
            break;
            
        case 4:
            for(int i=0;i<4;i++){

                go(x+dx[i],y+dy[i], i); go(x+dx[(i+2)%4],y+dy[(i+2)%4], (i+2)%4); go(x+dx[(i+1)%4],y+dy[(i+1)%4], (i+1)%4);
                solve(c+1,cctv[c+1].second);
               memcpy(map, temp, sizeof(map));
          
            }
            break;
            
        case 5:
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                go(nx,ny, i);
                }
            
            solve(c+1,cctv[c+1].second);
            memcpy(map, temp, sizeof(map));
          
            break;
        
    }
}

int main(){
    cin>>n>>m;
    cctv.clear();
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]!=0 && map[i][j]!=6){
                cctv.push_back(make_pair(make_pair(i, j), map[i][j]));
            }
        }
    }
    
    ans=987654321;
    if(cctv.size()!=0){ //cctv사이즈 !!!!!! 없을 때 고려하기 
    solve(0,cctv[0].second);
    }else{
        solve(0,0);
    }
    cout<<ans<<endl;
    
}
