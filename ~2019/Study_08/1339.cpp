//
//  1339.cpp
//  Project
// 단어수학
#include <iostream>
#include<vector>
#include <string>
#include <stdio.h>
#include<algorithm>
using namespace std;


int NN;
vector<int> num_(90);

void solve(string s)
{
    int multi = 1;
//    int size = s.size();
    reverse(s.begin(), s.end());
    while (true)
    {
     //   char tmp = s[0];
        num_[s[0] - 'A'] += multi;
       // cout<<s[0]<< s[0] - 'A' <<" ";
        multi*= 10;
        s = s.substr(1);
        
        if (s.size() == 0)
        {
            return;
        }
    }
}


int main(){
    
    cin>>NN;
   
    
    for(int n=0;n<NN;n++){
        string s;
        cin>>s;
        solve(s);
    }
    
    sort(num_.begin(), num_.end());
    
    int ans = 0;
    int k = 9;
    for (int i = num_.size() - 1; i >= 0; i--)
    {
        ans += k*num_[i];
        k--;
    }
    printf("%d\n", ans);
    
    return 0;
}
