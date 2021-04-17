//
//  N1.cpp
//  Project
//
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
int visited[5001];
vector<int> people;
vector<int> tshirts;

int solution(vector<int> people, vector<int> tshirts) {
    for(int i=0;i<people.size();i++){
        for(int j=0;j<tshirts.size();j++){
            if(people[i]==tshirts[j])
                visited[people[i]]=1;
    }
    }
int answer = 0;
    
    for(int i=0;i<5001;i++)
       if( visited[i]==1)
           answer=answer+1;

    return answer;
    
    
}

int main(){
    
     int p; int t;
    
    for(int i=0;i<5001;i++)
        visited[i]=0;
    
    do {
        scanf("%d", &p);
        people.push_back(p);
        // value값을 parameter로하는 함수호출부분
    } while (getc(stdin) == ' ');
    
    do {
        scanf("%d", &t);
        tshirts.push_back(t);
        // value값을 parameter로하는 함수호출부분
    } while (getc(stdin) == ' ');
    
    
//    for(int i =0;i<people.size();i++)
//        cout<< people[i]<<" ";
//
    
    cout<<solution(people,  tshirts)<<endl;
    
    
}
