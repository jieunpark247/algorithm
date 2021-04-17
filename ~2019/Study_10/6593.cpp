//
//  6593.cpp
//  Project
//
//  Created by Ji-Eun Park on 2018. 10. 18..
//  Copyright © 2018년 Ji-Eun Park. All rights reserved.
//상범빌딩
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <memory.h>

using namespace std;
#define INF 987654321
struct node{
    int x,  y, z,cnt;
};
int L,R,C;
char map[33][33][33];
int visited[33][33][33];
int ans;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
queue<node> q;
int sx,sy,sz;
void cleanQueue(queue<node> &clean){
    queue<node> qqq;
    swap(clean,qqq);
    
}
bool isRange(int x, int y,int z){
    return (x>=0&&x<C&&y>=0&&y<R&&z>=0&&z<L);
}
void init(){
    for(int z=0;z<32;z++){
        for(int i=0;i<32;i++){
            for(int j=0;j<32;j++){
                visited[j][i][z]=0;
                map[j][i][z]='0';
            }
        }
    }
}

void solve(){

    q.push({sx,sy,sz});
    while(!q.empty()){
        node s= q.front();
        
        if(map[s.x][s.y][s.z]=='E'){
           // ans = visited[s.x][s.y][s.z];
            ans= min(s.cnt,ans);
        }
        q.pop();
        for(int i=0;i<6;i++){
            int nx = s.x +dx[i];
            int ny = s.y+ dy[i];
            int nz = s.z+ dz[i];
               int ncnt=s.cnt;
            if((map[nx][ny][nz]=='.'||map[nx][ny][nz]=='E') && visited[nx][ny][nz]==0&&isRange(nx,ny,nz)){
              //  visited[nx][ny][nz]= visited[s.x][s.y][s.z]+1;
                visited[nx][ny][nz]=1;
                q.push({nx,ny,nz,ncnt+1});
                
            }
        }
    }
}
int main(){
    while(true){
        
        cin>>L>>R>>C;
        if(L==0 && R==0 &&C==0)
            break;
         cleanQueue(q);
        init();
        for(int z=0;z<L;z++){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cin>>map[j][i][z];
                    if(map[j][i][z] == 'S'){
                        sx=j;sy=i;sz=z;
                    }
                }
            }
        }
        ans =INF;
        solve();
        // cout<<endl;
       
        if(ans==INF)
            cout<<"Trapped!"<<endl;
        else
            cout <<"Escaped in "<< ans << " minute(s)."<<endl;
        
    }
    return 0;
    
}

