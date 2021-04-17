//
// 14620.cpp
// Project
// 꽃길

#include <iostream>
#include<vector>
#include <string.h>
#define INF 987654321
#define min(a,b) (a<b ? a:b)
using namespace std;
int ans;
int n;
int map[11][11];
int checked[11][11];

int result(){ // 최솟값 출력 
    int cnt =0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(checked[i][j]==1)
                cnt= cnt + map[i][j];
    ans = min(cnt,ans);
    return ans;
}

int check(int x , int y){
    if(x-1>=0 && y-1>=0 &&x+1<n&&y+1<n){
        if(checked[x][y]==0&&checked[x+1][y]==0 &&checked[x][y+1]==0&&checked[x-1][y]==0&&checked[x][y-1]==0){ // 5평모두에 꽃이 없다면
            return 0;
        }
    }
            return 1;
}

void solve(int x, int y,int cnt){
  
    if(cnt==3) {
        result();
        return;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check(i,j)==0){ // 5평모두 꽃이 없다면
                checked[i][j]= checked[i+1][j]=checked[i][j+1]=checked[i-1][j]=checked[i][j-1]=1; // 5평모두 1표시해줌
                
                solve(i,j,cnt+1); //꽃한개 늘려줌
                
                checked[i][j]= checked[i+1][j]=checked[i][j+1]=checked[i-1][j]=checked[i][j-1]=0;
                
            }
        }
    }
  
}

int main(){

        cin>>n;
        memset(checked, 0, sizeof(checked));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>map[i][j];
        
        ans=INF;
        solve(0,0,0);
        cout<<ans<<endl;
    
}
