//
//  2105.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 9. 9..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//

#include <iostream>
using namespace std;
#define max(a,b) (a>b ? a:b)
int map[21][21];
int dessert[101];
int visited[21][21];
int n;
int ans,cnt,c;
int w,h;
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,-1,1};
int fixX,fixY;
int dirCnt[4];
bool is_range(int x, int y){
    return(x>=0&&x<n&&y>=0&&y<n);
}
void solve(int x,int y,int cnt,int d){
  
    if(x==fixX && y==fixY && cnt > 1){
        c=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(visited[i][j]==1)
                    c=c+1;
           ans=max(c,ans);
        return;
    }
    
    if(is_range(x, y)==false)
        return;
    if(dessert[map[x][y]]== 1 )
        return;
    if(visited[x][y]==1)
        return;
    
    
    
    for(int dir=d;dir<4;dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dessert[map[x][y]]=1;
        visited[x][y]=1;
        solve(nx, ny, cnt+1, dir);
        visited[x][y]=0;
        dessert[map[x][y]]=0;
        cnt=cnt-1;

        
    }
    
}
int main(){
    int testcase;
    cin>>testcase;
    
    for(int t=1;t<=testcase;t++){
        ans=-1;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>map[i][j];
      
        cnt=1;
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
        
                for(int i =0 ;i<=100;i++)
                    dessert[i]=0;
                for(int i =0 ;i<4;i++)
                    dirCnt[i]=0;
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        visited[i][j]=0;
        
                
                fixX= i; fixY=j;
                solve(i, j,cnt,0);
                
            }
        }
        
     
        
        
        cout<<"#"<<t<<" "<<ans<<endl;
        
        
        
        
    }
}
