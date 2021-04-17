//
//  2805.cpp
//  Project
// 농작물 수확하기
#include <iostream>
#include<stdio.h>

using namespace std;
int ans;
int n;
int map[50][50],checked[50][50];
int middle;

void checkDiamond(int m, int c){ //마름모 형태로 checked ==1 로 바꿔주기

if(middle+m == n)
    return;
    
    
    for(int i =0+c; i<n-c ;i++){
        checked[i][middle+m]=1;
        checked[i][middle-m]=1;
        
    }
    
    checkDiamond(m+1,c+1);
    
    
    
}



int main(){
    int testcase;
    cin >>testcase;
    for(int t=1;t<=testcase;t++){
        
        ans=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                map[i][j]=0;
                checked[i][j]=0;
            }
        }
        //초기화
        
        cin>>n;

        for(int i =0;i<n;i++)
            for(int j =0;j<n;j++)
               scanf("%1d",&map[i][j]);
        //입력
        
        middle = n/2; //중간값
        checkDiamond(0,0);

        

        for(int i =0;i<n;i++)
            for(int j =0;j<n;j++)
                if(checked[i][j]==1)
                    ans=ans+map[i][j];
        //checked 가 1인 값을 찾아서 가치 더해주기
        
        
        cout<<"#" << t << " "<<ans<<endl;
        
    }
    
}
