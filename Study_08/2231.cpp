//
//  2231.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 8. 16..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
int vsum[1000001];
vector<int> dividenum;
int num_,r;
int n,m;
int ii,res;
void makeNum(int i){
    num_=i;
    
    if(i==0)
        return;
    

        r= num_%10;
    
        vsum[ii]=vsum[ii]+r;
        makeNum(num_/10);
    
    
}





int main(){
    cin>>n;
    res=0;
    for(int i=0;i<1000000;i++){
        vsum[i]=0;
      
    }
    
    for(int i=0;i<1000000;i++){
        vsum[i]=vsum[i]+i;
        ii=i;
        makeNum(i);
    }
    
    for(int i=1000000;i>=0;i--){
        if(n==vsum[i])
            res=i;
    }
    cout<<res<<endl;
}
