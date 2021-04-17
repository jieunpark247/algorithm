//
//  kakao_B.cpp
//  Project
//

#include <iostream>
#include<vector>
#include <math.h>

using namespace std;

int n,k;
long dollN[502];
long double m,m2;
long double m3;
long double ans, res;
int temp;
vector <long> v;

void solve(int tmp,int kk){

    
    for(int i =tmp;i<kk+tmp;i++){
        m = m+dollN[i];
    }
    
    m=m/kk; // 산술평균
    
    
    for(int i =tmp;i<kk+tmp;i++){
        m2=m2+(dollN[i]-m)*(dollN[i]-m);
    }
    
    m3= m2/kk;//분산
    
   res= sqrt(m3);
    
    if(ans>res)
        ans=res;
    
}


void permu(int kk){
     m=0; m2=0; m3=0;
    if(temp+kk>n)
        return;
    
    int cnt=0;
    for(int i=temp;i<n;i++){
        if(cnt==kk)
            break;
        
        v.push_back(dollN[i]);
  
          cnt++;
        
            }
    
    solve(temp,kk);
    
    
    
    
    v.clear();
    temp++;
    permu(kk);
    
}



int main(){
    
    cin>>n>>k;
    m=0; m2=0; m3=0; ans=987654321;
    
    for(int i =0;i<n;i++){
        cin>>dollN[i];
    }

    
    for(int i=k;i<=n;i++){
    temp=0;
    permu(i);
    }
        cout.precision(10);
    cout<<fixed<<ans<<endl;
    
}
