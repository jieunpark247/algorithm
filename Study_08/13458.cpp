//
//  13458.cpp
//  Project
//
//  Created by PARKHASIK on 2018. 8. 7..
//  Copyright © 2018년 PARKJIEUN. All rights reserved.
//

#include <iostream>

using namespace std;
long a[1000002];
long b,c;
long n;
long res;
long cnt;
long d;


int main(){
    res=0;
    cin>>n;
    for(long i =0; i<n;i++){
        cin>>a[i];
        
    }
    
    cin>>b>>c;
    
    for(long i =0; i<n;i++){
        if(a[i]>0){
            a[i]=a[i]-b;
            res++;
        }
        
    }
    
    for(long i =0; i<n;i++){
        if(a[i]>0){
            d=a[i]/c;
            if(a[i]%c==0)
                res=res+d;
            else
                res=res+d+1;
        }
        
    }
    
  
    cout<<res<<endl;;
    
}
