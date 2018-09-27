//
//  5656.cpp
//  Project
// 벽돌꺠기 swea
#include<iostream>
#include<vector>
#include <string.h>
using namespace std;

int N,W,H;
int map[20][20];
int map2[20][20];
int ans;
int visited[20][20];
int dx[4] = {1,-1,0 ,0};
int dy[4] = {0,0, 1,-1};
int x;int y;int block;

void pushblock(){

    vector <int> v;
    int temp[20][20];
    for(int i=0;i<20;i++)
        for(int j =0;j<20;j++)
            temp[i][j]=0;
         for(int j=0;j<W;j++){
             for(int i =H-1;i>=0;i--){
                 if(map[i][j]!=0)
                     v.push_back(map[i][j]);
             }
             
        int a=H-1;
        for(int vv=0;vv<v.size();vv++){
            temp[a][j]=v[vv];
            a--;
            }
         v.clear();
         }
    
    for(int i=0;i<H;i++)
        for(int j =0;j<W;j++)
            map[i][j]=temp[i][j];
}

void findblock(int wi){
    for(int j =0;j<H;j++){
        if(map[j][wi]!=0){
            block = map[j][wi];
            map[j][wi]=0;
            x = j;
            y = wi;
            break;
        }
    }
}

void removeblock(int x, int y){
    
            for(int i =1;i<block;i++){
                for(int j =0;j<4;j++){
                    int nx= x + (dx[j]*i);
                    int ny= y + (dy[j]*i);
                    if(map[nx][ny]==1&&nx>=0&&ny>=0&&nx<H&&ny<W){
                        map[nx][ny]=0;
                    }else if(map[nx][ny] > 1&&nx>=0&&ny>=0&&nx<H&&ny<W){
                        block = map[nx][ny];
                        map[nx][ny] = 0;
                        removeblock(nx, ny);
                    }
                }
            }
    }


int block_check(){
    int cnt =0;
    for(int i=0;i<H;i++){
        for(int j =0;j<W;j++){
         if(map[i][j]>0)
             cnt++;
            }
        }
//
//                cout<<'\n';
//        for(int i=0;i<H;i++){cout<<'\n';
//            for(int j =0;j<W;j++){
//                cout<<map[i][j];
//            }}cout<<'\n';
    
    if(ans>cnt) ans = cnt;
    return ans;
}

void solve(){

    if(N==1){
          for(int j =0;j<W;j++){
              
                for(int a=0;a<H;a++)
                    for(int b =0;b<W;b++)
                        map[a][b]=map2[a][b]; // 전 맵으로 되돌아가기
              
              findblock(j);
              removeblock(x,y);
              pushblock();
              block_check();
             
          }
        
    }else if(N==2){
        
        for(int i =0;i<W;i++){
            for(int j =0;j<W;j++){
            
                for(int a=0;a<H;a++)
                    for(int b =0;b<W;b++)
                        map[a][b]=map2[a][b]; // 전 맵으로 되돌아가기
                
                findblock(i);
                removeblock(x,y);
                pushblock();
                findblock(j);
                removeblock(x,y);
                pushblock();
                block_check();
            
        }
        }
        
        
        
    }else if(N==3){
        
        for(int w =0;w<W;w++){
            for(int  i=0;i<W;i++){
                for(int j =0;j<W;j++){
                    
                    for(int a=0;a<H;a++)
                        for(int b =0;b<W;b++)
                            map[a][b]=map2[a][b]; // 전 맵으로 되돌아가기
                    
                    findblock(w);
                    removeblock(x,y);
                    pushblock();
                     findblock(i);
                    removeblock(x,y);
                    pushblock();
                     findblock(j);
                    removeblock(x,y);
                    pushblock();
                    block_check();
            
                }
            }
        }
    }else if(N==4){
        for(int ww =0;ww<W;ww++){
          
            for(int w =0;w<W;w++){
                
            
                for(int i =0;i<W;i++){
                  
                    for(int j =0;j<W;j++){
                        
                        for(int a=0;a<H;a++)
                            for(int b =0;b<W;b++)
                                map[a][b]=map2[a][b]; // 전 맵으로 되돌아가기
                        
                        findblock(ww);
                        removeblock(x,y);
                        pushblock();
                         findblock(w);
                        removeblock(x,y);
                        pushblock();
                         findblock(i);
                        removeblock(x,y);
                        pushblock();
                         findblock(j);
                        removeblock(x,y);
                        pushblock();
                        block_check();
                        
            
                    }
                }
            }
        }
    }
    
    if(ans == 0)
        return;
                 
}
int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        ans=987654321;
        cin>>N>>W>>H;
        for(int i=0;i<H;i++)
            for(int j =0;j<W;j++)
                cin>>map2[i][j];
        
            solve();
            cout<<"#"<<t<<" "<<ans<<endl;
        
    }
}
