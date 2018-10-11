//
//  14889.cpp
//  Project
// 스타트와 링크
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321;
int n;
int map[101][101];
int ans;
vector <int> teamstart;
vector <int> teamlink;
vector<int> v;
vector<int> two;
int teams,teaml;

int sumteam(vector<int> team){
    int sum = 0;
    vector<int> ind;
    int k = 2;
    
    for (int i = 0; i <k; i++)
        ind.push_back(1);
    
    for (int i = 0; i < team.size()-k; i++)
         ind.push_back(0);
        
    sort(ind.begin(), ind.end());
    
    do {
        two.clear();
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 1) {
                two.push_back(team[i]);
                
            }
        }
        
        sum = sum+map[two[0]][two[1]]+map[two[1]][two[0]];
        
    } while (next_permutation(ind.begin(), ind.end()));
    
    return sum;
}

void solve(int num){
    
    vector <int> ind;
    int k = num;
    
    for(int i=0;i<k;i++)
        ind.push_back(1);
    for(int i=0;i<v.size()-k;i++)
        ind.push_back(0);
    
    sort(ind.begin(),ind.end());
    do{
        teamstart.clear();
        teamlink.clear();
        for(int i=0;i<ind.size();i++){
            if(ind[i]==1){
                teamstart.push_back(v[i]);
            }
            if(ind[i]==0){
                teamlink.push_back(v[i]);
            }
        }

        teams=0;
        teaml=0;
        teams=sumteam(teamstart);
        teaml=sumteam(teamlink);

        ans=min(ans,abs(teams-teaml));
        
    } while (next_permutation(ind.begin(), ind.end()));
}

int main(){
    cin>>n;
    for(int i =0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
            
       
    for(int i =0;i<n;i++)
        v.push_back(i);
  
    ans = INF;
    solve(n/2);

    cout<<ans<<endl;
}
