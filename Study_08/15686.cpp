//
//  boj_15686.cpp
//  Project
// 치킨배달

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define max(a,b) (a < b ? a : b)
#define min(a,b) (a < b ? a : b)
#define MAX 987654321;
int N,M;
int map[51][51], map2[51][51];
vector < pair < int, int > > chicken;
vector < pair < int, int > > person;

vector < pair < int, int > > distanceChi[14];
vector<int>choose;
int d;
int minN;
int sumD;//모든 치-집 거리 구하여 더한값들
int ans;
void chooseOne(){ //어떤 치킨 ? 선택
    vector<int> ind;
    
    int k = M;
    
    for (int i = 0; i < k; i++) {
        ind.push_back(1);
    }
    for (int i = 0; i < chicken.size() - k; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end()); //오름차순 정렬
    
    do { //순열 돌리기
          choose.clear();
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 1) {
                choose.push_back(i+1);
            }
        }
        
        sumD=0;
        for(int p=0;p<person.size();p++){
            minN=MAX;
            for(int ch=0;ch<choose.size();ch++){
                minN= min(distanceChi[choose[ch]][p].second,minN);
                
            }
            sumD=minN+sumD;
        }
        
     
        ans= min(sumD,ans);
     
      
    } 
    
    while (next_permutation(ind.begin(), ind.end()));
}
int main(){
    
     cin>>N>>M;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>map[i][j];
                map2[i][j]=map[i][j];
                if(map[i][j]==2)
                    chicken.push_back(make_pair(i, j));
                if(map[i][j]==1)
                    person.push_back(make_pair(i, j));
            }
        }
    
        for(int m=0;m<chicken.size();m++){
            for(int p=0;p<person.size();p++){
                d= abs(chicken[m].first-person[p].first)+abs(chicken[m].second-person[p].second);
                distanceChi[m+1].push_back(make_pair(p+1, d));
            }
        }

        ans=MAX;
        chooseOne();
        
        cout<<ans<<endl;
    
        
    }
    

