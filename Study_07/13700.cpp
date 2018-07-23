//
//  13700.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 7. 23..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//  완전범죄

#include <iostream>
#include <queue>
using namespace std;
int n,s,d,f,b,k;
int policeLoction;
int N[100001];
int visited[100001];
int cnt[100001];
queue <int> q;
void bfs(int newN){
    q.push(newN);
    
    while(!q.empty()){
        newN=q.front();
        q.pop();
       
        int newb= newN-b; // b만큼 뒤로감
        int newf= newN+f;  //f만큼 앞으로감
        if(newb>0){ // 뒤로간곳이 0보다크면
            if(N[newb]!=1 && visited[newb]==0){
                visited[newb]=1; //방문표시
                q.push(newb); //간 값을 집어넣어라
                cnt[newb]=cnt[newN]+1; // now 위치에 cnt ++ 해줘라
            }
        }
            
            if(newf<=n){ //앞으로 간 곳이 n보다 작거나 같다면
                 if(N[newf]!=1 && visited[newf]==0){
                visited[newf]=1;
                q.push(newf);
                cnt[newf]=cnt[newN]+1;
                 }
            }
        
    }

}
int main(){

    cin>>n>>s>>d>>f>>b>>k;
  
    for(int kk=1;kk<=k;kk++){
        cin>>policeLoction;
        N[policeLoction]=1; //경찰의 위치인곳에 1을 저장
        
    }
  
    /*  for(int i=1;i<=n;i++){
          cout<<N[i]<< " ";
      }
    */
    cnt[d]=-1;
    bfs(s);
   
    if(cnt[d]==-1) //d의 위치가 -1이면?  cnt를 각 위치에 ++해주었기때문에 마지막 d위치에는 최종cnt값이 나온다.
        cout<<"BUG FOUND";
    else
        cout<<cnt[d]<<endl;
    
}
