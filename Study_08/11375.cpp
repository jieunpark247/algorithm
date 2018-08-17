//
//  11375.cpp
//  Project
// 열혈강호


#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
#define MAX 1001

int N,M;
int matchWork[MAX];
int times,matchW;

vector < int > adj[MAX];



int visited[MAX];


bool dfs(int a)
{
    if (visited[a]==1) return false;
    
    visited[a] = 1;
    
    for (int b = 0; b < adj[a].size(); b++){
        int w=adj[a][b];
        if(matchWork[w]==0 || dfs(matchWork[w])){
            matchWork[w] = a;
            return true;
        }
    }
    return false;
    
}


int main()
{
    cin>>N>>M;
    
    for(int i=0;i<=MAX;i++){
        visited[i]=0;
        matchWork[i]=0;
    }
    
    for(int n=1;n<=N;n++){
        cin>>times;
        for(int t=1;t<=times;t++){
            cin>>matchW;
            adj[n].push_back(matchW);
        }
    }
    
    int size = 0;
    
    for (int start = 1; start <= N; start++){
        
        for(int i=0;i<=N;i++){
            visited[i]=0;
        }
        
        if (dfs(start)){
            size++;
        }}
        

    
    cout << size << endl;
    
    return 0;
}
