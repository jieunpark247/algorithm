//
//  1949.cpp
//  Project
//
//  Created by Ji-Eun Park on 2018. 10. 16..
//  Copyright © 2018년 Ji-Eun Park. All rights reserved.
//  등산로 조성 (againg)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,K, map[10][10], temp[10][10];;
int ans;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector <pair<int, int> >topV;
queue<pair<pair<int, int>,int > > q;
void init(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            map[i][j]=0;
        }
    }
    topV.clear();
    
}
void tempinit(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            temp[i][j]=map[i][j];
        }
    }
}
bool isRange(int x, int y){
    return x>=0 && y>=0 && x<n && y<n;
}
void solve(){
    for(int v=0;v<topV.size();v++){
        int i=topV[v].first;
        int j=topV[v].second;
            q.push(make_pair(make_pair(i, j), 1));
            
            while(!q.empty()){
           
                int cx = q.front().first.first;
                int cy = q.front().first.second;
                int cnt=q.front().second;
                q.pop();
              
                if(cnt>ans)
                    ans=cnt;
                for(int a=0;a<4;a++){
                    int nx = cx+dx[a];
                    int ny = cy+dy[a];
                    
                    if(temp[nx][ny] < temp[cx][cy] && isRange(nx,ny)){
                        q.push(make_pair(make_pair(nx, ny), cnt+1));
                    }
                }
            
       
            }
            
            
        }
    
}
int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        init();
        cin>>n>>K;
        int top=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
                if(map[i][j]>top){
                    top=map[i][j];
                }
            }
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(map[i][j]==top)
                    topV.push_back(make_pair(i, j));
             
        ans =0;
        for(int k=0;k<=K;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    tempinit();
                    temp[i][j] = temp[i][j]- k;
                    
                        solve();
           //         cout<<i<<j<<ans<<'\n';;
                }}}
        cout<<"#"<<t<<" "<<ans<<endl;
    }
}
