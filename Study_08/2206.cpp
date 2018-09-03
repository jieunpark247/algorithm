//
//  2206.cpp
//  Project

#include <iostream>
#include<queue>
#include <string.h>
#include <vector>
#define min(a,b)(a < b ? a : b)
using namespace std;
#define MAX 987654321

int n,m;
int map[1002][1002];
int visited[1002][1002][2];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans,res;


void bfs(int x, int y, int cnt){

    queue  < pair < int, int >>  q;
    queue < pair < int, int > >checkc;
    q.push(make_pair(x, y));
    checkc.push(make_pair(1, cnt));
    
    
    while(!q.empty()){
        int cx = q.front().first; //x값
        int cy = q.front().second; //y값
        int checked = checkc.front().first;
        int ccnt = checkc.front().second;
        //   cout<<"XY: "<<cx<<cy<<'\n';
        //    cout<<"ccnt: "<<ccnt<<" "<<checked<< '\n';;
     
        if(cx==n-1 && cy==m-1){
            ans=ccnt;
            res= min(ans,res);
   
        }

        q.pop();
        checkc.pop();
        
        for(int i =0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(visited[nx][ny][0]==0&&map[nx][ny]==0&&checked==1){
                    q.push(make_pair(nx, ny));
                    checkc.push(make_pair(1, ccnt+1));
                    visited[nx][ny][0]=1;
                       
                }else if(visited[nx][ny][1]==0 &&map[nx][ny]== 1 && checked == 1 ){
                        q.push(make_pair(nx, ny));
                        checkc.push(make_pair(0, ccnt+1));
                        visited[nx][ny][1]=1;
                }else if(visited[nx][ny][1]==0 && map[nx][ny]== 0 && checked == 0){
                         q.push(make_pair(nx, ny));
                         checkc.push(make_pair(0, ccnt+1));
                        visited[nx][ny][1]=1;
                    }
                }
        }
    }
}
   





int main(){
    
    cin>>n>>m;
    
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            scanf("%1d",&map[i][j]);

    res=MAX;
    ans=MAX;

    bfs(0,0,1);
    
    if(res==MAX)
        res=-1;
    
    cout<<res<<endl;
    
    return 0;
    
    }
    

