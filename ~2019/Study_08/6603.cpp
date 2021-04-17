//
//  6603.cpp
//  Project
// 로또

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector <int> vnum;
int K,S;
int main(){
    while(true){
        vnum.clear();
     
        cin>>K;
        if(K==0) break;
        
        for(int i =0;i<K;i++){
            cin>>S;
            vnum.push_back(S);
        }
     
        
        vector<int> ind;
        
        int k = 6;
        
        for (int i = 0; i < k; i++) {
            ind.push_back(1);
        }
        for (int i = 0; i < vnum.size() - k; i++) {
            ind.push_back(0);
        }
        sort(ind.begin(), ind.end(),greater<int>());
        
        do { //순열 돌리기
          
            for (int i = 0; i < ind.size(); i++) {
                if (ind[i] == 1) {
                    cout<<vnum[i]<<" ";
                    
                }
            }
            cout<<'\n';;
            
        }
        
        while (next_permutation(ind.begin(), ind.end(),greater<int>()));

           cout<<'\n';
        
        
    }
}
