//
//  1753.cpp
//  Project
// 최단경로


#include <iostream>
#include<queue>
#include <vector>

using namespace std;
#define MAX 20001
#define INF 987654321

int V,E,K;
int u,w,v;
 int start;
vector < pair < int,int > > adj[MAX];

vector<int> dijstra(int src){


    vector <int> dist(V,INF); //start를 기준으로 거리
    dist[src]=0; //자기 자신한테 가는 비용 0
    priority_queue< pair < int,int > > pq;
    pq.push(make_pair(0, src)); //초기 비용과 시작점
    
    while(!pq.empty()){
        int cost= -pq.top().first;//거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내지게 하였으므로 부호를 바꿔준다
        int here= pq.top().second;
        pq.pop();
        
         //최소거리를 원하므로
        if(dist[here]<cost) continue;
        
        //there 다 확인
        for(int i =0;i<adj[here].size();i++){
            int there = adj[here][i].first;
            int nextDist = cost+ adj[here][i].second;
           
            //최소 경로 발견시 업데이트
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                     //거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내지도록하기 위해
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}



int main(){
    cin>>V>>E;
    cin>>start;
   
    V++;//정점번호 1부터 시작
    for (int i = 0; i < E; i++){
       
  
        cin>>u>>v>>w;
        
        adj[u].push_back(make_pair(v, w));
        
        
    }
    vector<int> result = dijstra(start);
    
 
    
    for (int i = 1; i < V; i++)
        
    {
        
        if (result[i] == INF)
            
            cout << "INF" << endl;
        
        else
            
            cout << result[i] << endl;
        
    }
    
    return 0;
}
