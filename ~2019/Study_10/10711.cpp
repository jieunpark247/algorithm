//
//  10711.cpp
//  Project
//  모래성

#include <iostream>
#include <string>
#include<vector>
#include <stdio.h>
#include <string>
#include<algorithm>
#include<queue>
using namespace std;
int dx[8] = {1 , -1 , 0 , 0 , -1 , -1 , 1 , 1}; // 오 왼 위 아 왼위 왼아 오아 오위
int dy[8] = {0 , 0 , 1 , -1 , -1 , 1 , -1 , 1};
int h,w;
char map2[1001][1001];
int map[1001][1001];
int checked[1001][1001];
int temp[1001][1001];
int cnt;
int ans;

queue < pair < pair < int , int >, int > > q;
queue <  pair < int , int > > qq;

void sandCheck(int x , int y){
    cnt=0;
    for(int a=0;a<8;a++){
        // cnt=0;
        int nx = x + dx[a];
        int ny = y + dy[a];
        if(nx>=0&&ny>=0&&nx<h&&ny<w){
            if(map[nx][ny] == 0){
                cnt++;
                
            }
        }
    }
    checked[x][y]=cnt;
    temp[x][y]=cnt;
    
}
void detailCheck(int x , int y){
    
    
    map[x][y]=0;
    
    
    while(!q.empty()){
        
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int c = q.front().second;
        ans = max(c,ans);
        
        
        q.pop();
        for(int a=0;a<8;a++){
            int nx = cx+dx[a];
            int ny = cy+dy[a];
            
            
            checked[nx][ny]=checked[nx][ny]+1;
            
            
            if(nx>=0&&ny>=0&&nx<h;ny<w){
                if(checked[nx][ny]>=map[nx][ny] && map[nx][ny]!=0 ){
                    
                    q.push(make_pair(make_pair(nx, ny),c+1));
                    
                    map[nx][ny]=0;
                }
            }
        }
    }
}

int main()
{
    cin>>h>>w;
    
    for(int i =0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>map2[i][j];
    
    
    for(int i =0;i<h;i++)
        for(int j=0;j<w;j++)
            if(map2[i][j]=='.')
                map[i][j] = 0;
            else
                map[i][j]=map2[i][j]-'0';
    
    
    for(int i =0;i<h;i++)
        for(int j=0;j<w;j++)
            if(map[i][j]>0)
                sandCheck(i,j);

    
    for(int i =0;i<h;i++)
        for(int j=0;j<w;j++)
            if(map[i][j]!=0 && temp[i][j]>=map[i][j]){
                q.push(make_pair(make_pair(i, j),1));
                map[i][j]=0;
            }
    
    for(int i=0;i<q.size();i++)
        detailCheck(q.front().first.first, q.front().first.second);

    
    cout<<ans<<endl;
}

