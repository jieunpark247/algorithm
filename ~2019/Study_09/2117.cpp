//
//  2117.cpp
//  Project
//
// 홈방범
#include <iostream>
#define max(a,b) (a>b?a:b)

using namespace std;

int N,M;
int map[21][21];
int price[23];
int ans;
int countall;
//범위안에 있나?
bool isRange(int x, int y){return (x>=0&&x<N)&&(y>=0&&y<N);}

void solve(int x, int y, int k){
    int cnt=0;
    int nexty;
    int endp;
    
    for(int i=0;i<=k-1;i++){
        int upNextx=x-k+i;
        int downNextx=x+k-i;
        
        endp=i*2-1;
        nexty=y-endp/2;
        for(int j =0; j<endp;j++){
            if(isRange(upNextx, nexty+j)&&map[upNextx][nexty+j]==1)
                cnt++;
            if(isRange(downNextx, nexty+j)&&map[downNextx][nexty+j]==1)
                 cnt++;
                    
        }
    }
    endp=k*2-1;
    nexty=y-endp/2;
    for(int i =0; i<endp;i++)
    if(isRange(x, nexty+i)&& map[x][nexty+i]==1)
        cnt++;
   
    if(M*cnt-price[k]>=0){
        countall=cnt;
      //  cout<<countall;
    }
    
    else{
        countall=0;
    }
    
}
int main(){
    int testcase;
    cin>>testcase;
    price[1]=1;
    for(int i=1;i<21;i++){
        price[i+1]=(price[i+1]==0)? price[i] + 4*i : price[i+1];
        
    }
    for(int t=1;t<=testcase;t++){
        cin>>N>>M;
        
 
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                map[i][j]=0;
        ans=0;
        //초기화
    
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>map[i][j];
            }
            
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k =1;k<=N+1;k++){ //k는 map전체를 감쌀수 있을 때 까지 ==그럼 무조건 최대
                    solve(i, j, k);
                    ans=max(ans,countall);
                }
            }
        }
         
        
        cout<<"#"<<t<<" "<<ans<<endl;
        
    }
   
}
