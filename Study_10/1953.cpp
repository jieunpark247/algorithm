//
//  1953.cpp
//  Project
//  탈주범 검거 (고침)
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n,m,r,c,l;
int map[52][52];
int visited[52][52];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector <int> tunnel[8];
queue <pair<pair<int,int>,int>> q;
int pos[4]={2,3,0,1}; // 0-2 , 3-1 로 짝지어져있어야 이동 가능
void init(){
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            visited[i][j]=0;
            map[i][j]=0;
        }
    }
}
bool isRange(int x,int y){
    return (x>=0 && x<n) && (y>=0 && y<m);
}
bool isPossible(int nx, int ny,int dir){
    int after = map[nx][ny];
    for(int d=0;d<tunnel[after].size();d++){
        if(pos[dir]==tunnel[after][d])
            return true;
    }
        
        return false;

}
void solve(int cx , int cy , int ctime){


    q.push(make_pair(make_pair(cx, cy), 1));
    visited[cx][cy]=1;
   
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        q.pop();
      
        for(int i=0;i<tunnel[map[x][y]].size();i++){
            
            int dir = tunnel[map[x][y]][i];
            int nx = x + dx[dir];
            int ny = y + dy[dir];
          
              if(time!=l){
                  if(map[nx][ny]>0 && isRange(nx, ny) && isPossible(nx,ny,dir)&&visited[nx][ny]==0){
                      visited[nx][ny]=1;
                      q.push(make_pair(make_pair(nx, ny), time+1));
   
                      }
                  }
        }
        
    }
}
int main(){
    int testcase;
    cin>>testcase;
    tunnel[0].push_back(-1);
    tunnel[1].push_back(0);  tunnel[1].push_back(1);  tunnel[1].push_back(2);  tunnel[1].push_back(3);
    tunnel[2].push_back(0);  tunnel[2].push_back(2);
    tunnel[3].push_back(1);  tunnel[3].push_back(3);
    tunnel[4].push_back(0);  tunnel[4].push_back(1);
    tunnel[5].push_back(1);  tunnel[5].push_back(2);
    tunnel[6].push_back(2);  tunnel[6].push_back(3);
    tunnel[7].push_back(0);  tunnel[7].push_back(3);
    for(int t=1;t<=testcase;t++){
        cin>>n>>m>>r>>c>>l;
        init();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>map[i][j];
       
        int cnt=0;
        
        solve(r,c,l);

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(visited[i][j]==1)
                    cnt++;
        
        cout<<"#"<<t<<" "<<cnt<<endl;
    }
}
