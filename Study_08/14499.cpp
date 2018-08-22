//
//  14499.cpp
//  Project
//
// 주사위 굴리기

#include <iostream>
#include<vector>
using namespace std;

int N,M,K,x,y;
int dir;
int map[21][21];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int mapV[7];
vector <int> dirAll;
int east[4]={5,2,6,1};int west[4]={6,2,5,1};
int south[4]= {3,6,4,5};int north[4]={6,3,5,4};
int nx,ny;

void copyNum(int i,int j){
    if(map[i][j]!=0){
        mapV[6]=map[i][j];
        map[i][j]=0;
    }else if(map[i][j]==0){
        map[i][j]=mapV[6];
    }
}


void moveDir(int num){
    switch(num){
        case 1:{ //동
            int tmp,temp;
            tmp=mapV[east[0]];
            for(int e=0;e<4;e++){
                int e1=(e+1)%4;
                temp=tmp;
                tmp=mapV[east[e1]];
                mapV[east[e1]]=temp;
            }
            
        }break;
        case 2:{ //서
            int tmp,temp;
            tmp=mapV[west[0]];
            for(int e=0;e<4;e++){
                int e1=(e+1)%4;
                temp=tmp;
                tmp=mapV[west[e1]];
                mapV[west[e1]]=temp;
            }
            
        }break;
        case 3:{ //북
            int tmp,temp;
            tmp=mapV[north[0]];
            for(int e=0;e<4;e++){
                int e1=(e+1)%4;
                temp=tmp;
                tmp=mapV[north[e1]];
                mapV[north[e1]]=temp;
            }
            
            
        }break;
        case 4:{ //남
            int tmp,temp;
            tmp=mapV[south[0]];
            for(int e=0;e<4;e++){
                int e1=(e+1)%4;
                temp=tmp;
                tmp=mapV[south[e1]];
                mapV[south[e1]]=temp;
            }
            
        }break;
    }
}

int main(){
    
    cin>>N>>M>>x>>y>>K;
    
    for(int n=0;n<N;n++)
        for(int m=0;m<M;m++)
            cin>>map[n][m];
    
    for(int k=0;k<K;k++){
        cin>>dir;
        dirAll.push_back(dir);
    }
    
    nx=x;ny=y;
    copyNum(nx,ny);
    
    for(int k=0;k<dirAll.size();k++){
        if(dirAll[k]==1){
            if(nx+dx[0]<N && nx+dx[0] >=0 &&ny+dy[0]<M&&ny+dy[0]>=0){
                moveDir(dirAll[k]);
                nx=nx+dx[0];
                ny=ny+dy[0];
                copyNum(nx,ny);
                cout<<mapV[5]<<'\n';
            }
        }else if(dirAll[k]==2){
            if(nx+dx[1]<N && nx+dx[1] >=0 &&ny+dy[1]<M&&ny+dy[1]>=0){
                moveDir(dirAll[k]);
                nx=nx+dx[1];
                ny=ny+dy[1];
                copyNum(nx,ny);
                cout<<mapV[5]<<'\n';
            }
        }else if(dirAll[k]==3){
            if(nx+dx[2]<N && nx+dx[2]>=0 &&ny+dy[2]<M&&ny+dy[2]>=0){
                moveDir(dirAll[k]);
                nx=nx+dx[2];
                ny=ny+dy[2];
                copyNum(nx,ny);
                cout<<mapV[5]<<'\n';
            }
        }else if(dirAll[k]==4){
            if(nx+dx[3]<N && nx+dx[3] >=0 &&ny+dy[3]<M&&ny+dy[3]>=0){
                moveDir(dirAll[k]);
                nx=nx+dx[3];
                ny=ny+dy[3];
                copyNum(nx,ny);
                cout<<mapV[5]<<'\n';
            }
        }
        
    }
    
    
}
