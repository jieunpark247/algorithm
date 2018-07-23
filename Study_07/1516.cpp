//
//  1516.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 7. 23..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
// 게임개발

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int defaultTime[502];
int addTime[502];
int indegree[502];
int a,b,N;
vector <int> abN[502];
queue <int> in;
#define max(a,b) (a > b ? a:b)
int main(){
    cin>>N;
    for(int i =1;i<=N;i++){
        cin>>a;
        defaultTime[i]=a; //초기시간 값
        while(1){
            cin>>b;
            if(b==-1)
                break;
            abN[b].push_back(i); //몇번을 먼저 실행해야하는지 넣어줌
            indegree[i]++; //degree값을 ++
        }
            
    }
    
    for(int i=1;i<=N;i++){
        if(indegree[i]==0)
            in.push(i); //degree 값이 0이면 값을 큐에 넣어줌
    }
    while(!in.empty()){
        
        for(int j=0;j<in.size();j++){
            int now=in.front();
            in.pop();
            indegree[now]--;
            
            for(auto i:abN[now]){
           //     cout << i<<" / ";
                indegree[i]--;
                if(!indegree[i]) in.push(i);
            
            int time_=defaultTime[now]+addTime[now];
                addTime[i]=max(time_,addTime[i]);
            }
        }
        
        
        
    }
    
    for(int i =1;i<=N;i++){
        cout<<defaultTime[i]+addTime[i]<<endl;
    }
    return 0;
}
