//
//  2477.cpp
//  Project
//차량정비소
#include <iostream>
#include <queue>
using namespace std;
#define min(a,b) (a < b ? a : b)
int n,m,K;
int a[21][2],aa[21][2];
int b[21][2],bb[21][2];
int tt[21][2];
int A,B;
int ans,res;
int minValue, mintt;;
int checkAB[21][2];
queue <int> wa;
queue <int> wb;
void solve(int time){
    
    int cnt=0; int cntt=0;
    
    for(int i=1;i<=n;i++){
        if(a[i][1]!=0)
            cnt++;
       // cout<<"A " <<a[i][0]<<" ";
      //  cout<<"AA " <<a[i][1]<<" ";
        
        
        if(a[i][0]>=0)
            cntt++;
    }
    for(int j=1;j<=m;j++){
        if(b[j][1]!=0)
            cnt++;
      //  cout<<"B "<< b[j][0]<<" ";
        
        // cout<<"BB "<< b[j][1]<<" ";
        
        
        if(b[j][0]>=0)
            cntt++;
    }
   // cout<<'\n';
    if(cnt==0||cntt==0)
        return;
    
    
    
    //다끝나면 리턴
    
    for(int k=1;k<=K;k++){
        if(tt[k][0]>=0){
            tt[k][0]=tt[k][0]-1;
            if(tt[k][0]==0 && tt[k][1]==0){
                wa.push(k);
                tt[k][1]=1;
        }
        }
    }
    for(int i=1;i<=n;i++){

        if(a[i][1]!=0){
            a[i][0]=a[i][0]-1;
            if(a[i][0]==0){
                if(i==A)
                    checkAB[a[i][1]][0]=1;
                wb.push(a[i][1]);
                a[i][1]=0;
                a[i][0]=aa[i][0];
                
            }
        }
        
        if(a[i][1]==0 && !wa.empty()){
            cout<<"   queue.empty:";
            cout<<wa.empty();
            cout<<"   queue.size: ";
            cout<<wa.size();
          // if(!wa.empty()){
               cout<<"   queue.front : ";
               a[i][1]=wa.front();
               cout<<wa.front()<<'\n';;
               wa.pop();
      //  }
        }
    }
    
    for(int j=1;j<=m;j++){
        
        if(b[j][1]!=0){
            b[j][0]=b[j][0]-1;
            if(b[j][0]==0){
                if(j==B)
                    checkAB[b[j][1]][1]=1; //B가 맞으면 1
                b[j][1]=0;
                b[j][0]=bb[j][0];
            }
        }
        
        if(b[j][1]==0){
            if(!wb.empty()){
                b[j][1]=wb.front();
                wb.pop();
            }
        }
    }
    
    solve(time+1);
}

int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        cin>>n>>m>>K>>A>>B;
        ans=-1;res=0;
        for(int i=0;i<21;i++)
            for(int j=0;j<2;j++)
                checkAB[i][j]=0;
        for(int i=1;i<=n;i++){
            cin>>aa[i][0];
            a[i][0]=aa[i][0];
        }
        
        for(int j=1;j<=m;j++){
            cin>>bb[j][0];
            b[j][0]=bb[j][0];
        }
        
        for(int k=1;k<=K;k++){
            cin>>tt[k][0];
            tt[k][1]=0;
        }
        int ct=0; mintt = 987654321;
        for(int k=1;k<=K;k++){
            if(tt[k][0]==0){
                ct++;
            }
            mintt=min(tt[k][0], mintt);
        }
        if(ct==0)
            for(int k=1;k<=K;k++)
                tt[k][0]=tt[k][0]-mintt; // 고객 시간이 0이 없다면 고객들중 최솟값을 찾아 빼줘서 0으로 만들어준다
        
        for(int k=1;k<=K;k++){
            if(tt[k][0]<=0){
                wa.push(k);
                tt[k][1]=1;
            }
        }
        
        
        for(int i=1;i<=n;i++){
            if (!wa.empty()){
                a[i][1] = wa.front();
                wa.pop();
            }
        }//맨 처음 t가 0 인값들을 넣어줌
        
        solve(1);
        
        for(int i =0;i<21;i++)
            if(checkAB[i][0]==1 && checkAB[i][1]==1)
                res=i+res;
        
        if(res!=0)
            ans=res;
        cout<<"#"<<t<<" "<<ans<<endl;
    }
}
