//
//  1992.cpp
//  Project
// 쿼드트리

#include <iostream>
using namespace std;
int n;
int map[65][65];

void divideQ(int x, int y,int size){
    if(size==0){
         cout<<map[y][x];
        return;
    }
    int fixN = map[y][x];
    bool flag= true;
    for(int i=y;i<y+size;i++)
        for(int j =x ;j<x+size;j++)
            if(map[i][j] != fixN){
                flag = false;
            }
    
        if(flag){
            cout<<fixN;
        }
     
        else{
            cout<<"(";
            divideQ(x, y, size/2);
            divideQ(x+size/2, y, size/2);
            divideQ(x, y+size/2, size/2);
            divideQ(x+size/2, y+size/2, size/2);
            cout<<")";
      
            }
}

int main(){
    
    cin>>n;
    for(int i =0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&map[i][j]);
      
    
    divideQ(0,0,n);
    
    
}
