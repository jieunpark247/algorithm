//
//  2112.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 7. 20..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//  보호필름

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
#define max(a,b) (a > b ? a : b) 
int d,w,k;
int map[21][21];
int ans;
int tmp[21][21];


void init_tmp(){
    for(int i=0;i<d;i++)
            for(int j=0;j<w;j++)
                    tmp[i][j]=map[i][j];
} // tmp초기화


//k에부합하는지 확인하는 함수 부합=true 부합ㄴㄴ = false
bool check_K(){
    int checked[w]; // w길이중 연속되는 숫자가 큰값의 수를 넣는 배열
    for(int j=0;j<w;j++) checked[j]=0; //초기화
    int check_; // 이값을 각각 배열에 넣어줌

        for(int j=0;j<w;j++){
             for(int i=0;i<d;i++){
                 int n= tmp[i][j]; // k개중 처음값
                 check_=0;
                 for(int kk=0;kk<d;kk++){ //k만큼의 길이중 처음값과 같으면 값을 +1 해준다.
                     if(i+kk<d && tmp[i+kk][j]==n)
                         check_++;
                     else
                         break;
            
                     
                 }
                 checked[j]=max(checked[j],check_); // 연속되는값중 최댓값을 배열에 넣어줌
             }
       }
    
   //  for(int j=0;j<w;j++){
   // cout<<checked[j]<<" ";
  //   }
    
    for(int j=0;j<w;j++){
        if(checked[j] < k){ //하나라도 k개만큼 연속되지 않으면 false
    //        cout<< "J" << j << " ";
            return false;
            break;
        }
          }
  
    return true;

}




//약품을 넣는함수
void pushST(int kTime){
    
    //cout<<check_K();
    if(check_K()){
        return;
    } // 모든 가로의 길이가 k만큼 연속된 수일경우 리턴
    
    if(kTime>=k){
        ans=k;
        return;
    } //k보다 클경우 답은 k 리턴

    
    //조합 돌리기
    vector<int> ind;
    
    int kk = kTime;
    
    for (int i = 0; i < kk; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < d - kk; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end()); //오름차순 정렬
    
    do { //순열 돌리기
        
        init_tmp(); //tmp 를 map 값으로 초기화
        
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 1) {
                //a : 1 , b : 0 , a(x)b(x) : 2
                for(int j=0;j<w;j++)
                    tmp[i][j]=1;
            }
        }
        
        if(check_K()){
            ans=kTime;
            return;
        }
        
        init_tmp();
        //========== a일 경우
        
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 1) {
                //a : 1 , b : 0 , a(x)b(x) : 2
                for(int j=0;j<w;j++)
                    tmp[i][j]=0;
            }
        }
        
        if(check_K()){
            ans=kTime;
            return;
        }
        
        //========== b로 할경우

        
    }
    
    while (next_permutation(ind.begin(), ind.end())); 

    
    if(!check_K())
        pushST(kTime+1); // ktime을 조합으로 다돌렸을때도 조건에 부합하지않는다면 ktime의갯수를 1늘려준다.
    
 
    
    
    
}


int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        
        cin>>d>>w>>k;
        
        for(int i=0;i<d;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
    
        init_tmp();
        
        ans=0;
        pushST(1); //ktime은 1부터 시작
        
        cout<<"#"<<t<<" "<< ans<<endl;
    }
}
