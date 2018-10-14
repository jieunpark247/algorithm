//
//  6087.cpp
//  Project
//  레이저 통신
//

#include<iostream>
#include<queue>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
char temp[101][101];
int map[101][101];
int visited[101][101];
vector < pair < int, int > > laser;
int ans;
int w,h;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
queue < pair < pair < int,int>, pair < int, int >  > > q;
void solve(int x, int y ,int cnt){
    int d=-1;
    q.push(make_pair(make_pair(cnt,d),make_pair(x,y)));
    visited[x][y]=1;
    int a = laser[1].first; int b = laser[1].second;
    while(!q.empty()){
        int cx= q.front().second.first;
        int cy= q.front().second.second;
        int ccnt= q.front().first.first;
        int dir = q.front().first.second;
        
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx<w && ny<h){
                if(map[nx][ny]==0 && visited[nx][ny]==0){
                    if(dir!=i && dir>=0) // -1 -> (x) , 전 방향과 비교 바뀌면 +1
                        ccnt= ccnt+1;
                    
                    if(nx == a && ny == b){
                        ans= min(ans,ccnt);
                    }else{
                        q.push(make_pair(make_pair(ccnt ,i), make_pair(nx, ny)));
                        visited[nx][ny]=1;
                    }
                }
            }
        }
        
    }
}
int main(){
    cin>>w>>h;
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>temp[j][i];
            if(temp[j][i]=='*'){
                map[j][i]=1;
            }else if(temp[j][i]=='.'){
                map[j][i]=0;
            }else if(temp[j][i]=='C'){
                map[j][i]=2;
                laser.push_back(make_pair(j, i));
            }
        }
    }
    // (3: /)  (4 : \)
    //    for(int i=0;i<h;i++){
    //        cout<<'\n';
    //        for(int j=0;j<w;j++){
    //            cout<<map[j][i];
    //        }
    //    }
    //
    //    for(int i=0;i<h;i++){
    //        cout<<'\n';
    //        for(int j=0;j<w;j++){
    //            cout<<temp[j][i];
    //        }
    //    }
    ans =INF;
    int a;
    a=laser[0].first;
    int b;
    b=laser[0].second;
    solve(a,b,0);
    
    cout<<ans;
}
