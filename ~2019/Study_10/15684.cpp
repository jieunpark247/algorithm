//
//  15684.cpp
//  Project
//
//  Created by Ji-Eun Park on 2018. 10. 17..
//  Copyright © 2018년 Ji-Eun Park. All rights reserved.
// 사다리 조작
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <memory.h>
using namespace std;

int n,m,h;
int map[11][31];
int visited[11][31];
int a,b;
int d[3]={0,1,-1};//->1 , <-2
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans;
bool flag;

void init(){
    for(int i=0;i<31;i++){
        for(int j=0;j<11;j++){
            map[j][i]=0;
            visited[j][i]=0;
        }
    }
}
bool isRange(int x ,int y){
    return x>=1 &&y>=1&&x<=n&&y<=h;
}
void goladder(int hi){
    if(hi==h+1){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(visited[i][h] == i)
                cnt++;
           
        if(cnt==n)
            flag = true;
        else
            flag=false;
        return;
    }
    
      for(int j=1;j<=n;j++){
             if(map[j][hi]==1){
                 visited[j+1][hi]=visited[j][hi-1];
             }else if(map[j][hi]==2){
                 visited[j-1][hi]=visited[j][hi-1];
             }else if(map[j][hi]==0){
                 visited[j][hi]=visited[j][hi-1];
             }
      }
    
    goladder(hi+1);
  
  
}

void makeLadder(int ladder,int x, int y){
  
    for(int i=1;i<31;i++)
        for(int j=1;j<11;j++)
            visited[j][i]=0;
    
    goladder(1);
    if(flag==1){
        ans=ladder;
        return;
      
    }
    if (ans >= 0&&ans<987654320)
        return;
    if(ladder==3){
        return;
    }
    int temp[31][31];
    memcpy(temp, map, sizeof(temp));
    
    for(int i=y;i<=h;i++){
        for(int j=1;j<=n;j++){
          
            if(map[j][i]==0 &&map[j+1][i]==0 && isRange(j ,i)&&isRange(j+1, i)){

                map[j][i]=1; map[j+1][i]=2;

                makeLadder(ladder+1 ,j+2 ,i);

                memcpy(map, temp, sizeof(map));
            }
        }
    }

    
    
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>h;
    for(int i=1;i<=n;i++){
        visited[i][0]=i;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        map[b][a]=1; map[b+1][a]=2;
    }
    
    ans = 987654321;
    flag=true;
    makeLadder(0,1,1);
    if(ans==987654321)
        ans=-1;
    
    cout<<ans<<endl;
}
