//
//  6593.cpp
//  Project
// 상범빌딩
// 다익스트라

#include <iostream>
#include<queue>
#include <vector>

using namespace std;
#define INF 987654321
#define MAX 27001

int L,R,C;
int v;
char map[33][33][33];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int checked[33][33][33];
int start;
int end_;
int ans;
int sl,sr,sc;
void bfs(int z,int x, int y){
    

  queue < pair < pair < int, int >, int > > q;
    
    q.push(make_pair(make_pair(x, y), z));
 
    
    while(!q.empty()){
        
      
        int cx = q.front().first.first; //x값
        int cy = q.front().first.second; //y값
        int cz = q.front().second;
        
        if(map[cz][cx][cy]=='E'){
            ans=checked[cz][cx][cy];
        }
        
        q.pop();
     
        for(int i =0;i<6;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            int nz = cz+dz[i];
            if(nz>0 && nx>0 && ny>0 && nz<=L && nx<=R && ny<=C){
                if(checked[nz][nx][ny]==0&& (map[nz][nx][ny]=='.' || map[nz][nx][ny]=='E')){
                    q.push(make_pair(make_pair(nx, ny), nz));
                    checked[nz][nx][ny]=checked[cz][cx][cy]+1;
            }
        }

    }
    
    
    }

    
 

}




int main(){
    
    while(true){
        cin>>L>>R>>C;
        if(L==0 && R==0 && C==0)
            break;
       
        v=1;
        ans = INF;
        for(int l=0;l<=L;l++){
            for(int r=0;r<=R;r++){
                for(int c=0;c<=C;c++){
                    map[l][r][c]='0';
                    checked[l][r][c]=0;
                }}}
        
       for(int l=1;l<=L;l++){
            for(int r=1;r<=R;r++){
                for(int c=1;c<=C;c++){
                    cin>>map[l][r][c];
                    
                    if(map[l][r][c]=='S'){
                        sl=l;sr=r;sc=c;
                        
                    }else if(map[l][r][c]=='E'){
                        
                    }
                }}}
        
        
  
        
        bfs(sl,sr,sc);
        

        
        if(ans==INF)
            cout<<"Trapped!"<<endl;
        else
            cout <<"Escaped in "<< ans << " minute(s)."<<endl;
        
    }
    
    return 0;
    
    
    
}
