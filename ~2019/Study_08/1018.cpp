//
//  1018.cpp
//  Project
// 체스판 다시 칠하기

#include <iostream>
#include <vector>
using namespace std;
int cnt,count_;
int M,N;
char map[51][51];
vector <char> mapV;
char start;

void sliceChess(int startM,int startN,char start){
  
    for(int i =startM-7;i<=startM;i++)
        for(int j=startN-7;j<=startN;j++)
            mapV.push_back(map[i][j]);

    char tmp = start;
   
    for(int v=0;v<mapV.size();v++){
        if(tmp==mapV[v]){
            cnt++;
        }
        if(v%8 == 7){
            tmp=tmp;
        }else{
        if(tmp=='B')
            tmp='W';
        else
            tmp='B';
        }
            }

    if (cnt>count_)
        count_=cnt;
    
}


int main(){
    cin>>M>>N;
    for(int i =0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
   
    count_=0;
    
    for(int i =7;i<M;i++){
        for(int j=7;j<N;j++){
            mapV.clear();
            cnt=0;
            start = 'B';
            sliceChess(i,j,start);
            
            mapV.clear();
            cnt=0;
            start= 'W';
            sliceChess(i,j,start);
        }
    }
    
    cout<<64-count_<<endl;
}
