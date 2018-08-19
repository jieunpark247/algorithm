//
//  15684.cpp
//  Project
//사다리 조작
#include <iostream>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;
int M, N, H,a,b;
int map[31][11],map2[31][11],map3[31][11],visited[31][11],visited2[31][11];
int ans;
int finishLadder[12];
int dx[4] = { -1,1,0, 0};
int dy[4] = { 0, 0,1,-1};
int nx, ny,nn;
int cnt;
int tt;
void goLadder(int x,int y) { //사다리를 타고 갔을 때 결과를 출력
    if (x > H) {
        finishLadder[nn] = y;
        return;
    }
    
    
    if (map3[x][y] == 1) {
        nx = dx[1] + x;
        ny = dy[1] + y;
        
    }else if (map3[x][y] == 2) {
        nx = dx[2] + x;
        ny = dy[2] + y;
        if (nx <= H && ny <= N && nx > 0 && ny > 0)
            map3[nx][ny] = 1;
        
        
    }else if (map3[x][y] == 3) {
        nx = dx[3] + x;
        ny = dy[3] + y;
        if (nx <= H && ny <= N && nx > 0 && ny > 0)
            map3[nx][ny] = 1;
    }
    
    
    goLadder(nx,ny);
}

//h = x j=y
void plusLadder(int times,int xx, int yy) { //사다리를 놓는 경우의 수 출력
    cout<<"T"<<tt;
    if (times > tt ){
        for (int j = 1; j <= N; j++){
            memcpy(map3, map2, sizeof(map2));
            nn = j;
            goLadder(1, j);
        }
//
      
          if(tt==3)
          {
//        for (int h = 1; h <= H; h++){
//            cout<<'\n';
//            for (int j = 1; j <= N; j++){
//                cout<<map2[h][j];
//            }} cout<<'\n';
//        
//        for (int h = 1; h <= H; h++){
//            cout<<'\n';
//            for (int j = 1; j <= N; j++){
//                cout<<visited[h][j];
//            }} cout<<'\n';
        
//            for (int h = 1; h <= H; h++){
//                cout<<'\n';
//                for (int j = 1; j <= N; j++){
//                    cout<<visited2[h][j];
//                }} cout<<'\n';
//            
        
          }
        
        
        
        //fin[i] == i 가 맞는지 세서 맞으면 리턴
//        for (int f = 1; f <= N; f++){
//            cout<<finishLadder[f]<<" ";
//        }cout<<'\n';
        int cn=0;
        for (int f = 1; f <= N; f++)
            if(finishLadder[f]==f)
                cn=cn+1;
        
        if(cn==N){
//            for (int h = 1; h <= H; h++){
//                cout<<'\n';
//                for (int j = 1; j <= N; j++){
//                    cout<<map2[h][j];
//                }} cout<<'\n';
            
                  //  cout<<times;
            ans=tt;
        }
        
  
        
        return;
    }
    
    
    
    
    visited[xx][yy]=1;
    map2[xx][yy]=2;
    map2[xx][yy+1]=3;
    
    
    if(tt==3)
    {
                for (int h = 1; h <= H; h++){
                    cout<<'\n';
                    for (int j = 1; j <= N; j++){
                        cout<<map2[h][j];
                    }} cout<<'\n';
        
                for (int h = 1; h <= H; h++){
                    cout<<'\n';
                    for (int j = 1; j <= N; j++){
                        cout<<visited[h][j];
                    }} cout<<'\n';
        
        for (int h = 1; h <= H; h++){
            cout<<'\n';
            for (int j = 1; j <= N; j++){
                cout<<visited2[h][j];
            }} cout<<'\n';
        
        
    }
    
    
    for (int h = 1; h <= H; h++){
        for (int j = 1; j <= N; j++){
            if(j+1<=N && map2[h][j]==1 && map2[h][j+1]==1&&visited[h][j]==0 &&times>0 &&visited2[h][j]==0){
 
                
                plusLadder(times+1,h,j);
                
                times=times-1;
                map2[xx][yy]=1;
                map2[xx][yy+1]=1;
                
             

                
            }}}
    

    
}

int main() {
    ans = -1;

    cin >> N >> M>> H;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= N; j++)
            map[i][j]=1;
    
    for (int m = 0; m < M; m++) {
        cin >> a >> b;
        map[a][b] = 2; //go to right
        map[a][b + 1] = 3; // go to left
        visited[a][b]=1;
        visited[a][b+1]=1;
        
    }
    
  
  
   // plusLadder(0,1,1);
    
    for(int t=0;t<=3;t++){
        tt=t;
        memset(visited2, 0, sizeof(visited2));
    for (int h = 1; h <= H; h++){
        for (int j = 1; j <= N; j++){
             memcpy(map2, map, sizeof(map));
            memset(visited, 0, sizeof(visited));

     
                if(j+1<=N && map2[h][j]==1 && map2[h][j+1]==1){
                  
                    plusLadder(1,h,j);
                }
            
               visited2[h][j]=1;
        }}
        
       if(ans>=0)
           break;
    }

    
    cout << ans << endl;
}
