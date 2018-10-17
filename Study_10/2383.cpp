//
//  2383.cpp
//  Project
//
//  Created by Ji-Eun Park on 2018. 10. 17..
//  Copyright © 2018년 Ji-Eun Park. All rights reserved.
// 점심식사시간 (again)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <memory.h>
using namespace std;
int n;
int map[11][11];
vector<int> s1;
vector<int> s2;

vector<pair<int, int>> person;
vector<pair<pair<int, int>, int>> stair;
vector<pair<int, int>> dist;

int sumTime1,sumTime2,sumTime;
int ans;
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=0;
        }
    }

    person.clear(); dist.clear(); stair.clear();
}

void solve(){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
    
    if(s1.size()<=3){
        for(int i=0;i<s1.size();i++){
            s1[i] = s1[i] + stair[0].second+1;
            
            sumTime1 = max(s1[i],sumTime1);
        }
        
    }else{
        for(int i=0;i<s1.size();i++){
            if(i<3){
                    s1[i] = s1[i] + stair[0].second+1;
            }else{
                
                s1[i] = max(s1[i-3],s1[i]+1) + stair[0].second;
            }
        
        
         sumTime1 = max(s1[i],sumTime1);
        }
    }
    
   
    if(s2.size()<=3){
        for(int i=0;i<s2.size();i++){
            s2[i] = s2[i] + stair[1].second+1;
            sumTime2 = max(s2[i],sumTime2);
        }
    }else{
        for(int i=0;i<s2.size();i++){
            if(i<3){
                    s2[i] = s2[i] + stair[1].second+1;
                    
            }else{
                
                s2[i] = max(s2[i-3] ,s2[i]+1)+ stair[1].second;
            }

             sumTime2 = max(s2[i],sumTime2);
        }
      
    }

    
    sumTime =max(sumTime1,sumTime2);

}
void choose(int k){
    vector<int> ind;
    
    //int k = person.size()/2;
    
    for (int i = 0; i < k; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < person.size() - k; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end()); //오름차순 정렬
    
    do { //순열 돌리기
        s1.clear(); s2.clear(); sumTime1=0;sumTime2=0;sumTime=0;
        for (int i = 0; i < ind.size(); i++){
            if(ind[i] == 1)
                s1.push_back(dist[i].first); //1으로 갈 값 넣어주기
            else if(ind[i] == 0)
                s2.push_back(dist[i].second);//2로 갈 값 넣어주기
            
        }
      
         solve();

        ans = min(sumTime,ans);
    }
    
    while (next_permutation(ind.begin(), ind.end()));
    

}

int main(){
    int testcase;
    cin>>testcase;
    for(int t=1;t<=testcase;t++){
        init();
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
                if(map[i][j]==1){
                    person.push_back(make_pair(i, j));
                }else if(map[i][j]>1){
                    stair.push_back(make_pair(make_pair(i, j),map[i][j]));
                }
            }
        }
        for(int i=0;i<person.size();i++){
            int a= abs(person[i].first - stair[0].first.first)+abs(person[i].second-stair[0].first.second);
            int b= abs(person[i].first - stair[1].first.first)+abs(person[i].second-stair[1].first.second);
            dist.push_back(make_pair(a,b));
        } //사람, 계단 거리 넣어줌
        ans =987654321;
        sumTime1=0;sumTime2=0;sumTime=0;
        for(int i=0;i<=person.size();i++){
            choose(i);
        }
      
        cout<<"#"<<t<<" "<<ans<<endl;
    }
    
}
