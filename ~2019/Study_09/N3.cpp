//
//  N3.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 9. 22..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//
#include <string.h>
#include <stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector < pair < int,int > > item;
vector<int> health;

int answer;
int visited[5001];
int possible[5001];
vector<vector<int>> node;



int dfs(int here) {
if (visited[here]) return 0;
    visited[here] = 1;
    for (int i = 0; i<node[here].size(); i++) {
        int there = node[here][i];
        if(there == 0 ){
            return 0;
        }
        else if (!possible[there] || dfs(possible[there])) {
            possible[there] = here;
         
            return 1;
        }
    }
    return 0;
}
void bmatch() {
   
    for (int i = 1; i < health.size(); i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
  
    }

}


vector<int> solution(vector<int> healthes, vector<vector<int>> items) {
    vector<int> answer;
 
    for(int i=0;i<5001;i++){
        visited[i]=0;
        possible[i]=0;
    }

    int h;
    health.push_back(0);
    do {
        scanf("%d", &h);
        health.push_back(h);
   
    } while (getc(stdin) == ' ');
    int ita ,itb;
       item.push_back(make_pair(0, 0));
    do {
        scanf("%d", &ita);
        scanf("%d", &itb);
        item.push_back(make_pair(ita, itb));
    
    } while (getc(stdin) == ' ');

 
   
    node.resize(item.size());
    for(int i =1;i<item.size();i++){
        for(int j =1;j<health.size();j++){
            if((health[j] - item[i].second )>= 100){
                     node[i].push_back(j);
               
                
            }
        }
    }

    bmatch();


    for(int i=0;i<5001;i++)
        if(possible[i]!=0)
            answer.push_back(possible[i]);
    if(answer.size()!=0){
        for(int i=0;i<answer.size();i++)
            cout<<answer[i]<<" ";
    }else{
        cout<<-1<<endl;
    }
    
    return answer;
}

int main(){
    vector<vector<int>> items;
    solution(health, items);
}
